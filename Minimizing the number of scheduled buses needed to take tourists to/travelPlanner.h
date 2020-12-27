/* 

   travelPlanner.h - interface file for a program named travelPlanner
   ======================================================

   This program is for Assignment No. 6, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - travelPlannerApplication.cpp - for details of the functionality of this program

      
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

 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include "graph.h"
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_N 100
#define MAX_M 100
#define debug false


/* function prototypes go here */

void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);

/** Take inputs and build the graph **/
void build_graph(graph *g, FILE *fp_in, bool directed, int N, int R);