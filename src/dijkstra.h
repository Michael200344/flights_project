#include "adjacency_list.h"
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;
using std::string;
using std::vector;
using std::pair;
using std::stack;

pair<vector<Airport*>, float> Dijkstras(AdjList& graph, string start, string dest); 
// vector<Airport> dijkstraShortestPath(Airport* start, Airport* dest, AdjList* graph);
pair<vector<Airport*>, float> Dijkstras(AdjList& graph, Airport* start, Airport* dest);
int minDistance(AdjList* graph);