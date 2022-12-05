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
void BFS(AdjList &adjlist, Airport* start);