#include "utils.h"
#include <vector>
#include <iostream>
#include "airport.h"
#include "flight.h"
#include <unordered_set>
#include <unordered_map>

class AdjList {

    public:

        AdjList(const std::string &filename);
        std::unordered_set<Airport> getList() const;
        Airport* findAirport(std::string IATA) const;
        std::unordered_map<std::string, Airport> getMap() const;

    private:

        std::unordered_set<Airport> list_;
        std::unordered_map<std::string, Airport> IATAmap_;

};