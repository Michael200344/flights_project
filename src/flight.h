#pragma once

#include <string>

class Flight {
    public:
        Flight(const std::string source, const std::string destination, const float distance);   


    private:
        std::string source_;
        std::string destination_;
        std::string airline_;
        float distance_;

};