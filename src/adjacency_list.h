#pragma once
#include <vector>
#include "airport.h"
#include "flight.h"
#include "utils.h"
#include <unordered_set>

class AdjList {

    public:
        AdjList();
        AdjList(const std::string &filename);

    private:

        std::unordered_set<Airport> list;

};