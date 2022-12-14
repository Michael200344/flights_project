#pragma once
#include "utils.h"
#include <vector>
#include <iostream>
#include "airport.h"
#include "flight.h"
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cstdlib>

class AdjList {

    public:

    // class AirportHash {   
    //     public: 
    //         std::string operator()(const Airport &a) {
    //             return a.getIATA();
    //     }
    // };

// struct AirportEqual {
//     bool operator()(const Airport & a1, const Airport & a2) {
//         if (a1.getIATA() == a2.getIATA())
//             return true;
//         else
//             return false;
//     }
// };

        AdjList();
        AdjList(const std::string &filename);
        
        Airport findAirport(std::string IATA) const;
        std::map<std::string, Airport*> getMap() const;
        std::vector<Airport*> getVector() const;

        std::set<std::string> getList() const;
        void printAdjList();

        std::pair<AdjList*, std::vector<std::string>> trimList(std::vector<string> IATAlist);
        Airport* searchMap(std::string IATA);

        AdjList* generateSample(size_t n);

    private:

        // std::set<Airport> list_;
        std::set<std::string> IATAlist_;
        std::map<std::string, Airport*> IATAmap_;

        std::vector<Airport*> vector_;

};