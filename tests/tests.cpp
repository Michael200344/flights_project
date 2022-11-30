#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "bfs.h"

using namespace std;

// TEST_CASE("Sample Data Adjacency List", "[weight=5]") {

//     const string filename = "/workspaces/CS 225/flights_project/dataFiles/used_data.csv"; 
//     cout << "here" << endl;
//     AdjList adj = *(new AdjList(filename));

//     for(const auto& k : adj.getMap()){


//         cout << k.first << endl;

//     }

//     REQUIRE(adj.getMap().size() == 6);
    
// }

TEST_CASE("USAdata AdjList", "[weight=5]") {

    const string filename = "/workspaces/CS225/flights_project/dataFiles/usadata.csv"; 
    cout << "here" << endl;
    AdjList adj = *(new AdjList(filename));

    for(auto& a : adj.getVector()){


        cout << a->getIATA() << ": " << endl;

        for(auto& f : a->getFlights()){

            cout << "Src: " << f->getSource() << " Dest: " << f->getDestination() << " Dist: " << f->getDistance() << std::endl;

        }

    }

    REQUIRE(adj.getMap().size() == 35);

    // adj.printAdjList();
}

TEST_CASE("AdjList Airport Test") {



}

TEST_CASE("BFS Test Level 1", "[weight=5]") {

    const string filename = "/workspaces/CS225/flights_project/dataFiles/usadata.csv"; 
    AdjList adj = *(new AdjList(filename));

}