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

// bool Airport::operator==(const Airport a1){

//     if(this->getIATA() == a1.getIATA()) return true;
//     return false;

// }

std::vector<Flight>* Airport::getFlights() const{

    return &flights_;

}

void Airport::setVisited(){

    visited_ = true;

}

void Airport::setNotVisited(){

    visited_ = false;

}

bool Airport::getVisited() const{

    return visited_;

}

std::string Airport::getIATA() const{

    return IATA_;

}