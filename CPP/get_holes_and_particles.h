//
// Created by chris on 03/01/2018.
//

#ifndef UNTITLED1_GET_HOLES_AND_PARTICLES_H
#define UNTITLED1_GET_HOLES_AND_PARTICLES_H


#include <c++/utility>
#include <c++/bitset>
#include <c++/iostream>
#include "CountTrailingZeros.h"

template <int n> class get_holes_and_particles{
    CountTrailingZeros<int,n> c;
    int tz;

public: void processExc(std::bitset<n> det1,std::bitset<n> det2, int ***exc){
            pair<bitset<n>, bitset<n>> p = getHolesAndParticles(det1,det2);
            processHolesAndParticles(p, exc);
    }

public: void processHolesAndParticles(pair<bitset<n>, bitset<n>> p, int ***exc){

            //particle
            if (p.first.to_ullong() > 0 ) {
                tz = c.trailing_zero_naive(p.first);
                exc[0][1][0] = 1;
                exc[1][1][0] = tz;
            }

            //hole
            if (p.second.to_ullong() > 0 ) {
                tz = c.trailing_zero_naive(p.second);
                exc[0][0][0] = 1;
                exc[1][0][0] = tz;
            }
    }
public: std::pair<std::bitset<n>,std::bitset<n>> getHolesAndParticles(std::bitset<n> det1,std::bitset<n> det2){
        //particle and hole are searched simultaneously and placed into a bitset pair
        std::bitset<n> tmp = (det1 ^ det2);
        std::bitset<n> particle = tmp & det2;
        std::bitset<n> hole = tmp & det1;
        std::pair <std::bitset<n> , std::bitset<n>> p (particle, hole);
        return p;
    }
};

#endif //UNTITLED1_GET_HOLES_AND_PARTICLES_H
