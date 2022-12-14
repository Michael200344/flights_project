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

AdjList::AdjList() {

    IATAlist_.clear();
    IATAmap_.clear();
    vector_.clear();

}

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

            std::string source = Trim(elems[1]);
            if(IATAlist_.count(Trim(elems[1])) == 0){

                IATAlist_.insert(source);
                Airport* currAirport = new Airport(source); // creates a new airport for each IATA - unordered set checks for duplicates
                IATAmap_.insert(std::pair<std::string, Airport*>(source, currAirport));
                vector_.push_back(currAirport);

            }

            std::vector<Flight*> currF = IATAmap_[source]->getFlights();
            bool shouldAdd = true;
            for(Flight* f : currF){

                if(f->getDestination() == Trim(elems[2])){
                    shouldAdd = false;
                    break;
                }

            }
            if(shouldAdd)
                IATAmap_[Trim(elems[1])]->setFlights(new Flight(source, Trim(elems[2]), std::stof(Trim(elems[3])))); // adds current flight to current airports flights vector
        }
    }
}

std::set<std::string> AdjList::getList() const{

    return IATAlist_;

}

std::map<std::string, Airport*> AdjList::getMap() const{

    return IATAmap_;

}

std::vector<Airport*> AdjList::getVector() const{

    return vector_;

}

// Airport AdjList::findAirport(std::string IATA) const{

//     for(Airport a : list_){

//         if(a.getIATA() == IATA){
//             return a;
//         }

//     }

//     Airport* error = new Airport("XXX"); // if XXX appears, found an airport not in adjlist which should be impossible
//     return *error;

// }

void AdjList::printAdjList(){ //function to loop and print new csv with new type, time concerns?

    
    for(Airport* a : vector_){

        std::cout << a->getIATA() << ": " << std::endl;
        std::vector<Flight*> currFlights = a->flights_;

        for(Flight* f : currFlights){

            std::cout << f->getSource() << ", " << f->getDestination() << ", " << f->getDistance() << std::endl;

        }

    }

}

std::pair<AdjList*, std::vector<std::string>> AdjList::trimList(std::vector<string> IATAlist) { // takes us list and shortens it to user input

    // if(IATAlist.empty()) return std::pair<AdjList*, std::vector<std::string>>(NULL, NULL);

    AdjList* rList = new AdjList(); // to add values to eventually create the return adjacency list
    std::vector<std::string> invalList; // to keep track of invalid user IATAs

    for(const auto& s : IATAlist) {

        if(searchMap(s) != NULL) {

            rList->vector_.push_back(searchMap(s));
            rList->IATAlist_.insert(s);
            rList->IATAmap_.insert(std::pair<std::string, Airport*>(s, searchMap(s)));

        }
        else invalList.push_back(s);

    }

    for(Airport* a : rList->getVector()){ // trims flight list

        std::vector<Flight*> tempF;
        std::vector<Flight*> currF = a->getFlights();

        for(auto &f : currF){

            if(rList->getList().count(f->getDestination()) == 1){
                tempF.push_back(f);
            }

        }

        a->replaceFlights(tempF);

    }

    return std::pair<AdjList*, std::vector<std::string>>(rList, invalList);

}

Airport* AdjList::searchMap(std::string IATA) {

    if(IATAmap_.find(IATA) != IATAmap_.end()) return IATAmap_[IATA]; // does find have a condition for empty maps? otherwise must add
    return NULL;

}

AdjList* AdjList::generateSample(size_t n) { // pass in large set, generate n random airports from the set

    if(n == 0) return nullptr;

    size_t range = vector_.size();

    AdjList* rList = new AdjList();

    while(n > 0){

        int idx = std::rand() % range;
        std::string currIATA = vector_[idx]->getIATA();

        if(rList->searchMap(currIATA) == NULL) {

            rList->vector_.push_back(searchMap(currIATA));
            rList->IATAlist_.insert(currIATA);
            rList->IATAmap_.insert(std::pair<std::string, Airport*>(currIATA, searchMap(currIATA)));

        }
        else n++; // if the airport is alreayd in rList, duplicate, so must subtract n until unique found

        n--;
    }

    for(Airport* a : rList->getVector()){ // trims flight list

        std::vector<Flight*> tempF;
        std::vector<Flight*> currF = a->getFlights();

        for(auto &f : currF){

            if(rList->getList().count(f->getDestination()) == 1){
                tempF.push_back(f);
            }

        }

        a->replaceFlights(tempF);

    }


    return rList;

}