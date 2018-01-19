#include <c++/bitset>
#include <c++/vector>
#include <c++/fstream>
#include <c++/iostream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "hayai/hayai.hpp"
#include "CountLeadingZeros.h"
#include "NaivePopcnt.h"

int main(){
    hayai::ConsoleOutputter consoleOutputter;
    hayai::Benchmarker::AddOutputter(consoleOutputter);
    hayai::Benchmarker::RunAllTests();
    return 0;
}

BENCHMARK(NaivePopcnt, NaivePopcnt, 10, 100000)
{
    const int bitSetSize = 64;
    CountLeadingZeros <int, bitSetSize> c;
    std::bitset<bitSetSize> foo(1);

    for(int i = 1; i < bitSetSize; i++){
        foo = foo << 1;
    }

    NaivePopcnt n;

}


//static void computeDensityMatrix(double coEf[], int moNum, vector< bitset< 128 > > dets_spin_up, vector< bitset< 128 > > dets_spin_down, int nInt) {
//    double densityMatrix[moNum][moNum];
//    unsigned long long iShift = 0;
//    unsigned long long j;
//    bitset<128> bitbuffer;
//
//    for (int detPairIndex = 0; detPairIndex < dets_spin_up.size(); detPairIndex++) {
//        //cout << dets_spin_up.at(detPairIndex) << endl;
//        //bitset< 128 > one(1);
//        unsigned long long int iShift = 0;
//
//        bitbuffer = dets_spin_up.at(detPairIndex);
//        bitset<128> zero;
//        while (bitbuffer != zero) {
//            // cout<< 0 << endl;
//            j = leading_zero_naive(bitbuffer) + iShift + 1;
//            densityMatrix[j][j] = densityMatrix[j][j] + coEf[detPairIndex] * coEf[detPairIndex];
//            bitbuffer = bitbuffer &= bitset<128>(bitbuffer.to_ullong() - 1);
//            //  cout<< bitbuffer << endl;
//
//        }
//        iShift += 64;
//    }
//
//    for (int detPairIndex = 0; detPairIndex < dets_spin_down.size(); detPairIndex++) {
//        //cout << dets_spin_up.at(detPairIndex) << endl;
//        //bitset< 128 > one(1);
//        iShift = 0;
//
//        bitbuffer = dets_spin_down.at(detPairIndex);
//        bitset<128> zero;
//        while (bitbuffer != zero) {
//            // cout<< 0 << endl;
//            j = leading_zero_naive(bitbuffer) + iShift + 1;
//            densityMatrix[j][j] = densityMatrix[j][j] + coEf[detPairIndex] * coEf[detPairIndex];
//            bitbuffer = bitbuffer &= bitset<128>(bitbuffer.to_ullong() - 1);
//            // cout<< bitbuffer << endl;
//
//        }
//        iShift += 64;
//    }
//
//    for (int detPairIndex = 0; detPairIndex < dets_spin_up.size(); detPairIndex++) {
//        for (int i = 0; i < detPairIndex - 1; i++) {
////            if(n_excitations(det(1,1,k),det(1,1,l),Nint) /= 1) then
////                        cycle
////                end if
//
//
//
//           // call get_excitation(det(1,1,k),det(1,1,l),exc,deg,phase,Nint)
////            if(exc(0,1,1) == 1) then
////                        i = exc(1,1,1)
////                j = exc(1,2,1)
////            else
////                i = exc(1,1,2)
////            j = exc(1,2,2)
////            end if
////                !
////                        c = phase*coef(k)*coef(l)
////            !
////                    density_matrix(j,i) = density_matrix(j,i) + c
////            density_matrix(i,j) = density_matrix(i,j) + c
//        }
//    }
//
//}
//int main() {
//
//        int nDet = 10;
//        //long det[nInt][2][nDet];
//        double coef[nDet];
//
//        int moNum = 105;
//        double densityMatrix[moNum][moNum];
//
//        static int const MAXORB = 128;
//
//        vector< bitset< MAXORB > > dets_spin_up;
//        vector< bitset< MAXORB > > dets_spin_down;
//
//
//        bool up = true;
//        string getcontent;
//        ifstream openfile("C:\\Users\\chris\\CLionProjects\\untitled1\\cuShortened.dat");
//        if (openfile.is_open()) {
//            long int amount = 0;
//            getline(openfile, getcontent);
//            while (!openfile.eof()) {
//                getline(openfile, getcontent);
//
//                vector<string> strs;
//                boost::split(strs, getcontent, boost::is_any_of("\t "), boost::token_compress_on);
//
//
//                cout << "* size of the vector: " << strs.size() << endl;
//                for (size_t i = 1; i < strs.size(); i++) {
//                    // cout << strs[i] << endl;
//
//                    istringstream is(strs[i]);
//
//                    unsigned long long int ii = 0;
//                    // use is like an input stream
//                    is >> ii;
//
//                    // cout << getcontent << endl;
//                    bitset<MAXORB> bs(ii);
//                    //cout << bs << endl << endl ;
//                    // dets_spin_up.push_back(bitset(i));
//                    if (up) {
//                        // cout << bs << endl;
//
//                        //  cout << leading_zero_naive(bs) << endl;
//                        //int n = 0;
//                        //bitset  * bitSet = &bs;
//
//
//                        // cout << n << endl;
//
//                        dets_spin_up.push_back(bs);
//                        up = false;
//                    } else {
//                        dets_spin_down.push_back(bs);
//                        up = true;
//                    }
//                    amount = amount + 1;
//                }
//
//
//            }
//
//        }
//
//    string content;
//    ifstream coefFile("C:\\Users\\chris\\CLionProjects\\untitled1\\cu.coef");
//    if (coefFile.is_open()) {
//        long int amount = 0;
//        //getline(coefFile, content);
//        while (!coefFile.eof()&& amount<nDet) {
//            getline(coefFile, content);
//
//            vector<string> strs;
//            boost::split(strs, content, boost::is_any_of("\t "), boost::token_compress_on);
//
//
//            //cout << "* size of the vector: " << strs.size() << endl;
//            for (size_t i = 1; i < strs.size(); i++) {
//                // cout << strs[i] << endl;
//              //  cout.precision(300);
//                if(amount>=nDet)break;
//                istringstream is(strs[i]);
//                double ii;
//                // use is like an input stream
//                is >> ii;
//               // cout << ii<< endl;
//                coef[amount] = ii;
//                amount++;
//
//               // double t =   0.968464025462443;
//               // cout << t<< endl;
//
//            }
//
//
//        }
//
//    }
//
//
//    computeDensityMatrix(coef, moNum, dets_spin_up, dets_spin_down, 2);
//
////        for(int i = 0; i < dets_spin_up.size();i++){
////            cout << dets_spin_up.at(i) << endl << endl;
////        }
////
////        for(int i = 0; i < dets_spin_up.size();i++){
////            cout << dets_spin_down.at(i)  << endl;
////        }
//
//
//
//    return 0;
//}







