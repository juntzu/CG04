//
// Created by chris on 30/12/2017.
//

#ifndef UNTITLED1_N_EXCITATIONS_H
#define UNTITLED1_N_EXCITATIONS_H

#include <c++/bitset>
#include <c++/iostream>
//Dynamically sized n_excitations function - int n = number of bits required to represent determinant
template <int n> class n_excitations{

public: bitset<n> excitations
            (bitset<n> det1up, bitset<n> det1down,
             bitset<n>det2up, bitset<n>det2down){

        // ^=  is equal to XoR
        // .count() is equal to popcount
        bitset<n> r (( det1up ^= det2up).count()
                     + ( det1down ^= det2down).count());
        //divide result by two
        r = r >> 1;
        return r;

    }
};
#endif //UNTITLED1_N_EXCITATIONS_H
