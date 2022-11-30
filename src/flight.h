#pragma once

#include <string>

class Flight {
    public:

        Flight();
        Flight(std::string source, std::string destination, float distance);

        void setType(char t);
        std::string getDestination();
        std::string getSource();

    private:
    
        std::string source_;
        std::string destination_;
        std::string airline_;
        char type_; // will be used in bfs - u = unexplored, d = discovery, c = cross
        float distance_;


};