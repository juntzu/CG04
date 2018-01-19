//
// Created by chris on 05/12/2017.
//

#ifndef UNTITLED1_COUNTLEADINGZEROS_H
#define UNTITLED1_COUNTLEADINGZEROS_H


#include <c++/bitset>

template <typename ReturnType, int monum> class CountLeadingZeros {
public: ReturnType leading_zero_naive(std::bitset< monum > x)
    {
        ReturnType t = 0;
        for (int i = 0; i < monum; i ++) {
            if( x[(monum-1)-i]==1){
                break;
            }
            t++;
        }
        return t;
    }

};


#endif //UNTITLED1_COUNTLEADINGZEROS_H
