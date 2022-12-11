# CS225 Final Project - Open Flights

## Group members:
* Jacob Poeschel - jacobop2 
* Michael Rheintgen - mar13 
* Dirgh Shah - dirghvs2 
* Branden Kooper - bkooper2

## Deliverables (Loaction - Main Branch):
* [Written Report](https://github.com/Michael200344/flights_project/blob/main/results.md)
* [Final Presentation Video]()
* [Final Presentation Slides]()

## Project Overview:
Our program uses data from [Open Flights](https://openflights.org/data.html) to find the shortest path between two airports by using BFS Traversal and Dijkstra's Algorithm.

## Github Organization:

The files and folders that can be found in the main branch are:
* build: This folder cointing files required to build and run the program.
* dataFiles: This folder cointains all the raw data (airportsData.txt, airports_processed.csv, distance_data.csv, routesData.txt, routes_processed.csv), the sample test data (used_data.csv) and the processed data containg all the flights in the US including distances between each airport (usadata.csv).
* entry: This folder contains the main.cpp file which is executed to run the program.
* lib:
* src: This folder contains all the code used to make the graph and execute the algorithms. The airport.h and airport.cpp files store the code used to make an ariport object which stores the airport IATA code and a vector of all the flights from that airport. Flights.h and flights.cpp cointain the code for the flight object which stores the source and destination airport, the airline and the distance between the airport. The adjacency_list.h and adjacency_list.cpp use the 2 objects creates to make a weighted directed graph using adjecency lists. The utils files were taken from the last CS225 MP whse functions were used to read data from a csv file.
* tests: This coints the test file with all the tests used to test if our programs work.
* Project_Proposal.md: Our groups project proposal.
* Team_Contract.md: Our groups team contract.
* dataprocessing.py: The python code whihc was used to process and clean the raw data.
* results.md: The final written report.

## Running Instructions

To download our program, please copy and paste this line to your terminal:

```
git clone https://github.com/Michael200344/flights_project.git
```

### First you will need to edit the code:
Open the tests.cpp file in the tests folder. In that file, you will need to change the file path and add the appropriate file path. This can be done by right clicking on the usadata.csv and copying the path. This path should replace the path in line 8 of the code in the brackets - 
```
AdjList* USAadj = new AdjList("insert file path here");
```


### Second to build the program:

First you need to delete the existing build directory and then run
```
mkdir build
cd build
cmake ..
make
```
in the terminal.

Then to test the program you need to run the tests.cpp file which can me done by inputting this in your terminal:
```
./test
```

Your results will export automatically in terminal window.

## Results Example:

