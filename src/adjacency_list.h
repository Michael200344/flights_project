#pragma once
#include <vector>
#include "airport.h"
#include "utils.h"

class AdjList {

    public:

        AdjList(const std::string &filename);

    private:

        std::vector<Airport> list;

};