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
* lib: This folder contains all the code used to make the graph and execute the algorithms. The airport.h and airport.cpp files store the code used to make an ariport object which stores the airport IATA code and a vector of all the flights from that airport. Flights.h and flights.cpp cointain the code for the flight object which stores the source and destination airport, the airline and the distance between the airport. The adjacency_list.h and adjacency_list.cpp use the 2 objects creates to make a weighted directed graph using adjecency lists.
* src
* tests
* Project_Proposal.md
* Team_Contract.md
* dataprocessing.py
* results.md













# How to use our program?

To download our program, please copy and paste this line to your terminal:

```
git clone https://github-dev.cs.illinois.edu/cs225-fa20/chienhn2-lbn2-jamestp3-ruscito2.git
```

### First you will need to edit input:

Open **input.txt**, enter **IATA codes** of desired airports (3-letter codes ex. Chicago Midway -> MDW).
Capitalization does not matter, and invalid airports will be filtered by program.
Each code must be on its own line in input.txt

1. To change starting airport for BFS, enter IATA code at top of **input.txt** file
(location is noted in file and these instructions are also seen in file)

2. To change airports for shortest path algorithms:

Each test case must have 3 airports, in following order:
Starting location;
Destination location;
Landmark location;

### Second to build the program, you need to run:
```make
make
```
in the terminal.

The makefile will create a executable file which is named 'flight'
Run this command in the terminal: 
```flight
./flight
```

Your results will export automatically in terminal window or you can open the **output.txt** file which is located in your root folder.

### Example about the results:
![GitHub Logo](/images/example.png)

### OUTPUT.TXT
![GitHub Logo](/images/output.png)
