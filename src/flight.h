#pragma once

#include <string>

using namespace std;

class Flight {
    public:
    Flight();
    Flight(string start, string dest, string aline, float dist);

    private:
    string source;
    string destination;
    string airline;
    float distance;

};