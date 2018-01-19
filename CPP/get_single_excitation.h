//
// Created by chris on 01/01/2018.
//

#ifndef UNTITLED1_GET_SINGLE_EXCITATION_H
#define UNTITLED1_GET_SINGLE_EXCITATION_H

#include <c++/array>
#include <c++/bitset>
#include "CountLeadingZeros.h"
#include "get_holes_and_particles.h"



using namespace std;

template <int n> class get_single_excitation{
    get_holes_and_particles<n> holes_and_particles;
public: void getSingleExcitation(bitset<n> det1up, bitset<n> det1down,
                                 bitset<n>det2up, bitset<n>det2down, int ***exc, int degree, double *phase) {
        exc[0][0][0] = 0;
        exc[0][1][0] = 0;
        exc[0][0][1] = 0;
        exc[0][1][1] = 0;

        int tz;

        if (det1up == det2up) {
            //    do nothing
        } else {

            holes_and_particles.processExc(det1up, det2up, exc);
            if ((exc[0][0][0] & exc[0][1][0]) == 1) {
                   phase = computePhase(exc);
            }

        }
    }


public: void computePhase( bitset<n> det1up, bitset<n> det1down,
                           bitset<n>det2up, bitset<n>det2down, int ***exc ){
        int low, high, j, nn, k, m, temp, nperm;

        //identify highest and lowest spin orbitals involved in the excitation
        low = min(exc[1][0][0], exc[1][1][0]);
        high = max(exc[1][0][0],exc[1][1][0]);

        //Bit mask used to extract occupied spin orbitals placed
        //between hole and paricle
        bitset<n> mask (0);

        for(int i = low; i < high; i++){
            mask[i] = 1;
        }

        bitset<n> det1[2]= {det1up, det1down};
        bitset<n> det2[2]= {det2up, det2down};

        j = ((low-1)/n)+1;
        nn = (low-1)& (n-1);

        //K and m are used in scemama code to determine which 64 bit integer the low and high belong to
//        k = ((high-1)/n)+1;
//        m = (high-1) & (n-1);

        if ( j == k ){
                nperm =  bitset<n>(det1[1].to_ullong() &
                                           (~(1 << nn+1)+1) & ((1 << m) -1)).count();

        }
        else {

            // If NINT is not used - do we need this code?
//            nperm =  bitset<n>(det1[j].to_ullong() &
//                                       ( ~(0) & ( ~(1 << nn) + (1))))
//                    + bitset<n>(det1[k].to_ullong() &

        }

        return nperm;

    }

};

#endif //UNTITLED1_GET_SINGLE_EXCITATION_H
