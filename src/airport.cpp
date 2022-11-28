#include "airport.h"


Airport::Airport(){
    IATA_ = "";
}

Airport::Airport(string IATA, vector<Flight> flights) {
    IATA_ = IATA;
    flights_ = flights;
}