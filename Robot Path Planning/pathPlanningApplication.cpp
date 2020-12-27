/* 

   pathPlanningApplication.cpp - application file for a program named pathPlanning
   =====================================================================

   This program is for Assignment No. 5, Course 04-630 Data Structures and Algorithms for Engineers. 

   The functionality of the program is defined as follows.
   
	A program to determine the shortest path between a robot’s initial position and a goal
	position using a grid-based map of the robot’s environment.
	The map comprises a two-dimensional array of numbers, each number representing the
	occupancy of a cell in the grid.
	0 indicates that the cell is empty and the robot can occupy that cell when navigating
	to its goal.
	1 indicates that there is an obstacle in that cell and the robot cannot move into that
	cell when navigating to its goal.
	2 indicates the initial position of the robot.
	3 indicates the goal position of the robot.
	The size of the map can vary. Its dimensions are n and m, 1 <= n <= 100 and 1 <= m <= 100,
	where n is the number of rows in the map and m is the number of columns.
	The origin of the map is given by cell coordinates (0, 0). This is the cell at the top left of the
	map.
	The robot’s initial position and its goal position are given in cell coordinates.
	The path the robot takes is indicated by printing a ‘*’ character in each map cell
	on the path.
	If no path can be found, a message is printed saying that no path exists from the
	robot’s initial position to its goal position, stating the coordinates of both positions in the
	message.
	The robot only moves forwards, backwards, and sideways, i.e. it only moves from cell
	(i, j) to cells (i, j-1), (i, j+1), (i-1, j), or (i+1, j)

	The path the robot takes is shown on an output map where:
	- An empty cell is depicted by a space ' ' character
	- An obstacle is depicted by '#' character
	- The start position of the robot is depicted by a '@' character
	- The destination position of the robot is depicted by a '$' character
	- The path cells are depicted by a '*' character
	In order to render the graph with the correct aspect ratio (width divided by height), each cell
	character (' ', '#', '@', '$', '*') is followed by a space ' '.

   Input data with a test case message is provided in an input file named input.txt.  
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the pathPlanning .exe file resides, the filename used when opening the file is "../data/input.txt".


   Output for the test case is written to an output file "../data/output.txt"

   

   Input
   -----

   - The first line of the input file contains the number of scenarios to be considered.
	The remaining lines in the input file specify these scenarios.
	Each scenario begins with a line containing two digits: the dimensions n and m of the grid
	map.
	There then follow n lines, each line comprising m numbers. Each number is either a 0, 1, 2, or
	3, designating an unoccupied cell, a cell occupied by an obstacle, the start cell where the robot
	is located initially, and the destination cell, respectively.
	You can assume that all input provided is valid and contains no errors. In particular, you can
	assume that one and only one cell in the grid contains a 2 and one and only one cell contains a
	3.


   Output
   ------

   - The program should writes to the output file (“output.txt”) the Andrew Id as the first line.
	This is followed by the scenario number, followed by the map with the path marked
	on it, i.e. n lines, each line comprising 2m characters, i.e. the characters ' ', '#', '@', '$', or '*',
	each followed by a space character ' ', depending on whether it is an unoccupied cell, and
	obstacle cell, the initial cell, the goal cell, or a cell on the path from the initial cell to the goal
	cell.
	If no path can be found, a message is printed saying that no path exists from the
	robot’s initial position to its goal position (state the coordinates in the message).
	A blank line is written after each scenario.

 

   Sample Input
   ------------
   
	4
	4 4
	2 0 0 0 
	0 1 1 0 
	0 0 0 0 
	0 0 0 3
	10 10
	0 0 0 0 0 0 0 0 0 0
	0 2 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0
	0 0 0 1 1 1 1 1 1 0
	0 0 0 1 1 1 1 0 0 0
	0 0 0 1 1 1 1 0 0 0
	0 0 0 0 0 1 1 0 0 0
	0 1 1 1 0 0 0 0 0 0
	0 1 1 1 0 0 0 0 3 0
	0 0 0 0 0 0 0 0 0 0 
	2 2
	1 2
	1 3
	5 5
	2 0 0 0 0
	0 1 1 1 0
	0 0 1 0 1
	0 0 1 3 0
	0 0 1 1 0


   Sample Output
   -------------

	jwuyeh
	Scenario 1
	@       
	* # #   
	*       
	* * * $ 

	Scenario 2
                    
	  @                 
	  *                 
	  *   # # # # # #   
	  *   # # # #       
	  *   # # # #       
	  * * * * # #       
	  # # # *           
	  # # # * * * * $   
                    

	Scenario 3
	# @ 
	# $ 

	Scenario 4
	No path from (0 0) to (3 3)
	@         
	  # # #   
		#   # 
		# $   
		# #   




   Solution Strategy
   -----------------

   - print the andrew (jwuyeh) to the output
   - Read the number of scenarios
   - For each scenario:
		- Print the scenario number
		- Read the dimensions of the map
		- Read the inputs of the map into a pointer based 2D array
		- While reading the inputs, if a start cell (indicated by cell value of 2) or 
		  goal cell (indicated by cell value of 3) is met, store their cell cordinates 
		  and reset the cell value to 0
		- Build a graph by inserting an edge between vertice numbers ( representing cell coordinates
		  and generated using a mapping function that takes in the cell coordinates and the y dimension 
		  as a parameter). An edge is inserted between vertices whose cell values are similar (i.e an 
		  obstacle is connected to an obstacle and a free cell is connected to a free cell).
		- Find the path from start to goal using BFS
		- When a path is found, convert the vertices into their cell cordinates and mark the
		  corresponding cell values with 4, to use when printing the character map
		- Print characters representing various start, goal, obstacles, path, free cell spaces


   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

   - Map with 1 column and 2 rows (with start and goal only)
   - Map with 2 columns and 1 rows (with start and goal only)
   - Goal is surrounded with obstacles
   - A map with 100 * 100 dimension
   - Map with all obstacles aside from start and goal
   - Map with start and goal side by side each other
   - Map with all free spaces
   - When start and goal are on different ends of the map






   File organization
   -----------------

   pathPlanning.h                  interface file:      
                              contains the declarations required to use the functions that implement the solution to this problem
                              typically, these will include the definitions of the abstract data types used in the implementation

   pathPlanningImplementation.cpp  implementation file: 
                              contains the definitions of the functions that implement the algorithms used in the implementation
 
   pathPlanningApplication.cpp     application file:    
                              contains the code that instantiates the abstract data types and calls the associated functions
                              in order to effect the required functionality for this application


   Author
   ------

   Wuyeh Jobe (jwuyeh), Carnegie Mellon University Africa
   29/03/2020

*/
 
#include "pathPlanning.h"


int main() {

   bool debug = false;
   FILE *fp_in, *fp_out;
   int i;

   graph g; //graph declaration
   bool directed = false; // boolean to decide if graph should be directed or not
   int robot_x, robot_y; //Robot's x and y cordinates for start position
   int goal_x,  goal_y; //Robot's x and y cordinates for goal position
   int robot; //robot's start vertex number
   int goal; //robot's goal vertex number
   int map_dimension_x, map_dimension_y; //dimensions of the map
   int scenario; //count of the number of scenarios for testing purpose
   int number_of_scenarios; //number of scenarios to be tested
   int *map[MAX_M]; //2D map for the graph using a pointer based array

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

   scenario = 0; //initialize scenario count

   fscanf(fp_in, "%d",&number_of_scenarios); //read number of scenarios

   for (i=0; i<number_of_scenarios; i++) {
      
      fprintf(fp_out, "Scenario %d\n",i+1); //print scenario processed to output file

      fscanf(fp_in, "%d %d",&map_dimension_x, &map_dimension_y); // read the dimensions of the map
	  //printf("%d - %d\n", map_dimension_x, map_dimension_y);

      /* read the input file and initialize the map array, and also get the start and goal cells */
      read_map_robot_goal(fp_in,   map, map_dimension_x, map_dimension_y, &robot_x, &robot_y, &goal_x, &goal_y);  

      if (debug) {
         printf("Scenario %d\n",i+1);
         printf("Map dimensions: %d %d\n", map_dimension_x, map_dimension_y);
         printf("Robot and goal positions: (%d %d), (%d %d)\n", robot_x, robot_y, goal_x, goal_y);
      }

	  map_to_graph(&g, directed, map, map_dimension_x, map_dimension_y);  // convert the array map to a graph
    
      if (debug) print_graph(&g);

	  robot = vertex_number(robot_x, robot_y, map_dimension_y);           // get the vertex number for the robot coordinates (using a mapping function)
      goal  = vertex_number(goal_x,  goal_y, map_dimension_y);            // get the vertex number for the robot coordinates (using a mapping function)
	  find_path_and_trace(&g, robot, goal, map, map_dimension_x, map_dimension_y);

	   if (debug) {
         printf("Robot and goal vertices: %d %d\n", robot, goal);         // print the vertex numbers to check
      }

      if (!find_path_and_trace(&g, robot, goal, map, map_dimension_x, map_dimension_y)) {           // mark the path on the map by performing a BFS on the graph
         if (debug) {                                                                            // and using the find_path() function to identify the vertices on the path
            printf("No path from (%d %d) to (%d %d)\n", robot_x, robot_y, goal_x, goal_y);       // these vertex numbers have to be convered to coordinates (using a mapping function)
         }                                                                                       // check to see whether there is a path and print a message if not
         fprintf(fp_out, "No path from (%d %d) to (%d %d)\n", robot_x, robot_y, goal_x, goal_y);
      }

	  /* printing characters representing various start, goal, obstacles, path, free spaces */
	  write_map(fp_out, map, map_dimension_x, map_dimension_y, robot_x, robot_y, goal_x, goal_y); 
   }



   fclose(fp_in);
   fclose(fp_out);

   // keep the terminal open until the user hits return
   if (debug) {
      printf("Press <return> to finish"); 
      getchar();
   }
}