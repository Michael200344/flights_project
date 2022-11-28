#pragma once

#include <string>
#include <vector>
#include "flight.h"

using namespace std;

class Airport {
    public:
        Airport();
        Airport(const std::string IATA);


        std::vector<Flight> flights; // moved from private, not sure if this is correct
    
    Airport(string iata, vector<Flight> connections);


    private:
        std::string IATA_;
        
};