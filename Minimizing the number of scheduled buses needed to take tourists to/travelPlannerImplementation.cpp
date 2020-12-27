/* 

travelPlannerImplementation.cpp - implementation file for a program named travelPlanner
============================================================================

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

Wuyeh Jobe, Carnegie Mellon University Africa
29/03/2020


*/



#include "travelPlanner.h"


void prompt_and_exit(int status) {
	printf("Press any key to continue and close terminal\n");
	getchar();
	exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {

	fprintf(fp,"The message is: %s\n", message);
}


/* Build the graph from the inputs */
void build_graph(graph *g, FILE *fp_in, bool directed, int N, int R){
	int i,
		C1, /* First city, marking beginning of a road*/
		C2, /* Second city, marking end of a road */
		P; /* Maximum number of passengers that can be transported */
	initialize_graph(g, directed); // initialize graph
	g->nvertices = N;

	for (i=0; i< R;i++){
		fscanf(fp_in, "%d %d %d",&C1, &C2, &P); // cities and the end of the road and maximum passengers
		// for the bus service between the citities
		if (debug) printf("C1: %d C2: %d P: %d \n",C1, C2, P);
		insert_edge(g,C1, C2, directed, P); //build graph as we read the inputs
	}

}


