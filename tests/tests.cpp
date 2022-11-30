#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "adjacency_list.h"
#include "utils.h"

using namespace std;

TEST_CASE("Sample Data Adjacency List", "[weight=5]") {

    cout << "here" << endl;

    ifstream myfile;
    myfile.open("used_data.csv");

    AdjList adj = *(new AdjList("used_data.csv"));

    for(const Airport &a : adj.getList()){


        cout << a.getIATA() << endl;

    }

    myfile.close();

    REQUIRE(1 == 1);
}

TEST_CASE("tostring test") {

    cout << file_to_string("test_out.csv");

}