#include "adjacency_list.h"

AdjList::AdjList(const std::string &filename) {

    list_.clear();

    std::string filestring = file_to_string(filename); // converting file into usable string format

    std::vector<std::string> lines; // initializing vector to save the result of split string
    int rv = SplitString(filestring, '\n', lines); // splitting filestring by newline so that each line is in its own index of lines

    for(size_t i = 0; i < lines.size(); i++){ // loops through each line in lines vector

        std::vector<std::string> elems;
        int rv2 = SplitString(lines[i], ',', elems); // splits each line by commas, stores result in elems

        Airport *currAirport = new Airport(Trim(elems[0])); // creates a new airport for each IATA - unordered set checks for duplicates
        IATAmap_.insert({Trim(elems[0]), *currAirport}); // links IATA with airport - should resolve time issues later
        Flight *currFlight = new Flight(Trim(elems[0]), Trim(elems[1]), std::stof(Trim(elems[2]))); // new flight with source, dest, and distance as float

        currAirport->getFlights()->push_back(*currFlight); // adds current flight to current airports flights vector

        list_.insert(*currAirport); // inserts airport into adjacency list if it inst there

    }
    
}

std::unordered_set<Airport> AdjList::getList() const{

    return list_;

}

std::unordered_map<std::string, Airport> AdjList::getMap() const{

    return IATAmap_;

}

Airport* AdjList::findAirport(std::string IATA) const{

    for(Airport a : list_){

        if(a.getIATA() == IATA){
            return &a;
        }

    }

    Airport* error = new Airport("XXX"); // if XXX appears, found an airport not in adjlist which should be impossible
    return error;

}