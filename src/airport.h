#pragma once

#include <string>
#include <vector>
#include "flight.h"
#include <iostream>

using namespace std;

class Airport {
    public:

        Airport();
        Airport(const std::string IATA);
        Airport(const string IATA, const vector<Flight*> flights);

        bool operator==(const Airport a1);
        friend bool operator<(const Airport a1, const Airport a2);
        Airport operator()(const Airport a1, const Airport a2);

        std::vector<Flight*>* getFlights();
        void setFlights(Flight* f);

        void setVisited();
        void setNotVisited();

        bool getVisited() const;
        std::string getIATA() const;

        std::vector<Flight*> flights_; // moved from private, not sure if this is correct

    private:

        
        std::string IATA_; // each airport has a code
        bool visited_; // used in BFS to determine if vertex has been visited
        
};