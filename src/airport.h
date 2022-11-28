#pragma once

#include <string>
#include <vector>
#include "flight.h"

class Airport {
    public:
        Airport();
        Airport(const std::string IATA);


        std::vector<Flight> flights; // moved from private, not sure if this is correct

    private:
        std::string IATA_;
        

};