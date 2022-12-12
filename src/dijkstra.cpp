#include "Dijkstra.h"
#include "airport.h"
#define INT_MAX 10000000

pair<vector<Airport*>, float> Dijkstras(AdjList& graph, string start, string dest) {
    return Dijkstras(graph, graph.getMap()[start], graph.getMap()[dest]);
}

pair<vector<Airport*>, float> Dijkstras(AdjList& graph, Airport* start, Airport* dest) {


    if (start->getFlights().empty() || dest->getFlights().empty()) {
        return pair<vector<Airport*>,float>(vector<Airport*>(), -1);
    }

    vector<Airport*> list = graph.getVector();

    vector<int> toVisit;
    unordered_map<string, float> distance;
    vector<Airport*> terminals;
    vector<int> previous(12000);

    string startStr = start->getIATA();
    string destStr = dest->getIATA();

    unsigned idx = 0;
    int start_idx = 0;
    int dest_idx = 0;
    
    for(Airport* a : list) { // sets each distance to inf and inshortest to false
        if (a == start) {
            start_idx = idx;
        }
        if (a == dest) {
            dest_idx = idx;
        }
        toVisit.push_back(idx);
        distance.insert(pair<string, float>(a->getIATA(), INT_MAX));
        terminals.push_back(a);
        idx++;
    }




    previous[dest_idx] = start_idx;

    distance[terminals[start_idx]->getIATA()] = 0;

    int currAirport = start_idx;
    

    while (!toVisit.empty()) {
        float minDistance = INT_MAX;
        int minIndex = 0;
       

        int j = 0;
        for(int curr : toVisit) {
            auto currDist = terminals[j]->getIATA();
            if (distance[currDist] < minDistance) {
                minDistance = distance[currDist];
                minIndex = j;
            }
            j++;
        }



        currAirport = toVisit[minIndex];
        toVisit.erase(toVisit.begin() + minIndex);

        if (terminals[currAirport] == dest) {
            auto currDist = terminals[dest_idx]->getIATA();
            if (distance[currDist] == INT_MAX) {
                // cout << "here " << currDist << endl;
                auto currTermFlights = terminals[currAirport]->getFlights();
                for (auto& curr : currTermFlights) {
                    // cout << curr->getSource() << " source and dest > " << curr->getDestination() << endl;
                    if ((curr->getSource() == startStr && curr->getDestination() == destStr) || (curr->getDestination() == startStr && curr->getSource() == destStr)) {
                        distance[currDist] = curr->getDistance();
                    }
                }
            }
            break;
        } 

        // // cout << "before flights Iteration" << endl;
        auto currTermFlights = terminals[currAirport]->getFlights();
        auto inIdx = 0;

        for (auto curr : currTermFlights) {
            auto currDist = terminals[currAirport]->getIATA();
            float updateDist = distance[currDist] + curr->getDistance();

            if (updateDist < distance[currDist]) {
                distance[currDist] = updateDist;
                previous[inIdx] = currAirport;
            }
            inIdx++;
        }

    }



    if (terminals[currAirport] != dest) {
        return pair<vector<Airport*>,float>(vector<Airport*>(), -1);
    }



    stack<Airport*> tmp;
    while (terminals[currAirport] != start) {
        tmp.push(terminals[currAirport]);
        // // cout << start_idx << " <- start : curr -> " << currAirport << " : prev -> " << previous[currAirport] << endl;
        currAirport = previous[currAirport];
    }



    vector<Airport*> path;
    while (!tmp.empty()) {
        auto id = tmp.top();
        path.push_back(id);
        tmp.pop();
    }

    path.push_back(start);
    
    auto destDist = terminals[dest_idx]->getIATA();
    return pair<vector<Airport*>,float>(path, distance[destDist]);
}

// int minDistance(AdjList* graph) {
//     int min = INT_MAX;
//     auto list = graph->getVector();
//     for(Airport* a : list) {
//         // if () {
            
//         // }
//     }
//     return 0;
// }
