//
// Created by chris on 27/12/2017.
//
using namespace std;
#include <c++/bitset>
#include <c++/vector>
#include <c++/fstream>
#include <boost/algorithm/string/split.hpp>
#include <c++/sstream>
#include <boost/algorithm/string/classification.hpp>

#ifndef UNTITLED1_DETREADER_H
#define UNTITLED1_DETREADER_H


template <int n> class DetReader{

public: pair <vector<bitset<n>>, vector<bitset<n>>> readFile(string fileName){
        pair <vector<bitset<n>>,vector<bitset<n>>> dets;

        bool up = true;
        string getcontent;
        ifstream openfile("C:\\Users\\chris\\Documents\\CG04\\CPP\\"+fileName);
        if (openfile.is_open()) {
            long int amount = 0;
            getline(openfile, getcontent);
            while (!openfile.eof()) {
                getline(openfile, getcontent);

                vector<string> strs;
                boost::split(strs, getcontent, boost::is_any_of("\t "), boost::token_compress_on);

                //iterate over each value in strs - start at index 1
                for (size_t i = 1; i < strs.size(); i++) {
                    istringstream is(strs[i]);
                    unsigned long long int ii = 0;
                    is >> ii;
                    bitset<n> bs(ii);

                    if (up) {
                        dets.first.push_back(bs);
                        up = false;
                    } else {
                        dets.second.push_back(bs);
                        up = true;
                    }
                    amount = amount + 1;
                }


            }

        }

        openfile.close();
        return dets;
    }

};
#endif //UNTITLED1_DETREADER_H
