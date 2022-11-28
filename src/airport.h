#pragma once

#include <string>
#include <vector>
#include "flight.h"

using namespace std;

class Airport {
    public:
    Airport();
    Airport(string iata, vector<Flight> connections);

    private:
    std::string IATA;
    std::vector<Flight> flights;

};