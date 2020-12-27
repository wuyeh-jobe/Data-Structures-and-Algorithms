/* 

   travelPlannerApplication.cpp - application file for a program named travelPlanner
   =====================================================================

   This program is for Assignment No. 6, Course 04-630 Data Structures and Algorithms for Engineers. 

   The functionality of the program is defined as follows.
   
	A tourist guide has the task of taking a large group of tourists to a distant city. However, she
	is operating on a strict budget and so she wants to use scheduled bus services. Each pair of
	neighbouring cities has a bus service that runs only between those two cities and uses the road
	that directly connects them. Each bus service has a limit on the maximum number of
	passengers it can carry. The tourist guide has a map showing the cities and the roads
	connecting them, as well as the capacity limit for each bus service.
	Since the number of tourists is very large, it may not always possible for her to take all the
	tourists to the destination city in a single trip. She may have to make several trips. For
	example, consider the following road map of seven cities, where the edges represent roads
	and the number written on each edge indicates the passenger limit of the associated bus
	service.

	This program finds the route to take all tourists to the destination city in the
	minimum number of trips. In the event that it is not possible to find a route that will allow the
	tourists to be taken to the destination, the program should print an appropriate message.
	When running the program, no user interaction is required.

   Input data with a test case message is provided in an input file named input.txt.  
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the travelPlanner .exe file resides, the filename used when opening the file is "../data/input.txt".


   Output for the test case is written to an output file "../data/output.txt"

   

   Input
   -----

   - The input will contain one or more test cases. The first line of each test case will contain two
	integers: N (N ≤ 20) and R, representing the number of cities and the number of road
	segments, respectively. Each of the next R lines will contain three integers (C1, C2, and P)
	where C1 and C2 are the city numbers and P (P > 1) is the maximum number of passengers
	that can be carried by the bus service between the two cities. City numbers are positive
	integers ranging from 1 to N . The (R + 1)th line will contain three integers (S, D, and T)
	representing, respectively, the starting city, the destination city, and the number of tourists to
	be guided. The input will end with zero values for N and R. You can assume that all input
	provided is valid and contains no errors.


   Output
   ------

   - For each test case in the input, output:
	1. the scenario number
	2. the minimum number of trips required, followed by the number of tourists per trip
	(taking as many tourists as possible on each trip except possibly the final trip)
	3. the route to be taken
	All three items are to printed on a separate line. Print a blank line after the output for each
	test case.

 

   Sample Input
   ------------
	7 10
	1 2 30
	1 3 15
	1 4 10
	2 4 25
	2 5 60
	3 4 40
	3 6 20
	4 7 35
	5 7 20
	6 7 30
	1 7 99
	6 6
	1 2 30
	1 3 15
	2 4 20
	3 5 11
	4 6 10
	5 6 20
	1 6 49
	3 3
	1 2 40
	1 3 60
	2 3 50
	1 3 70
	3 3
	1 2 40
	1 3 30
	2 3 50
	1 3 1000
	0 0
	


   Sample Output
   -------------

	jwuyeh
	Scenario 1
	Minimum Number of Trips = 5: 24 24 24 24 3
	Route = 1 2 4 7 

	Scenario 2
	Minimum Number of Trips = 5: 10 10 10 10 9
	Route = 1 3 5 6 

	Scenario 3
	Minimum Number of Trips = 2: 59 11
	Route = 1 3 

	Scenario 4
	Minimum Number of Trips = 26: 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 39 25
	Route = 1 2 3 




   Solution Strategy
   -----------------

   - print the andrew (jwuyeh) to the output
   - Read R (number of roads/edges) and N (number of cities)
   - While R and N are not equal to 0:
     - Read the next R lines, and for each line get the two cities a road is connecting
	   and the passenger limit for the bus services between the cities
	 - Insert these details as the edge of a graph, with cities representing the vertices
	   and the passenger limit representing the weight
	 - After the R lines have been read (a graph is built due to the activity above), read the
	   read the next line and get the start and destination city as well as the number of 
	   tourists to be carried 
	 - This information is used to find a path (explained below) in the graph
	 - After the path is found the minimum passenger limit associated with the path is extracted
	   and the number of trips is calculated dividing the number of tourists to be carried with the
	   minimum passenger limit minus one (to exclude the tour guide).
	 - The number of tourist to be carried in each trip is determined by the passenger limit of the bus service
		- If the number of tourist are more than the passenger limit, the number of tourist for each trip
		  is the passenger limit minus one, except for the last trip in which the remaining tourist (total number
		  of tourists to be carried minus total carried so far)
		- If the number of tourist are less than the passenger limit, they are carried in one trip'
	- This computations are then printed to the array

	*********** Finding the path and the weight associated with paths ************************
	- The prim algorithm is adapted to maximize the weight instead of minimize
	- This means that the parent of a vertex is changed depending on which of the parents have an edge
	  with the highest weight (in this case passenger limit)
	- The prim algorithm is then called in the find path function that takes the start and end destinatio
	- After the prim algorithm is done, it returns an array of parents which is used by the find path function
	  that use the parents to generate the path. As the paths are discovered, they are saved in an array.
	  There corresponding weights are also stored in an array.
	- The paths are printed using the path array, and the minimum weight is determined from the weight array


   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

   - When the number of roads/edges (R) is 0, N > 1 and there is a start and end distination
   - When there is more than one path from start to the destination
   - When the edge between start and distination have the highest maximum passenger value
   - When there is no path from start to destination
   - There is no case for when N = 0 and and R > 1 because then which cities are you connecting??
   - When the number of tourist is zero and there is a path
   - When the number of tourist is 1 and there is a path
   - When the start and end are in extreme ends
   - A test case with more number of vertices (20 vertices)
   - When P = 2
   - When number of tourists is equal to the maximum minimum weight






   File organization
   -----------------

   travelPlanner.h                  interface file:      
                              contains the declarations required to use the functions that implement the solution to this problem
                              typically, these will include the definitions of the abstract data types used in the implementation

   travelPlannerImplementation.cpp  implementation file: 
                              contains the definitions of the functions that implement the algorithms used in the implementation
 
   travelPlannerApplication.cpp     application file:    
                              contains the code that instantiates the abstract data types and calls the associated functions
                              in order to effect the required functionality for this application


   Author
   ------

   Wuyeh Jobe (jwuyeh), Carnegie Mellon University Africa
   29/03/2020

*/
 
#include "travelPlanner.h"


int main() {
   FILE *fp_in, *fp_out;
   graph g; //graph declaration
   bool directed = false; // boolean to decide if graph should be directed or not
   int scenario, 
	   N, /* Number of cities */
	   R, /* Number of road segments */
	   S, /* Start city for picking passengers */
	   D, /* Destination city for passengers */
	   T; /* Number of tourist to be transported */




   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
     getchar();
     exit(0);
   }

   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
     getchar();
     exit(0);
   }

   if (debug) printf("Wavefront Breadth First Search Path Planning\n");

   fprintf(fp_out, "jwuyeh\n"); //print andrew ID

   scenario = 1; //initialize scenario count

   do{

		fscanf(fp_in, "%d %d",&N, &R); //read N and R from file
		if (debug) printf("N: %d R: %d\n",N, R);
		build_graph(&g, fp_in, directed, N, R);
		if ( N !=0 && R != 0){
			fprintf(fp_out, "Scenario %d\n", scenario); //print scenario number
			scenario++;
			fscanf(fp_in, "%d %d %d",&S, &D, &T); // read start and destination cities, and number of tourist
			if (debug) printf("S: %d D: %d T: %d\n",S, D, T);
			if(debug) print_graph(&g);
			if (!find_path(&g, S, D)){
				//There is no path, hence print a message
				fprintf(fp_out, "No path between %d and %d \n\n",S, D);
			}
			else{
				//There is a path, hence write the results to the output file
				write_graph_results(fp_out, N, T);
			}
		}
		else if (R==0 && N !=0){
			// No raods/edges between the cities
			fprintf(fp_out, "Scenario %d\n", scenario); //print scenario number
			fscanf(fp_in, "%d %d %d",&S, &D, &T); // read start and destination cities, and number of tourist
			scenario++;
			fprintf(fp_out, "There are no roads/edges. No trip possible :(\n\n");
		}
		/* After each iteration, this function resets the path counter */
		reset_path_counter();

   }
   while ( (N !=0 && R != 0) || (R==0 && N !=0));

   fclose(fp_in);
   fclose(fp_out);

   // keep the terminal open until the user hits return
   if (debug) {
      printf("Press <return> to finish"); 
      getchar();
   }
}