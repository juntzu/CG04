//
// Created by chris on 31/12/2017.
//

using namespace std;
#ifndef UNTITLED1_COMPUTE_DENSITY_MATRIX_H
#define UNTITLED1_COMPUTE_DENSITY_MATRIX_H

#include <c++/bitset>
#include <c++/vector>
#include "CountLeadingZeros.h"
#include "n_excitations.h"

template <int orbitals> class compute_density_matrix{
    CountLeadingZeros countLeadingZeros;
    n_excitations n;

public: void computeDensityMatrix(double coEf[], int moNum, vector< bitset< orbitals > > dets_spin_up, vector< bitset< orbitals > > dets_spin_down, int nInt) {

        double densityMatrix[moNum][moNum];
        unsigned long long iShift = 0;
        unsigned long long j;
        bitset<orbitals> bitbuffer;
        int exc[3][2][2];
        double phase, c;

        for (int detPairIndex = 0; detPairIndex < dets_spin_up.size(); detPairIndex++) {
            //cout << dets_spin_up.at(detPairIndex) << endl;
            //bitset< 128 > one(1);
            unsigned long long int iShift = 0;

            bitbuffer = dets_spin_up.at(detPairIndex);
            bitset<orbitals> zero;
            while (bitbuffer != zero) {
                // cout<< 0 << endl;
                j = countLeadingZeros.leading_zero_naive(bitbuffer) + iShift + 1;
                densityMatrix[j][j] = densityMatrix[j][j] + coEf[detPairIndex] * coEf[detPairIndex];
                bitbuffer = bitbuffer &= bitset<orbitals>(bitbuffer.to_ullong() - 1);
                //  cout<< bitbuffer << endl;

            }
            iShift += 64;
        }

        for (int detPairIndex = 0; detPairIndex < dets_spin_down.size(); detPairIndex++) {
            //cout << dets_spin_up.at(detPairIndex) << endl;
            //bitset< 128 > one(1);
            iShift = 0;

            bitbuffer = dets_spin_down.at(detPairIndex);
            bitset<orbitals> zero;
            while (bitbuffer != zero) {
                // cout<< 0 << endl;
                j = countLeadingZeros.leading_zero_naive(bitbuffer) + iShift + 1;
                densityMatrix[j][j] = densityMatrix[j][j] + coEf[detPairIndex] * coEf[detPairIndex];
                bitbuffer = bitbuffer &= bitset<orbitals>(bitbuffer.to_ullong() - 1);
                // cout<< bitbuffer << endl;

            }
            iShift += 64;
        }

        for (int detPairIndex = 0; detPairIndex < dets_spin_up.size(); detPairIndex++) {
            for (int i = 0; i < detPairIndex - 1; i++) {
//            if(n.excitations(dets(1,1,k),det(1,1,l),Nint) /= 1) then
//                        cycle
//                end if



                // call get_excitation(det(1,1,k),det(1,1,l),exc,deg,phase,Nint)
//            if(exc(0,1,1) == 1) then
//                        i = exc(1,1,1)
//                j = exc(1,2,1)
//            else
//                i = exc(1,1,2)
//            j = exc(1,2,2)
//            end if
//                !
//                        c = phase*coef(k)*coef(l)
//            !
//                    density_matrix(j,i) = density_matrix(j,i) + c
//            density_matrix(i,j) = density_matrix(i,j) + c
            }
        }

    }
};
#endif //UNTITLED1_COMPUTE_DENSITY_MATRIX_H
