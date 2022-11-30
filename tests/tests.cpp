#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "adjacency_list.h"
#include "bfs.h"

using namespace std;

TEST_CASE("Sample Data Adjacency List", "[weight=5]") {

    const string filename = "/workspaces/CS 225/flights_project/dataFiles/used_data.csv"; 
    cout << "here" << endl;
    AdjList adj = *(new AdjList(filename));

    for(const auto& k : adj.getMap()){


        cout << k.first << endl;

    }

    REQUIRE(adj.getMap().size() == 6);
    
}

TEST_CASE("Sample Data Airport List", "[weight=5]") {

    const string filename = "/workspaces/CS 225/flights_project/dataFiles/used_data.csv"; 
    cout << "here" << endl;
    AdjList adj = *(new AdjList(filename));

    for(auto& a : adj.getVector()){


        cout << a.getIATA() << endl;

    }

    REQUIRE(adj.getMap().size() == 6);

    adj.printAdjList();
}