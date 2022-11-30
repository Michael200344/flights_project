#pragma once

#include <string>
#include <vector>
#include "flight.h"

using namespace std;

class Airport {
    public:

        Airport();
        Airport(const std::string IATA);
        Airport(const string IATA, const vector<Flight> flights);

        // bool operator==(const Airport a1);

        std::vector<Flight>* getFlights();
        void setVisited();
        void setNotVisited();

        bool getVisited() const;
        std::string getIATA() const;

    private:

        std::vector<Flight> flights_; // moved from private, not sure if this is correct
        std::string IATA_; // each airport has a code
        bool visited_; // used in BFS to determine if vertex has been visited
        
};