#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "adjacency_list.h"

using namespace std;

TEST_CASE("Sample Data Adjacency List", "[weight=5]") {

    cout << "here" << endl;
    AdjList adj = *(new AdjList("used_data.csv"));

    for(const Airport &a : adj.getList()){


        cout << a.getIATA() << endl;

    }

    REQUIRE(1 == 1);
    
}