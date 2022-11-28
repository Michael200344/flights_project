#include "airport.h"


Airport::Airport(){
    IATA_ = "";
}

Airport::Airport(string iata, vector<Flight> connections) {
    IATA = iata;
    flights = connections;
}