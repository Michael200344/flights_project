#include "flight.h"

Flight::Flight(){

    type_ = 'u';

}

Flight::Flight(const std::string source, const std::string destination, const float distance){

    source_ = source;
    destination_ = destination;
    distance_ = distance;

}

void Flight::setType(char t){

    type_ = t;

}

std::string Flight::getDestination(){

    return destination_;

}

std::string Flight::getSource(){

    return source_;

}

float Flight::getDistance(){

    return distance_;

}

char Flight::getType(){

    return type_;

}