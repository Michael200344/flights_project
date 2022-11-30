#include "bfs.h"


/*
    This BFS function will take in our adjacency list and mark each flight as discovery or cross 
*/

BFS::BFS(AdjList &adjlist){

    auto list = adjlist.getList();
    // Iterator beg = list.begin();

    for(Airport a : list){ // sets each vertex to unvisited

        a.setNotVisited();
        std::vector<Flight*> currFlights = a.getFlights(); // fetches flights for each airport

        for(Flight* f : currFlights){

            f->setType('u'); // sets all flights to unexplored  ***** TIME COMPLEXITY CONCERN?

        }
    }

    for(Airport na : list){

        if(!na.getVisited()){ // if a vertex has not yet been visited, search it - loop ensures even unconnected components are accounted for
            BFS(adjlist, na);
        }

    }

}

BFS::BFS(AdjList &adjlist, Airport start){

    std::queue<Airport> q;
    start.setVisited(); // initializing queue, marking start as visited, and pushing it
    q.push(start);

    while(!q.empty()){ // until every node is visited

        Airport currAirport = q.front(); // fetch current airport
        q.pop();

        std::vector<Flight*> currFlights = currAirport.getFlights();  // gets current flights
        std::map<std::string, Airport*> currMap = adjlist.getMap();

        for(Flight* f : currFlights){

            std::string adjacentIATA = f->getDestination(); // gets adjacent IATA for each flight
            Airport adjacentAirport = *(currMap).at(adjacentIATA); // finds actual airport object

            auto sourceIATA = f->getSource();
            auto sourceAirport = *(currMap).at(sourceIATA); // get source IATA and use it to find airport

            if(!adjacentAirport.getVisited()){ // if adjacent airport isnt visited

                f->setType('d');
                adjacentAirport.setVisited(); // set discovery edge and graph visited
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

}


