//
// Created by chris on 02/01/2018.
//

#ifndef UNTITLED1_BENCHMARKSUITE_H
#define UNTITLED1_BENCHMARKSUITE_H

#include "hayai/hayai_console_outputter.hpp"
#include "hayai/hayai.hpp"
#include "CountLeadingZeros.h"


class benchMarkSuite{

public: void runBenchmark(){
        hayai::ConsoleOutputter consoleOutputter;
        hayai::Benchmarker::AddOutputter(consoleOutputter);
        hayai::Benchmarker::RunAllTests();
    }

    BENCHMARK(NaivePopcnt, NaivePopcnt, 1000, 1000)
    {
        const int bitSetSize = 64;
        CountLeadingZeros <int, bitSetSize> c;
        std::bitset<bitSetSize> foo(1);

        for(int i = 1; i < bitSetSize; i++){
            foo = foo << 1;
        }

    }
};


#endif //UNTITLED1_BENCHMARKSUITE_H
