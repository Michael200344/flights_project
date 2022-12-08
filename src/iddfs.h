#pragma once
#include "adjacency_list.h"
#include <queue>
#include <iostream>
/* iddfs = Iterative Deepening Depth First Search.
The main goal of this search algorithm is to find out if a source airport is within a specified number of
flights away from a destination airport.
*/

// Performs a depth limited search from a given source airport.
bool DLS(Airport* start, Airport* target, int numFlights, AdjList& adjList);

// Checks if start and destination airports are within x flights of each other
bool iddfs(Airport* start, Airport* target, int x, AdjList& adjList);

std::vector<Airport*> getOrder();

int getNumFlightsRequired();