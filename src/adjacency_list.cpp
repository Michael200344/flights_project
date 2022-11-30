#include "adjacency_list.h"

AdjList::AdjList(const std::string &filename) {


    std::string filestring = file_to_string(filename); // converting file into usable string format

    std::vector<std::string> lines; // initializing vector to save the result of split string
    int rv = SplitString(filestring, '\n', lines); // splitting filestring by newline so that each line is in its own index of lines
;
}