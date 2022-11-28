#pragma once

#include <string>
#include <vector>
#include "flight.h"

class Airport {
    public:
    Airport();
    Airport(string iata, vector<Flight> connections);

    private:
    string IATA;
    vector<Flight> flights;

};