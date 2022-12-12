#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "adjacency_list.h"
#include "bfs.h"
#include "iddfs.h"
#include "dijkstra.h"

using namespace std;

AdjList* USAadj = new AdjList("/workspaces/CS225/flights_project/dataFiles/usadata.csv");

//Dijkstra Tests

TEST_CASE("Dijkstra Test USA") {

    // 4B,LAS,LAX,379.9942734236406
    // 4B,LAX,LAS,379.9942734236406

    Airport* start = USAadj->getMap()["LAX"];
    Airport* dest = USAadj->getMap()["LAS"];

    auto result = Dijkstras(*USAadj, start, dest);

    std::cout << "Total dist: " << result.second << std::endl;
    REQUIRE((int)result.second == 379);
    std::cout << "Airports Used To Reach Dest " << '\n';
    for(auto &f : result.first) {
        std::cout << f->getIATA() << " ";
    }
    std::cout << std::endl;

}

TEST_CASE("Dijkstra Test USA 2") {

    Airport* start = USAadj->getMap()["ORD"];
    Airport* dest = USAadj->getMap()["PDX"];

    auto result = Dijkstras(*USAadj, start, dest);

    std::cout << "Total dist: " << result.second << std::endl;
    REQUIRE((int)result.second == 2791);
    std::cout << "Airports Used To Reach Dest " << '\n';
    for(auto &f : result.first) {

        std::cout << f->getIATA() << " ";

    }
    std::cout << std::endl;
}

TEST_CASE("Dijkstra Test USA 3") {

    Airport* start = USAadj->getMap()["LAX"];
    Airport* dest = USAadj->getMap()["CVG"];

    auto result = Dijkstras(*USAadj, start, dest);

    std::cout << "Total dist: " << result.second << std::endl;
    REQUIRE((int)result.second == 3050);
    std::cout << "Airports Used To Reach Dest " << '\n';

    for(auto &f : result.first) {

        std::cout << f->getIATA() << " ";

    }
    std::cout << std::endl;
}

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

TEST_CASE("Ohare AdjList Test") {

    Airport* ohare = USAadj->searchMap("ORD");

    std::cout << "ORD: " << std::endl;

    for(Flight* f : ohare->getFlights()){
        std::cout << f->getDestination() << ", " << f->getDistance() << std::endl;
    } 

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

    for(auto& a : USAadj->getVector()){

        cout << a->getIATA() << ": " << endl;

        for(auto& f : a->getFlights()){

            cout << "Src: " << f->getSource() << " Dest: " << f->getDestination() << " Dist: " << f->getDistance() << std::endl;

        }

    }


    REQUIRE(USAadj->getMap().size() == 35);

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
        // REQUIRE(a->getVisited() == 1);

    }
    std::cout << std::endl;

}

TEST_CASE("BFS Flights Test USA") {

    Airport* test = USAadj->getMap()["ORD"];
    auto result = BFS(*USAadj, test);

    for(auto &f : test->getFlights()){

        std::cout << f->getType() << std::endl;
        // REQUIRE(f->getType() == 'c' || f->getType() == 'd');

    }
    std::cout << std::endl;

}

TEST_CASE("BFS Result Test USA") {

    Airport* test = USAadj->getMap()["ORD"];
    auto result = BFS(*USAadj, test);

    for(auto &a : result){

        std::cout << a->getIATA() << ", ";

    }

    std::cout << std::endl;

}

TEST_CASE("Ohare AdjList Test") {

    Airport* ohare = USAadj->searchMap("ORD");

    std::cout << "ORD: " << std::endl;

    for(Flight* f : ohare->getFlights()){
        std::cout << f->getDestination() << ", " << f->getDistance() << std::endl;
    } 

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
        // REQUIRE(a->getVisited() == 1);

    }
    std::cout << std::endl;

}

TEST_CASE("BFS Flights Test USA") {

    Airport* test = USAadj->getMap()["ORD"];
    auto result = BFS(*USAadj, test);

    for(auto &f : test->getFlights()){

        std::cout << f->getType() << std::endl;
        // REQUIRE(f->getType() == 'c' || f->getType() == 'd');

    }
    std::cout << std::endl;

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
    std::cout << "Starting Airport: " << beg -> getIATA() << std::endl;

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
    std::cout << std::endl;
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

TEST_CASE("BFS Flights Test Small") {

    AdjList* sample = USAadj->generateSample(5);
    int start = rand()%5;
    Airport* beg = sample->getVector()[start];
    std::cout << "Starting Airport: " << beg -> getIATA() << std::endl;

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
    std::cout << std::endl;
}

// TEST_CASE("iddfs Flights Test Small") {
//     AdjList* sample = USAadj->generateSample(5);
//     int startIdx = rand()%5;
//     int targetIdx = rand()%5;
//     Airport* start = sample -> getVector().at(startIdx);
//     Airport* target = sample -> getVector().at(targetIdx);
//     int x = 3;
//     auto result = iddfs(start, target, x, *sample);

//     for(auto &a : sample->getVector()){

//         std::cout << a->getIATA() << ": ";
//         // REQUIRE(a->getVisited() == true);

//         for(auto &f : a->getFlights()){

//             std::cout << f->getDestination() << " ";
//             // REQUIRE(f->getType() == 'c' || f->getType() == 'd');

//         }
//         std::cout << std::endl;
//     }

//     if (!result.empty()) {
//         std::cout << "It is possible to reach " << target -> getIATA() << " from " << start -> getIATA() << " In " << x << " Flights. The corresponding flight path is below" << std::endl;
//     } else {
//         std::cout << "It is not possible to reach " << target -> getIATA() << " from " << start -> getIATA() << " In " << x << " Flights." << std::endl;
//     }

//     std::cout << "FLIGHT PATH: ";
//     for(auto &a : result){
//         std::cout << a->getIATA() << ", ";
//     }
// }

TEST_CASE("iddfs Flights Test USA") {
    int startIdx = rand() % USAadj -> getVector().size();
    int targetIdx = rand() % USAadj -> getVector().size();
    Airport* start = USAadj -> getVector().at(startIdx);
    Airport* target = USAadj -> getVector().at(targetIdx);
    int x = 2;
    auto result = iddfs(start, target, x, *USAadj);

    // for (const auto& k : USAadj -> getMap()) {
    //     std::cout << k.first << ": " << k.second -> getIATA() << std::endl;
    // }

    for(auto &a : USAadj->getVector()){

        std::cout << a->getIATA() << ": ";
        // REQUIRE(a->getVisited() == true);

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

// TEST_CASE("iddfs Flights Test Small") {
//     AdjList* sample = USAadj->generateSample(5);
//     int startIdx = rand()%5;
//     int targetIdx = rand()%5;
//     Airport* start = sample -> getVector().at(startIdx);
//     Airport* target = sample -> getVector().at(targetIdx);
//     int x = 3;
//     auto result = iddfs(start, target, x, *sample);

//     for(auto &a : sample->getVector()){

//         std::cout << a->getIATA() << ": ";
//         // REQUIRE(a->getVisited() == true);

//         for(auto &f : a->getFlights()){

//             std::cout << f->getDestination() << " ";
//             // REQUIRE(f->getType() == 'c' || f->getType() == 'd');

//         }
//         std::cout << std::endl;
//     }

//     if (!result.empty()) {
//         std::cout << "It is possible to reach " << target -> getIATA() << " from " << start -> getIATA() << " In " << x << " Flights. The corresponding flight path is below" << std::endl;
//     } else {
//         std::cout << "It is not possible to reach " << target -> getIATA() << " from " << start -> getIATA() << " In " << x << " Flights." << std::endl;
//     }

//     std::cout << "FLIGHT PATH: ";
//     for(auto &a : result){
//         std::cout << a->getIATA() << ", ";
//     }
// }

TEST_CASE("iddfs Flights Test USA") {
    int startIdx = rand() % USAadj -> getVector().size();
    int targetIdx = rand() % USAadj -> getVector().size();
    Airport* start = USAadj -> getVector().at(startIdx);
    Airport* target = USAadj -> getVector().at(targetIdx);
    int x = 2;
    auto result = iddfs(start, target, x, *USAadj);

    // for (const auto& k : USAadj -> getMap()) {
    //     std::cout << k.first << ": " << k.second -> getIATA() << std::endl;
    // }

    for(auto &a : USAadj->getVector()){

        std::cout << a->getIATA() << ": ";
        // REQUIRE(a->getVisited() == true);

        for(auto &f : a->getFlights()){

            std::cout << f->getDestination() << " ";
            // REQUIRE(f->getType() == 'c' || f->getType() == 'd');

        }
        std::cout << std::endl;
    }

    if (result) {
        std::cout << "It is possible to reach " << target -> getIATA() << " from " << start -> getIATA() << " In " << getNumFlightsRequired() << " Flights." << std::endl;
    } else {
        std::cout << "It is not possible to reach " << target -> getIATA() << " from " << start -> getIATA() << " In " << x << " Flights." << std::endl;
    }

    std::cout << "IIDS SCAN PATH: ";
    for(auto &a : getOrder()){
        std::cout << a->getIATA() << ", ";
    }
}
}