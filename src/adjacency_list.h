
#pragma once
#include "utils.h"
#include <vector>
#include <iostream>
#include "airport.h"
#include "flight.h"
#include <unordered_set>
#include <unordered_map>

class AdjList {

    public:

    class AirportHash {   
        public: 
            std::string operator()(const Airport &a) {
                return a.getIATA();
        }
    };

// struct AirportEqual {
//     bool operator()(const Airport & a1, const Airport & a2) {
//         if (a1.getIATA() == a2.getIATA())
//             return true;
//         else
//             return false;
//     }
// };

        AdjList(const std::string &filename);
        
        Airport findAirport(std::string IATA) const;
        std::unordered_map<std::string, Airport> getMap() const;

        std::unordered_set<Airport, AirportHash> getList() const;

    private:

        std::unordered_set<Airport, AirportHash> list_;
        std::unordered_map<std::string, Airport> IATAmap_;

};