#include "iddfs.h"
/* iddfs = Iterative Deepening Depth First Search.
The main goal of this search algorithm is to find out if a source airport is within a specified number of
flights away from a destination airport.
*/

std::vector<Airport*> orderAdded;

int numFlightsRequired = 0;

int getNumFlightsRequired() {
    return numFlightsRequired;
}

std::vector<Airport*> getOrder() {
    return orderAdded;
}

bool DLS(Airport* start, Airport* target, int limit, AdjList& adjList) {
    orderAdded.push_back(start);
    if (start -> getIATA() == target -> getIATA()) {
        return true;
    } // If the airport passed is the target airport, return true.
    
    if (limit <= 0) {
        return false;
    } // If the maximum depth has been reached, stop recursing and return false.

    for (size_t i = 0; i < start -> getFlights().size(); i++) {
        Flight* flight = start -> getFlights().at(i);
        Airport* newStart = adjList.searchMap(flight -> getDestination());
            if (DLS(newStart, target, limit - 1, adjList)) {
                return true;
            }
    } // Loop through each flight from that airport
    return false;
}

bool iddfs(Airport* start, Airport* target, int x, AdjList& adjList) {
    orderAdded.clear();
    // Repeatedly depth-limit search until x number of flights is reached
    for (int i = 0; i <= x; i++) {
        if (DLS(start, target, i, adjList) == true) {
            numFlightsRequired = i;
            return true;
        }
    }
    return false;
    // return std::vector<Airport*> {};
}

/*
Current Issues:
Whenever I add to visitedOrder, I need to check to make sure that the airport hasn't already been visited




*/