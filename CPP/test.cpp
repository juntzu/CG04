//
// Created by chris on 05/12/2017.
//
using namespace std;

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "CountLeadingZeros.h"
#include "DetReader.h"
#include "NaivePopcnt.h"
#include "n_excitations.h"
#include "get_excitation.h.h"
#include "get_holes_and_particles.h"
#include "CountTrailingZeros.h"
#include "get_single_excitation.h"


TEST_CASE( "Test get holes and particles function against output from Scemema code ", "[get_holes_and_particles]" ){
    get_holes_and_particles<64> g;

    std::bitset<64> det1up (8589949951);
    std::bitset<64> det1down (17179899903);
    std::bitset<64> det2up (4294999551);
    std::bitset<64> det2down(16383);

    REQUIRE(g.getHolesAndParticles(det1up, det2up).first.to_ullong() == 4294984704);
    REQUIRE(g.getHolesAndParticles(det1up, det2up).second.to_ullong() ==   8589935104);
    REQUIRE(g.getHolesAndParticles(det1down, det2down).first.to_ullong() == 2048);
    REQUIRE(g.getHolesAndParticles(det1down, det2down).second.to_ullong() ==   17179885568);
}
TEST_CASE( "Test processHolesParticles function against output from Scemama code", "[process_holes_particles]"){
    get_holes_and_particles<64> g;

    bitset<64> det1 (10000);
    bitset<64> det2 (100000000);

    pair<bitset<64>, bitset<64>> p;
    p.first = det1;
    p.second = det2;

    int dimX = 3; int dimY = 2; int dimZ = 2;
    int*** array;    // 3D array definition;
    // begin memory allocation
    array = new int**[dimX];
    for(int x = 0; x < dimX; ++x) {
        array[x] = new int*[dimY];
        for(int y = 0; y < dimY; ++y) {
            array[x][y] = new int[dimZ];
            for(int z = 0; z < dimZ; ++z) { // initialize the values to whatever you want the default to be
                array[x][y][z] = 0;
            }
        }
    }

    g.processHolesAndParticles(p, array);

    REQUIRE(array[0][1][0] ==1);
    REQUIRE(array[1][1][0] == 4);
    REQUIRE(array[0][0][0] == 1);
    REQUIRE(array[1][0][0] == 8);
}
TEST_CASE("Compute Phase", "[compute_phase]"){

    bitset<64> det1up (10000);
    bitset<64> det1down (10001);
    bitset<64> det2up (1000);
    bitset<64> det2down (1001);

    get_single_excitation<64> g;
    double * phase;

    int dimX = 3; int dimY = 2; int dimZ = 2;
    int*** array;    // 3D array definition;
    // begin memory allocation
    array = new int**[dimX];
    for(int x = 0; x < dimX; ++x) {
        array[x] = new int*[dimY];
        for(int y = 0; y < dimY; ++y) {
            array[x][y] = new int[dimZ];
            for(int z = 0; z < dimZ; ++z) { // initialize the values to whatever you want the default to be
                array[x][y][z] = 0;
            }
        }
    }

    array[0][1][0] = 1;
    array[1][1][0] = 4;
    array[0][0][0] = 1;
    array[1][0][0] = 8;

    g.computePhase(det1up, det1down, det2up, det2down, array, phase);
}
TEST_CASE( "Leading zeros is counted correctly from 0-64 leading zeros ", "[leading_zero_naive]" ) {

    const int bitSetSize = 64;
    CountLeadingZeros<int, bitSetSize> c;
    bitset<bitSetSize> foo(1);

    for(int i = 1; i < bitSetSize; i++){
        REQUIRE( c.leading_zero_naive(foo) == (bitSetSize - i) );
        foo = foo << 1;
    }
    REQUIRE( c.leading_zero_naive(foo) == 0 );
}
TEST_CASE( "Trailing zeros is counted correctly from 0-64 trailing zeros ", "[trailing_zero_naive]" ) {

    const int bitSetSize = 64;
    CountTrailingZeros<int, bitSetSize> c;
    bitset<bitSetSize> foo(1);

    for(int i = 0; i < bitSetSize; i++){
        REQUIRE( c.trailing_zero_naive(foo) == (i) );
//        cout << c.trailing_zero_naive(foo) << endl;
//        cout << foo << endl;
        foo = foo << 1;
    }
    REQUIRE( c.trailing_zero_naive(foo) == bitSetSize );
}
TEST_CASE( "Amount of 1s in a binary string is counted correctly for a single use case", "[popcnt_naive]"){
    NaivePopcnt naivePopcnt;
    int n = 3526; //0110111000110 - 7 bits set
    REQUIRE(naivePopcnt.popcnt(n) == 7);
}
TEST_CASE( "Test n_excitations output against output from equivalent fortran code stored in n_excitations_expectedresults.txt", "[n_excitations]") {
    const int bitSetSize = 64;
    DetReader<bitSetSize> detReader;
    pair<vector<bitset<bitSetSize>>, vector<bitset<bitSetSize>>> dets = detReader.readFile("cuShortened.dat");
    n_excitations<bitSetSize> n;
    int expectedResults[100];
    int exc[3][2][2];
    string getcontent;
    ifstream openfile("C:\\Users\\chris\\Documents\\CG04\\CPP\\testData\\n_excitations_expectedresults.txt");
    expectedResults[0] = 0;
    if (openfile.is_open()) {
        long int amount = 1;
        getline(openfile, getcontent);
        while (!openfile.eof()) {
            getline(openfile, getcontent);

            vector<string> strs;
            boost::split(strs, getcontent, boost::is_any_of("\t "), boost::token_compress_on);

            for (size_t i = 1; i < strs.size(); i++) {

                istringstream is(strs[i]);
                unsigned long long int ii = 0;

                is >> ii;
                expectedResults[amount] = ii;
                amount++;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < dets.first.size(); i++) {
        for (int j = 0; j < dets.first.size(); j++) {
            REQUIRE(n.excitations(dets.first.at(i), dets.second.at(i), dets.first.at(j), dets.second.at(j)) ==
                    expectedResults[count]);
            count++;

        }
    }
}


