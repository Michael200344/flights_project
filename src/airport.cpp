#include "airport.h"
#include "flight.h"


// Airport::Airport(){
//     IATA_ = "";
// }

Airport::Airport(const std::string IATA){

    IATA_ = IATA;
    flights_.clear();
    visited_ = false;
    
}

Airport::Airport(const string IATA, const vector<Flight> flights) {
    
    IATA_ = IATA;
    flights_ = flights;
    visited_ = false;

}

std::vector<Flight>* Airport::getFlights(){

    return &flights_;

}

void Airport::setVisited(){

    visited_ = true;

}

void Airport::setNotVisited(){

    visited_ = false;

}

bool Airport::getVisited(){

    return visited_;

}

std::string Airport::getIATA(){

    return IATA_;

}