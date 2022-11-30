#include "airport.h"
#include "stdio.h"


// Airport::Airport(){
//     IATA_ = "";
// }

Airport::Airport(std::string IATA){

    IATA_ = IATA;
    flights_.clear();
    visited_ = false;
    
}

// Airport::Airport(const string IATA, const vector<Flight*> flights) {
    
//     IATA_ = IATA;
//     flights_ = flights; // deep copy vector
//     visited_ = false;

// }

// bool Airport::operator==(const Airport a1){

//     if(this->getIATA() == a1.getIATA()) return true;
//     return false;

// }

bool operator<(const Airport a1, const Airport a2){

    return a1.getIATA()[0] < a2.getIATA()[0];

}

// Airport Airport::operator()(const Airport a1, const Airport a2){
//     return a1;
// }

std::vector<Flight*>& Airport::getFlights() {

    return flights_;

}

void Airport::setFlights(Flight* f){

    flights_.push_back(f);

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

bool Airport::isFlight(Airport a, Airport b) {
    for (const auto& flight : a.flights_) {
        if (flight->getDestination() == b.IATA_) {
            return true;
        }
    }
    return false;
}
