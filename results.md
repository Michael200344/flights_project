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

