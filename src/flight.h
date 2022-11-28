#pragma once

#include <string>

using namespace std;

class Flight {
    public:
    Flight();
    Flight(string source, string destination,float distance);

    private:
    string source_;
    string destination_;
    string airline_;
    float distance_;


};