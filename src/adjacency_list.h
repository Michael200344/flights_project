#include "utils.h"
#include <vector>
#include "airport.h"
#include "flight.h"
#include <unordered_set>
#include <unordered_map>

class AdjList {

    public:

        AdjList(const std::string &filename);
        std::unordered_set<Airport> getList();
        Airport* findAirport(std::string IATA);
        std::unordered_map<std::string, Airport> getMap();

    private:

        std::unordered_set<Airport> list_;
        std::unordered_map<std::string, Airport> IATAmap_;

};