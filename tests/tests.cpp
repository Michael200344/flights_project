#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "adjacency_list.h"

using namespace std;

TEST_CASE("Sample Data Adjacency List", "[weight=5]") {

    const string filename = "/workspaces/CS225/flights_project/dataFiles/usadata.csv";
    cout << "here" << endl;
    AdjList adj = *(new AdjList(filename));

    for(const auto& k : adj.getMap()){


        cout << k.first << endl;

    }

    REQUIRE(adj.getMap().size() == 6);
    
}