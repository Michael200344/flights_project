#pragma once
#include "adjacency_list.h"
#include <queue>
#include <iostream>

// class BFS {

//     public:
//         BFS(AdjList &adjlist);
//         BFS(AdjList &adjlist, Airport start);

//     private:
//         std::vector<std::string> visited;

// };

// void BFS(AdjList &adjlist);
std::vector<Airport*> BFS(AdjList &adjlist, Airport* start);
std::vector<Airport*> BFS(AdjList &adjlist, std::string IATA);