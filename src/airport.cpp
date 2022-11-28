#include "airport.h"

Airport::Airport(){
    IATA_ = "";
}

Airport::Airport(const std::string IATA){
    IATA_ = IATA;
}