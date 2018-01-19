public class density_matrix {

    public static void main(String[] args) {
        computeDensityMatrix(new long[1][1][1], new int[1], 50, 1);
    }

    //det
       //!     First dimension:
//    !       A determinant consists of two strings of integers. Each string is
//    !       the same length "Nint". All determinants are the same length.
//!
//        !     Second determinant:
//            !       There are two strings per determinant.
//            !
//            !             one is for SPIN UP   spin-orbials;
//!             one is for SPIN DOWN spin orbitals.
//            !
//            !       This dimension is always fixed at 2.
//            !
//            !     Third dimension:
//            !       The number of determinants in the wavefunction.
//!

//    Input data:
//            !            det storage for the determinants. A 3D array.

//!           coef and array of size ndet, holds the coefficient for
//            !                each determinant
//!         mo_num the number of molecular orbitals
//          nInt - integer string length

    //    int[][][] det;
//    int nDet, coEf, moNum, nInt;


//    !     Output data:
//            !        density_matrix a 2D array, size mo_num x mo_num holding
//!                       the spin reduced density matrix

    static int [][] densityMatrix;
    static long buffer;

    static void computeDensityMatrix(long[][][] det, int[] coEf, int moNum, int nInt){
        //all elements initialised to 0
        densityMatrix = new int [moNum][moNum];


        //using longs to represent f90 8byte integer
        long iShift;
        long j;
        int [][] densityMatrix;
        long buffer;

        //loop over all determinant pairs
        for ( int detPairIndex = 0 ; detPairIndex < det.length; detPairIndex++){
         //   !....... Here we compute the case determinant "k"
         //       !        crossed with with itself

          //  !        There are the so called on-diagonal terms.
          //  !
          //          !        By definition there are no excitations between
          //  !        the pair - its the same determinant
            for ( int iSpin = 0 ; iSpin < 2; iSpin++){
                iShift = 0;
                //loop over all integer in determinant integer string length nInt
                for ( int i = 0 ; i < nInt; i++) {
                    buffer = det[i][iSpin][detPairIndex];

                    while(buffer != 0){
                        // get Amount of leading zeros in binary representation of buffer
                        // add to iShift + 1 and store in j
                        j = getAmountOfLeadingZeros(buffer) + iShift +1;
                        densityMatrix[j][j] = densityMatrix[j][j] + coEf[detPairIndex] * coEf[detPairIndex];
                        //buffer equals ((binary representation(buffer) AND (binaryRepresentation(buffer-1))
                        buffer = (buffer && buffer-1);
                    }
                    iShift += 64;
                }

            }


            //!....... Look at all pairs of determinants involving "k"
            //!
            //        !        Due to symmetry, we only need consider dets=1,...,(k-1)

            for (int l = 0; l < detPairIndex; l++){



              //  !.......... Find the number of excitations to move from one
              //  !           determinant to the other.

                if (n_excitations(det(1,1,k),det(1,1,l),Nint) /= 1){
                    continue;
                }

           //     !
           //             !.......... We get here is there is precisely ONE excitation.
           //     !
           //             !           Lets find which ORBITALS are involved.
           //     !
           //             !           Note: ORBITALS, not SPIN-ORBITALS.
           //     !

                get_excitation(det(1,1,k),det(1,1,l),exc,deg,phase,Nint);



//                !.......... The ORBITAL indices define the element of the density matrix
//                !           The value is the product of the coefficients.
//                !
//                        !           Let's add that value to the density matrix element.
//                !
//                        !           It is useful to remeber that many determinant pairs may
//                !           contribute to the SAME density matrix element.
//                !
//                        !           We use the symmetry argument to populate the (j,i) element
//                !           from the (i,j) here.
                
                if(exc(0,1,1) == 1) {
                    i = exc(1, 1, 1)
                    j = exc(1, 2, 1)
                }
                else {
                    i = exc(1, 1, 2)
                    j = exc(1, 2, 2)
                }

                c = phase*coef(k)*coef(l)
                !
                        density_matrix(j,i) = density_matrix(j,i) + c
                density_matrix(i,j) = density_matrix(i,j) + c


            }

        }




    }




    int n_excitations(det1, det2, Nint){

    }

}
