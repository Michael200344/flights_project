#include "airport.h"

Airport::Airport(string iata, vector<Flight> connections) {
    IATA = iata;
    flights = connections;
}