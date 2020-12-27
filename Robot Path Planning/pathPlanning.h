/* 

   pathPlanning.h - interface file for a program named pathPlanning
   ======================================================

   This program is for Assignment No. 5, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - pathPlanningApplication.cpp - for details of the functionality of this program

      
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

 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include "graph.h"

#define TRUE 1
#define FALSE 0
#define MAX_N 100
#define MAX_M 100

/* function prototypes go here */

void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);

/* function to read the map and get the robot's position and goal  */
void read_map_robot_goal(FILE *fp_in,   int *map[], int map_dimension_x, int map_dimension_y, int *robot_x, int *robot_y, int *goal_x, int *goal_y);

/* Function get the robot's start and goal positions */
//void get_start_and_destination_coordinates(int *map[], int map_dimension_x, int map_dimension_y, int robot_x, int robot_y, int goal_x, int goal_y); 

/** Print characters  based on the map **/
void write_map(FILE * file, int *map[], int map_dimension_x, int map_dimension_y, int robot_x, int robot_y, int goal_x, int goal_y);

/**  change the map to a graph **/
void map_to_graph(graph* g, bool directed, int *map[],  int map_dimension_x, int map_dimension_y);

/** Get vertex number **/
int vertex_number(int i, int j, int map_dimension_y);

/** Get coordinates based on  vertex number **/
void coordinates(int vertex_n, int map_dimension_x, int map_dimension_y, int *coord_x, int *coord_y);