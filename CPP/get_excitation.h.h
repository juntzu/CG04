//
// Created by chris on 31/12/2017.
//
using namespace std;
#ifndef UNTITLED1_GET_EXCITATION_H_H
#define UNTITLED1_GET_EXCITATION_H_H

#include <c++/bitset>
#include "n_excitations.h"
#include "get_double_excitation.h"

// For the identification of the substitutions, only four
// cases are possible (figure 2) depending of the degree
// of excitation :

// no substitution, -the subroutine exits with a degree of excitation of zero
// one substitution,
// two substitutions
// more than two substitutions - returns a degrees of excitation equal to -1

//For the two remaining
// cases, a particular subroutine is written for each case.

//The cases were ordered from the most probable to the
//least probable to optimize the branch prediction.


// integer, intent(out) :: exc(0:2,2,2)
//. In output, the indices of the spin-orbitals are given in
//the array exc as follows:
//• The last index of exc is the spin (1 for α and 2
//for β)
//• The second index of exc is 1 for holes and 2 for
//particles
//• The element at index 0 of the first dimension of
//        exc gives the total number of holes or particles
//        of spin α or β
//• The first index of exc refers to the orbital index
//of the hole or particle


template <int n> class get_excitation{


    n_excitations<n> nex;
    get_double_excitation<n> doubleExctations;

    //The intent(in) attribute of argument i means that i cannot be changed inside the function.
    //The determinants need not be changed and can be passed by value
    //The exc and degree passed in need to be changed inside the class which is calling the function
    //They are passed by reference
    public: int getExcitation(bitset<n> det1up, bitset<n> det1down, bitset<n>det2up, bitset<n>det2down, int *exc[3][2][2], unsigned long long *degree){

           // unsigned long long degree = nex.excitations(det1up, det1down, det2up, det2down).to_ullong();

            if(*degree<2){
                *degree = -1;
                return -1;
            }
            else if (*degree==2){
               //doubleExctations.getDoubleExcitation(det1up, det1down, det2up, det2down, *exc);
               // return 2;
            }
            else if (*degree ==1){
                //call get_single_excitation(det1,det2,exc,phase,Nint)
                return 1;
            }
            else if (*degree ==0){
                return 0;
            }

        }
};

#endif //UNTITLED1_GET_EXCITATION_H_H
