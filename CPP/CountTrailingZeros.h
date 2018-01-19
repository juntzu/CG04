//
// Created by chris on 14/01/2018.
//

#ifndef UNTITLED1_COUNTTRAILINGZEROS_H
#define UNTITLED1_COUNTTRAILINGZEROS_H


#include <c++/bitset>

template <typename ReturnType, int monum> class CountTrailingZeros {
public: ReturnType trailing_zero_naive(std::bitset< monum > x)
    {
        ReturnType t = 0;
        for (int i = 0; i < monum; i ++) {
            if( x[i]==1){
                break;
            }
            t++;
        }
        return t;
    }

};



#endif //UNTITLED1_COUNTTRAILINGZEROS_H
