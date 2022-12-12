CS 225 Final Project: Open Flights
By: Dirgh Shah, Jacob Poeschel, Michael Rheintgen, Branden Kooper

Project Objective:
For the CS 225 final project, our group decided to analyze the dataset of airports and flight routes in the United States by creating a graph structure and implementing BFS and Dijkstra's algorithm to find and return the most efficient route between 2 chosen airports.


Data Processing:
The first step was to collect and clean the data. We obtained airports and flight routes data from https://openflights.org/data.html. The data which we downloaded from openflights.org contained information about 67663 routes between 3321 airports on 548 airlines. To implement the graph structure, we needed the location of each airport (latitude and longitude coordinates), the source and destination airport IATA codes and the 2 letter airline IATA codes. To get this information, we first opened the sirports and routes csv file in python as a pandas dataframe and merged bthem. Then we filtered out any duplicate data points and any data with NULL or missing IATA codes. The next step was to drop the unnecessary data columns like the callsign, callshare information, equipment and airline alias. We then filtered out and retained only the flight routes between US airports. After cleaning the data, we used Haversine's formula to calculte the distance between source and destination airport with the given latitude and longitude information and added it as a seperate column. We then exported the dataframe into a csv which was later used as the source data to create a graph in C++. The final data csv file cointained 4 columns: Airline IATA, Source Airport IATA, Destination Airport IATA and Distance (km).

Graph Building:

Algorithms

Adjacency List Algorithms:
NOTE: Each adjacency list (adjlist) contains 3 items. A set of string airport codes (IATAs), a vector of Airport*s, and a map that maps the IATA to its
respective airport. Each airport contains a string IATA, and a vector of Flight*s. Each Flight contains a source IATA, destination IATA, and distance.

1) Adjlist Constructor (INPUT: csv) (OUTPUT: Adjlist object)
  This constructor takes a csv file and creates an adjlist with the three member items described above. First, this file is transformed into a string, and each
  line is read. Each line contains source, destination, and distance, which is what defines a Flight object. If the source airport is new, a new Airport object
  is created, and each flight with said Airport as a source is added to that airport's vector of flights. Each flight is also checked for duplicacy before it is
  added.
  
  This algorithm has been tested by creating an adjacency list out of our USA data and printing it which displays all airports and flights. Additionally, the size
  of the list is checked.
  
2) AdjList::printAdjList (INPUT: none) (OUTPUT: printed list)
  This algorithm loops through each airport in adjlist.vector and then through each flight in airport.flights and prints each flight.
  
3) AdjList::trimList (INPUT: IATA list) (OUTPUT: pair of AdjList* and vector of invalid IATAs)
  This algorithm takes a user input vector of IATAs and trims the USA data list to only include these values. If an invalid IATA is found it is added to the vector
  of invalid IATAs and returned. This function works by overwriting the flight vector of each airport to only include the flights to the new airport list. 
  
  This algorithm has a null test and a test where the user can change the input IATAs. In both cases, the trimmed vector is printed and is properly displayed.
  
4) AdjList::searchMap (INPUT: IATA) (OUTPUT: Airport*)
  Searches the given adjlist map for an input IATA. Returns the airport if found and otherwise NULL.
  
  The functionality of this algorithm is proven by the trimList tests, as searchMap is used frequently in that function.
  
5) AdjList::generateSample (INPUT: int n) (OUTPUT: Sample list)
  This algorithm takes an int n and generates a new adjlist with n random airports from the USA adj. 
  
  This algorithm is tested to guarantee that the size of the resulting list = n, and printed for visual confirmation.
  
BFS Algorithms:
1) BFS (INPUT: AdjList, IATA) (OUTPUT: vector of airports visited)
  This algorithm is a helper for the main BFS (2). It takes an IATA and uses the adjmap to get the proper airport starting point, and then passes both to the main
  function.
  
2) BFS (INPUT: AdjList, Airport*) (OUTPUT: vector of airports visited)
  Standard BFS algorithm. Uses a queue to keep track of the order that airports should be visited. Every time that an airport is visited, it is added to the vector
  which is returned. As the function loops through every airport, every flight is also checked and marked as either a discovery or cross edge. 
  
  First, BFS is tested on the USA AdjList. The size is checked and each flight is checked to make sure none are still type 'u' unexplored. Then, each IATA is printed
  from the results to show that each airport is visited. Then, BFS is tested with a random sample of user chosen size n using generate sample. The result of this
  is also printed for visual confirmation that edges are marked. **NOTE** It is possible that some airports are not visited. When generating a small sample, it is
  possible that some airports aren't all connected, which is normal. Finally, the same test is done with the user decided trimmed list. All of these tests display
  the expected edges and visited vertices.


IDDFS Algorithm:
 1) IDDFS means Iterative deepening depth first search. The function signature of this search is: bool iddfs(Airport* start, Airport* target, int x, AdjList& adjList) The function of our IDDFS algorithm is described as: a function that takes in a starting airport, destination airport, the number of maximum desired flights, and an adjacency list representation of airports from the user. With this information, the goal of this function is to output true if the destination airport can be reached from the starting airport in the number of flights specified, given the flight connection information from the passed adjacency list, and false if it is not possible for the destination airport to be reached from the starting airport within the number of flights specified.In addition, this function also prints out each airport as it scans the adjacency list of airports for the correct path. This allows the user to get a better idea of how the function traverses the graph.

 2) getOrder, with function signature: std::vector<Airport*> getOrder(), is just a helper function to retrieve the order in which the IDDFS scans the adjacency list.

 4) DLS, or depth limited search, with function signature: bool DLS(Airport* start, Airport* target, int numFlights, AdjList& adjList), is a function that is used within the IDDFS algorithm. It is essentially taking the same arguments as IDDFS, and checking if any of airports adjacent to the starting airport are the target airport. If one of them is, then it returns true, as we have found a path, otherwise it returns false. Basically in IDDFS we run this function over an over again until the number of maximum flights has been reached.

 We have tested this function on our trimmed USA datalist and after changing our variables for maximum number of flights, starting aiport and destination airport, we have validated that this function produces the correct result when it comes down to true or false. We have also verified that it returns the correct minimum number of flights and have manually gone through and verified that the way in which the function scans makes sense with the ideal scanning path of an Iterative depth first search algorithm.


Conclusion / Leading Question Response:
Ultimately, our goal was to analyze a large database of flight and airport data. Specifically, we aimed to complete a BFS search algorithm, a shortest path algorithm, and a graph visualization. In the end, we were largely successful. We created each of these algorithms successfully for our trimmed data set of the 35 most popular U.S. airports. Our functions allow us to input a starting airport and discover which airports are reachable and even the shortest path between it and another given airport. However, our understanding of BFS at the time of our proposal was not strong enough to understand how it would function in our project. We assumed it would be used to return a list of the closest airports to a given airport. However, this information is clearly just accessible with our adjacency list, and isn't particularly useful. Instead, our BFS marks edges as discovery or cross and returns a vector that contains the order in which airports are visited during our search. Overall, this project lead to a major improvement in our programming skills as well as a clear increase in our teamwork and ability to understand how to create real world projects.
