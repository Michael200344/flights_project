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

TEST_CASE("AdjList Duplicate Flights Test") {

    std::string test = "ORD";
    Airport* testA = USAadj->getMap()["ORD"];

    for(auto &f : testA->getFlights()){

        std::cout << f->getDestination() << ", ";

    }
    std::cout << std::endl;

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

TEST_CASE("generateSample Size Test") {

    size_t n = rand() % 15 + 1;
    AdjList* rList = USAadj->generateSample(n);

    REQUIRE(rList->getVector().size() == n);
    REQUIRE(rList->getList().size() == n);

}

TEST_CASE("generateSample Trim Test") {

    size_t n = rand() % 15 + 1;
    AdjList* rList = USAadj->generateSample(n);

    for(auto &a : rList->getVector()){

        for(auto &f : a->getFlights()){

            REQUIRE(rList->getList().count(f->getDestination()) == 1);

        }

    }

}

TEST_CASE("BFS Visited Test USA") {

    Airport* test = USAadj->getMap()["ORD"];
    auto result = BFS(*USAadj, test);

    for(Airport* a : USAadj->getVector()){

        std::cout << a->getIATA() << " " << a->getVisited() << std::endl;
        REQUIRE(a->getVisited() == 1);

    }

}

TEST_CASE("BFS Flights Test USA") {

    Airport* test = USAadj->getMap()["ORD"];
    auto result = BFS(*USAadj, test);

    for(auto &f : test->getFlights()){

        std::cout << f->getType() << std::endl;
        // REQUIRE(f->getType() == 'c' || f->getType() == 'd');

    }

}

TEST_CASE("BFS Result Test USA") {

    Airport* test = USAadj->getMap()["ORD"];
    auto result = BFS(*USAadj, test);

    for(auto &a : result){

        std::cout << a->getIATA() << ", ";

    }

    std::cout << std::endl;

}

TEST_CASE("BFS Flights Test Small") {

    AdjList* sample = USAadj->generateSample(5);
    int start = rand()%5;
    Airport* beg = sample->getVector()[start];

    auto result = BFS(*sample, beg);

    for(auto &a : sample->getVector()){

        std::cout << a->getIATA() << ": ";
        // REQUIRE(a->getVisited() == true);

        for(auto &f : a->getFlights()){

            std::cout << "(" << f->getDestination() << ", " << f->getType() << ") ";
            // REQUIRE(f->getType() == 'c' || f->getType() == 'd');

        }
        std::cout << std::endl;

    }

    std::cout << "VISITED AIRPORTS: ";
    for(auto &a : result){

        std::cout << a->getIATA() << ", ";

    }
}

TEST_CASE("BFS Test From Trimmed USA") {

    vector<string> inputIATAs;

    inputIATAs.push_back("ORD");
    inputIATAs.push_back("DFW");
    inputIATAs.push_back("LAX");
    inputIATAs.push_back("JFK");
    inputIATAs.push_back("IND");
    inputIATAs.push_back("XXX");

    pair<AdjList*, vector<string>> p;
    p = USAadj->trimList(inputIATAs);
    std::string test = "ORD";

    std::vector<Airport*> result = BFS(*p.first, test);

    for(auto &a : p.first->getVector()){

        std::cout << a->getIATA() << ": ";
        // REQUIRE(a->getVisited() == true);

        for(auto &f : a->getFlights()){

            std::cout << "(" << f->getDestination() << ", " << f->getType() << ") ";
            // REQUIRE(f->getType() == 'c' || f->getType() == 'd');

        }
        std::cout << std::endl;

    }

    std::cout << "VISITED AIRPORTS: ";
    for(auto &a : result){

        std::cout << a->getIATA() << ", ";

    }

}