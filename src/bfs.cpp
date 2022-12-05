#include "bfs.h"


/*
    This BFS function will take in our adjacency list and mark each flight as discovery or cross 
*/
std::vector<Airport*> BFS(AdjList &adjlist, std::string IATA){

    std::vector<Airport*> result;

    result = BFS(adjlist, adjlist.getMap()[IATA]);
    return result;

}

std::vector<Airport*> BFS(AdjList &adjlist, Airport* start){

    std::vector<Airport*> result;

    auto list = adjlist.getVector();

    for(Airport* a : list){ // sets each vertex to unvisited

        a->setNotVisited();
        std::vector<Flight*> currFlights = a->getFlights(); // fetches flights for each airport

        for(Flight* f : currFlights){

            f->setType('u'); // sets all flights to unexplored  ***** TIME COMPLEXITY CONCERN?

        }
    }

    std::queue<Airport*> q;
    start->setVisited(); // initializing queue, marking start as visited, and pushing it
    q.push(start);

    while(!q.empty()){ // until every node is visited

        Airport* currAirport = q.front(); // fetch current airport
        q.pop();
        result.push_back(currAirport);

        std::vector<Flight*> currFlights = currAirport->getFlights();  // gets current flights
        std::map<std::string, Airport*> currMap = adjlist.getMap();

        for(Flight* f : currFlights){

            std::string adjacentIATA = f->getDestination(); // gets adjacent IATA for each flight
            Airport* adjacentAirport = (currMap).at(adjacentIATA); // finds actual airport object

            if(!adjacentAirport->getVisited()){ // if adjacent airport isnt visited

                // std::cout << "New Airport" << std::endl;

                f->setType('d');
                adjacentAirport->setVisited(); // set discovery edge and graph visited
                q.push(adjacentAirport); // add next vertex to queue

            }
            else if(f->getType() == 'u'){ // if airport has been visited, but no edge, mark cross

                f->setType('c');

            }

            /*
            
            NOTE: I have some time concerns here: we will have to run findAirport which is O(a) for every single flight. I thought
            about potentially making each flight->destination an airport object rather than a string, but think that that would also
            be costly as it is difficult (or impossible, or im just stupid) to initialize each flight in adjlist constructor with the
            same airport object. I think we may want to look at creating a map where each IATA directly corresponds to an airport object.
            
            UPDATE: I implemented a map from IATA to Airport in the adjacency list constructor. This means that each adjacency list obj
            has an easy way to both access IATA from airport and airport from IATA.

            */

        }

    }

    return result;
}


