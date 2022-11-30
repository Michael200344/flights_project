#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "adjacency_list.h"
#include "utils.h"

using namespace std;

TEST_CASE("Sample Data Adjacency List", "[weight=5]") {

    const string filename = "/workspaces/CS225/flights_project/dataFiles/used_data.csv";
    cout << "here" << endl;

    ifstream myfile;
    myfile.open("used_data.csv");

    AdjList adj = *(new AdjList("used_data.csv"));
    AdjList adj = *(new AdjList(filename));

    for(const auto& k : adj.getMap()){


        cout << k.first << endl;

    }

    myfile.close();

    REQUIRE(1 == 1);
}

TEST_CASE("tostring test") {

    cout << file_to_string("test_out.csv");

    REQUIRE(adj.getMap().size() == 6);
    
}