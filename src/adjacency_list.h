#include "utils.h"
#include <vector>
#include "airport.h"
#include "flight.h"
#include <unordered_set>

class AdjList {

    public:

        AdjList(const std::string &filename);

    private:

        std::unordered_set<Airport> list;

};