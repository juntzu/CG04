//
// Created by chris on 30/12/2017.
//

#ifndef UNTITLED1_NAIVEPOPCNT_H
#define UNTITLED1_NAIVEPOPCNT_H

#include <c++/iostream>

class NaivePopcnt{

 //   http://www.cplusplus.com/forum/beginner/119203/
//    int count = 0 , i;
//    for( i = 0; n; ++i )
//    {
//        count += n & 1;
//        n >>= 1;
//    }
//
//    cout << "Bits set: " << count << endl;
//    return( i);

public: unsigned long long popcnt( unsigned long long n )
    {
        unsigned long long i;
        for( i = 0; n; ++i )
        {
            n &= n - 1;
        }

        return( i );
    }
};

#endif //UNTITLED1_NAIVEPOPCNT_H
