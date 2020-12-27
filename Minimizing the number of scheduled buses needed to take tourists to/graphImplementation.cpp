/* 

Implementation file

Graph - adjacency list implementation based on code by Steven Skiena:

Steven S. Skiena, "The Algorithm Design Manual", 2nd Edition, Springer, 2008.

David Vernon
19 March 2017

Wuyeh Jobe
15 April 2020
Adapted find path and get the weights using Prim's algorithm

*/


#include "travelPlanner.h"

/* Breadth-First Search data structures */
bool processed[MAXV+1];   /* which vertices have been processed */
bool discovered[MAXV+1];  /* which vertices have been found */
int  parent[MAXV+1];      /* discovery relation */
bool intree[MAXV+1]; /* is the vertex in the tree yet? */
int distance[MAXV+1]; /* cost of adding to tree */
int path[MAXV+1]; /* path of the graph */
int distance_selected[MAXV+1]; /* cost of adding to tree */


/* Initialize graph  */

void initialize_graph(graph *g, bool directed){

	int i;                          /* counter */

	g -> nvertices = 0;
	g -> nedges = 0;
	g -> directed = directed;

	for (i=1; i<=MAXV; i++) 
		g->degree[i] = 0;

	for (i=1; i<=MAXV; i++) 
		g->edges[i] = NULL; 
}



/* insert edge in a graphs */

void insert_edge(graph *g, int x, int y, bool directed, int w) {

	edgenode *p;                  /* temporary pointer */

	p = (EDGENODE_PTR) malloc(sizeof(edgenode)); /* allocate edgenode storage */
	//^^^^^^^^^^^^^^ ADDED CAST. DV 7/11/2014

	p->weight = w;
	p->y = y;
	p->next = g->edges[x];

	g->edges[x] = p;              /* insert at head of list        */

	g->degree[x] ++;

	if (directed == false)        /* NB: if undirected add         */
		insert_edge(g,y,x,true,w); /* the reverse edge recursively  */  
	else                          /* but directed TRUE so we do it */
		g->nedges ++;              /* only once                     */
}


/* Print a graph                                                    */

void print_graph(graph *g) {

	int i;                             /* counter           */
	edgenode *p;                       /* temporary pointer */

	printf("Graph adjacency list:\n");

	for (i=1; i<=g->nvertices; i++) {
		printf("%d: ",i);
		p = g->edges[i];
		while (p != NULL) {

			printf(" %d-%d", p->y, p->weight);

			p = p->next;
		}
		printf("\n");
	}
	printf("nvertices %d\n",g->nvertices);
	printf("nedges    %d\n",g->nedges);

}



/* Prim’s algorithm adapted to maximize minimum passenger */
void prim_adapted(graph *g, int start) {
	int i; /* counter */
	edgenode *p; /* temporary pointer */
	int v; /* current vertex to process */
	int w; /* candidate next vertex */
	int weight; /* edge weight */
	int dist; /* best current distance from start */
	for (i=1; i<=g->nvertices; i++) {
		intree[i] = FALSE;
		distance[i] = 0;
		parent[i] = -1;
	}
	distance[start] = 0;
	v = start;

	while (intree[v] == FALSE) {
		intree[v] = TRUE;
		p = g->edges[v];

		while (p != NULL) {
			w = p->y;
			weight = p->weight;
			if ((weight > distance[w]) && (intree[w] == FALSE)) { //changes from Prim
				distance[w] = weight;
				parent[w] = v;
			}
			p = p->next;
		}
		v = 1;
		dist = 0;
		for (i=1; i<=g->nvertices; i++)
			if ((intree[i] == FALSE) && (distance[i] > dist)) { //changes from Prim
				dist = distance[i];
				v = i;
			}
	}

}


/* adapted from original to return true if it is possible to reach the end from the start */

int c = 1;
bool find_path(int start, int end, int parents[]) {
	bool is_path;

	if (end == -1) {
		is_path = false; // some vertex on the path back from the end has no parent (not counting start)
		if (debug) printf("\nis_path is false: ");
	}
	else if ((start == end)) {
		if (debug) printf("\n%d",start);
		path[c] = start;
		distance_selected[c] = distance[start];
		c++;
		is_path = true; // we have reached the start vertex
	}
	else {
		is_path = find_path(start,parents[end],parents);
		path[c] = end;
		distance_selected[c] = distance[end];
		c++;
		if (debug) printf(" %d",end);
	}
	return(is_path); 
}

/* DV abstract version that hides implementation by removing the parent array from the parameter list */
/* leaving only parameters that can be passed as arguments from the application code                  */

bool find_path(graph *g, int start, int end) {
	bool is_path;

	if (debug) printf("Path from %d to %d:",start,end);

	if ((start < 1) || (start > g->nvertices)) {
		if (debug) 
			printf("Invalid start vertex\n");
		is_path = false;
	}
	else if ((end < 1) || (end > g->nvertices)) {
		if (debug) 
			printf("Invalid end vertex\n");
		is_path = false;
	}
	else {
		prim_adapted(g, start);
		is_path = find_path(start, end, parent); // now call the version of find_path that has the parent array as an argument
		if (debug) printf("\n");
	}
	return(is_path);
}

/* reset the path counter */
void reset_path_counter(){
	c = 1;
}


/** Write the results of the computations to the output file **/
void write_graph_results(FILE* fp_out, int N, int T){
	int i, max_per_trip,
		min_trip,
		total_transported;

	max_per_trip = 10000;
	for (i = 1; i < c; i++){
		if ((distance_selected[i] != 0) && (distance_selected[i] < max_per_trip)){
			max_per_trip = distance_selected[i];
		}
	}

	max_per_trip = max_per_trip - 1; // remove the guide from the number
	min_trip = 0;
	if (max_per_trip != 0)
		min_trip = ceil( (float) T/ max_per_trip); //Get the min number of trips
	fprintf(fp_out, "Minimum Number of Trips = %d: ", min_trip);
	total_transported = 0; //Keep track of the number of tourist transported so far
	for (i = 0; i < min_trip-1; i++){ //print the number of tourist transported during
		fprintf (fp_out, "%d ", max_per_trip); // eacg trip except for last one
		total_transported += max_per_trip; // add to number of transported tourist so far
	}
	fprintf(fp_out, "%d", T - total_transported); //Get the final batch

	//Print the route, which is represented by the path
	fprintf(fp_out, "\nRoute = ");
	for (i=1; i<c; i++){
		//printf("c: %d - d: %d - p: %d\n",c, distance_selected[i], path[i]);
		fprintf(fp_out, "%d ", path[i]);
	}
	fprintf(fp_out, "\n\n");
}


