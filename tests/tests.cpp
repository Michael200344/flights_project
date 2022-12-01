#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "adjacency_list.h"
#include "bfs.h"

using namespace std;

TEST_CASE("USAdata AdjList", "[weight=5]") {

    const string filename = "/workspaces/CS 225/flights_project/dataFiles/usadata.csv"; 
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

TEST_CASE("trimList test") {

    vector<string> inputIATAs;

    inputIATAs.push_back("ORD");
    inputIATAs.push_back("DFW");
    inputIATAs.push_back("LAX");
    inputIATAs.push_back("JFK");
    inputIATAs.push_back("IND");
    inputIATAs.push_back("XXX");

    AdjList* adj = new AdjList("/workspaces/CS 225/flights_project/dataFiles/usadata.csv");

    pair<AdjList*, vector<string>> p;
    p = adj->trimList(inputIATAs);

    for(auto& a : p.first->getVector()){


        cout << a->getIATA() << ": " << endl;

        for(auto& f : a->getFlights()){

            cout << "Src: " << f->getSource() << " Dest: " << f->getDestination() << " Dist: " << f->getDistance() << std::endl;

        }

    }

    REQUIRE(p.first->getList().size() == 5);
    REQUIRE(p.second.size() == 1);

}

TEST_CASE("AdjList Airport Test") {



}

TEST_CASE("BFS Test", "[weight=5]") {

    const string filename = "/workspaces/CS 225/flights_project/dataFiles/usadata.csv"; 
    AdjList adj = *(new AdjList(filename));

    // Airport* test = 

    auto bfs = new BFS(adj);

}