#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "adjacency_list.h"
#include "bfs.h"

using namespace std;

AdjList* USAadj = new AdjList("/workspaces/CS 225/flights_project/dataFiles/usadata.csv");

TEST_CASE("USAdata AdjList Test") {

    for(auto& a : USAadj->getVector()){


        cout << a->getIATA() << ": " << endl;

        for(auto& f : a->getFlights()){

            cout << "Src: " << f->getSource() << " Dest: " << f->getDestination() << " Dist: " << f->getDistance() << std::endl;

        }

    }

    REQUIRE(USAadj->getMap().size() == 35);

    // adj.printAdjList();
}

TEST_CASE("trimList Test NULL") {

    vector<string> inputIATAs;
    inputIATAs.clear();

    pair<AdjList*, vector<string>> p;
    p = USAadj->trimList(inputIATAs);

    REQUIRE(p.first->getVector().empty());

}

TEST_CASE("trimList Test") {

    vector<string> inputIATAs;

    inputIATAs.push_back("ORD");
    inputIATAs.push_back("DFW");
    inputIATAs.push_back("LAX");
    inputIATAs.push_back("JFK");
    inputIATAs.push_back("IND");
    inputIATAs.push_back("XXX");

    pair<AdjList*, vector<string>> p;
    p = USAadj->trimList(inputIATAs);

    for(auto& a : p.first->getVector()){


        cout << a->getIATA() << ": " << endl;

        for(auto& f : a->getFlights()){

            cout << "Src: " << f->getSource() << " Dest: " << f->getDestination() << " Dist: " << f->getDistance() << std::endl;

        }

    }

    REQUIRE(p.first->getList().size() == 5);
    REQUIRE(p.second.size() == 1);

}

TEST_CASE("generateSample Test") {

    size_t n = rand() % 15 + 1;

    AdjList* rList = USAadj->generateSample(n);

    REQUIRE(rList->getVector().size() == n);
    REQUIRE(rList->getList().size() == n);

}


// TEST_CASE("BFS Test") {

//     // Airport* test = 

//     auto bfs = new BFS(USAadj);

// }