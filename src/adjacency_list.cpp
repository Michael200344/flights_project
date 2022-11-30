#include "adjacency_list.h"
#include <unordered_set>

// struct AirportEqual {
//     bool operator()(const Airport & a1, const Airport & a2) {
//         if (a1.getIATA() == a2.getIATA())
//             return true;
//         else
//             return false;
//     }
// };

AdjList::AdjList(const std::string &filename) {

    // list_.clear();

    vector_.clear();
    std::vector<std::string> elems;

    std::string filestring = file_to_string(filename); // converting file into usable string format

    std::vector<std::string> lines; // initializing vector to save the result of split string
    int rv = SplitString(filestring, "\r\n", lines); // splitting filestring by newline so that each line is in its own index of lines
    // for (std::string line : lines) {
    //     line.erase(line.end() - 2, line.end());
    // }
    for(size_t i = 1; i < lines.size(); i++){ // loops through each line in lines vector

        
        elems.clear();
        int rv2 = SplitString(lines[i], ',', elems); // splits each line by commas, stores result in elems
        if (elems.size() == 4) {
            if(IATAlist_.count(Trim(elems[1])) == 0){

                // std::cout << "fjdjdalf" << std::endl;

                IATAlist_.insert(Trim(elems[1]));
                Airport* currAirport = new Airport(Trim(elems[1])); // creates a new airport for each IATA - unordered set checks for duplicates
                // IATAmap_.insert({Trim(elems[0]), *currAirport}); // links IATA with airport - should resolve time issues later
                IATAmap_.insert(std::pair<std::string, Airport*>(Trim(elems[1]), currAirport));
                // list_.insert(*currAirport);
                vector_.push_back(currAirport);

            }
        
            // std::cout << currAirport << " in map - > " << IATAmap_[Trim(elems[0])] << std::endl;
            
            // Flight *currFlight = new Flight(Trim(elems[0]), Trim(elems[1]), std::stof(Trim(elems[2]))); // new flight with source, dest, and distance as float

            IATAmap_[Trim(elems[1])]->setFlights(new Flight(Trim(elems[1]), Trim(elems[2]), std::stof(Trim(elems[3])))); // adds current flight to current airports flights vector
        }
    }
    int joe = 0;
    for (const auto& k : IATAmap_) {
        // Hello
    }
}

std::set<Airport> AdjList::getList() const{

    return list_;

}

std::map<std::string, Airport*> AdjList::getMap() const{

    return IATAmap_;

}

std::vector<Airport*> AdjList::getVector() const{

    return vector_;

}

Airport AdjList::findAirport(std::string IATA) const{

    for(Airport a : list_){

        if(a.getIATA() == IATA){
            return a;
        }

    }

    Airport* error = new Airport("XXX"); // if XXX appears, found an airport not in adjlist which should be impossible
    return *error;

}

void AdjList::printAdjList(){ //function to loop and print new csv with new type, time concerns?

    
    for(Airport* a : vector_){

        std::cout << a->getIATA() << ": " << std::endl;
        std::vector<Flight*> currFlights = a->flights_;

        for(Flight* f : currFlights){

            std::cout << f->getSource() << ", " << f->getDestination() << ", " << f->getDistance() << std::endl;

        }

    }

}