/* 

pathPlanningImplementation.cpp - implementation file for a program named pathPlanning
============================================================================

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

Wuyeh Jobe, Carnegie Mellon University Africa
29/03/2020


*/



#include "pathPlanning.h"

void prompt_and_exit(int status) {
	printf("Press any key to continue and close terminal\n");
	getchar();
	exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {

	fprintf(fp,"The message is: %s\n", message);
}

/* function to read the map and get the robot's position and goal  */
void read_map_robot_goal(FILE *fp_in,   int *map[], int map_dimension_x, int map_dimension_y, int *robot_x, int *robot_y, int *goal_x, int *goal_y) { 
	int i, j;   
	for (i=0; i<map_dimension_x; i++) {   
		map[i] = new int[map_dimension_y]; //allocate memory for number of columns required
		if (map[i] == NULL)
		{ 
			printf("No memory");
		}
		else{
			for (j=0; j<map_dimension_y; j++) { 
				fscanf(fp_in, "%d", &((*(map+i))[j])); // pass a pointer to the array element to be changed, i.e. the address of the element      
				if ((*(map+i))[j] == 2){
					*robot_x = i; // set start's x
					*robot_y = j; // set start's y
					(*(map+i))[j] = 0; //put to zero for creating graph
				}
				else if ((*(map+i))[j] == 3){
					*goal_x = i; // set goal's x
					*goal_y = j; // set goal's y
					(*(map+i))[j] = 0; //put to zero for creating graph
				}
			}   
		}
	}
}


/** Print characters  based on cell values 1(obstacle) = #, @ for start, $ for end, * for path, space for free cells **/
void write_map(FILE * file, int *map[], int map_dimension_x, int map_dimension_y, int robot_x, int robot_y, int goal_x, int goal_y){
	int i,j;
	for (i=0; i< map_dimension_x;i++){
		for (j=0;j<map_dimension_y;j++){
			if ((*(map+i))[j] == 1){
				fprintf(file, "%c ", '#');
			}
			else if(i==robot_x && j==robot_y){
				fprintf(file, "%c ", '@');
			}
			else if(i==goal_x && j == goal_y){
				fprintf(file, "%c ", '$');
			}
			else if((*(map+i))[j] == 4){
				fprintf(file, "%c ", '*');
			}
			else{
				fprintf(file, "%c ", ' ');
			}
		}
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
}

/**  change the map to a graph **/
void map_to_graph(graph *g, bool directed, int *map[],  int map_dimension_x, int map_dimension_y){
	int n_vertices, i, j/*, vertex, vertex_right, vertex_bottom*/;
	n_vertices = map_dimension_x * map_dimension_y;
	initialize_graph(g, directed); // initialize graph
	g->nvertices = n_vertices;

	for (i=0; i< map_dimension_x; i++){
		for (j=0; j < map_dimension_y; j++){

			/* Add horizontal edges and last vertical edge */
			if (j+1 < map_dimension_y){ //Check if not last but one vertex column wise
				
				if ((*(map+i))[j] == (*(map+i))[j+1]){ //Check if vertice at the left is equal to one at the right
					insert_edge(g,vertex_number(i,j,map_dimension_y), vertex_number(i,j+1,map_dimension_y), directed, 0);
				}
			}

			/* Add vertical edges */
			if (i+1 < map_dimension_x){
				if ((*(map+i))[j] == (*(map+i+1))[j]){
					insert_edge(g,vertex_number(i,j,map_dimension_y), vertex_number(i+1,j,map_dimension_y), directed, 0);
				}
			}
		}
	}


}

/** Get vertex number based on cordinates **/
int vertex_number(int i, int j, int map_dimension_y){
	int base = 1;
	return base + i * map_dimension_y + j;
}

/** Get coordinates based on  vertex number **/
void coordinates(int vertex_n, int map_dimension_x, int map_dimension_y, int *coord_x, int *coord_y){
	int i, j;
	for(i=0; i < map_dimension_x;i++){
		for (j=0; j< map_dimension_y;j++){
			if ( vertex_n == vertex_number(i,j,map_dimension_y)){
				*coord_x = i;
				*coord_y = j;
				break;
				break;
			}
		}
	}

}



