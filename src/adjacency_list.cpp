#include "adjacency_list.h"

AdjList::AdjList(){}

AdjList::AdjList(const std::string &filename){

    std::string filestring = file_to_string(filename); // converting file into usable string format

    std::vector<std::string> lines; // initializing vector to save the result of split string
    int rv = SplitString(filestring, '/n', lines); // splitting filestring by newline so that each line is in its own index of lines

    for(size_t i = 0; i < lines.size(); i++){ // loops through each line in lines vector

        std::vector<std::string> elems;
        int rv2 = SplitString(lines[i], ',', elems); // splits each line by commas, stores result in elems

        Airport *currAirport = new Airport(Trim(elems[0])); // creates a new airport for each IATA - unordered set checks for duplicates
        Flight *currFlight = new Flight(Trim(elems[0]), Trim(elems[1]), std::stof(Trim(elems[2]))); // new flight with source, dest, and distance as float

        currAirport->flights_.push_back(*currFlight); // adds current flight to current airports flights vector

        list.insert(*currAirport); // inserts airport into adjacency list if it inst there

    }
    

}