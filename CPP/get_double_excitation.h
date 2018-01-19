//
// Created by chris on 03/01/2018.
//

#ifndef UNTITLED1_GET_DOUBLE_EXCITATION_H
#define UNTITLED1_GET_DOUBLE_EXCITATION_H

#include <c++/bitset>
#include <c++/iostream>

using namespace std;

template <int n> class get_double_excitation{
public: void getDoubleExcitation(bitset<n> det1up, bitset<n> det1down,
                                 bitset<n>det2up, bitset<n>det2down, double * phase, int *exc[3][2][2]) {

        *exc[0][0][0] = 0;
        *exc[0][1][0] = 0;
        *exc[0][0][1] = 0;
        *exc[0][1][1] = 0;

            CountLeadingZeros<int,n> c;
            int nexc = 0, nperm =0;
            int idx_particle = 0, idx_hole = 0;


        if (det1up == det2up) {
            //    cycle;

        } else {
//                cout << det1up.to_ullong() << endl;
//                cout << det2up.to_ullong() << endl;

                bitset<n> tmp = (det1up ^= det2up);
                bitset<n> particle = tmp &= det2up;
                bitset<n> hole = tmp &= det2down;

                while(particle.to_ullong() != 0){

                }
        }






    }

};
#endif //UNTITLED1_GET_DOUBLE_EXCITATION_H
