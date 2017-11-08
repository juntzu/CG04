!   Slater-Condon Rules
!   Copyright (C) 2013 Anthony Scemama <scemama@irsamc.ups-tlse.fr>
!                      Emmanuel Giner <emmanuel_giner_jr@hotmail.fr>
!
!   This program is free software; you can redistribute it and/or modify
!   it under the terms of the GNU General Public License as published by
!   the Free Software Foundation; either version 2 of the License, or
!   (at your option) any later version.
!
!   This program is distributed in the hope that it will be useful,
!   but WITHOUT ANY WARRANTY; without even the implied warranty of
!   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
!   GNU General Public License for more details.
!
!   You should have received a copy of the GNU General Public License along
!   with this program; if not, write to the Free Software Foundation, Inc.,
!   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

subroutine compute_density_matrix(det,Ndet,coef,mo_num, &
               Nint,density_matrix)
 implicit none
 integer*8, intent(in)         :: det(Nint,2,Ndet)
 integer, intent(in)           :: Ndet, Nint, mo_num
 double precision, intent(in)  :: coef(Ndet)
 double precision, intent(out) :: density_matrix(mo_num,mo_num)

 integer :: i,j,k,l,ispin,ishift
 integer*8 :: buffer
 integer :: deg
 integer :: exc(0:2,2,2)
 double precision :: phase, c
 integer :: n_excitations

!k = determinant index
!i = character of string
 density_matrix = 0.d0
!loop over all determinants
 do k=1,Ndet
!loop over spin 0,1
  do ispin=1,2
    ishift = 0
  !loop over all characters in string
    do i=1,Nint
      buffer = det(i,ispin,k)
	 
      do while (buffer /= 0_8)
       write (*,*) "Buffer = ", buffer
	  write (*,*) "  trailz(buffer) = ", trailz(buffer) 
	  write (*,*) "  ishift = ", ishift
        write (*,*) " before j = ", j
        j = trailz(buffer) + ishift + 1
        write (*,*) " after j = ", j
        density_matrix(j,j) = density_matrix(j,j) &
                            + coef(k)*coef(k)
	   write (*,*) "buffer-1_8 = ", buffer-1_8
        buffer = iand(buffer,buffer-1_8)
	   
	   write (*,*) "************"
      end do
      ishift = ishift+64
    end do
  end do
  do l=1,k-1
   if (n_excitations(det(1,1,k),det(1,1,l),Nint) /= 1) then
     cycle
   end if
   call get_excitation(det(1,1,k),det(1,1,l),exc,deg,phase,Nint)
   if (exc(0,1,1) == 1) then
     i = exc(1,1,1) 
     j = exc(1,2,1) 
   else
     i = exc(1,1,2)
     j = exc(1,2,2) 
   end if
   c = phase*coef(k)*coef(l)
   density_matrix(j,i) = density_matrix(j,i) + c 
   density_matrix(i,j) = density_matrix(i,j) + c 
  end do
 end do
end
