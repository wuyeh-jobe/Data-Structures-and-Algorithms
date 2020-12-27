/* 
  Interface file

  Graph - adjacency list implementation based on code by Steven Skiena:

  Steven S. Skiena, "The Algorithm Design Manual", 2nd Edition, Springer, 2008.

  David Vernon
  19 March 2017

  Wuyeh Jobe
  15 April 2020
  Adapted find path and get the weights

*/
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define QUEUESIZE       10000

typedef int item_type;

typedef struct {
        item_type q[QUEUESIZE+1];       /* body of queue */
        int first;                      /* position of first element */
        int last;                       /* position of last element */
        int count;                      /* number of queue elements */
} queue;


/* Adjacency list representation of a graph of degree MAXV          */
/*                                                                  */
/* Directed edge (x, y) is represented by edgenode y in x’s         */
/* adjacency list. Vertices are numbered 1 .. MAXV                  */

#define MAXV 25  /* maximum number of vertices */
#define MAXINT 10000

//Original code
//typedef struct {
//   int y;                        /* adjacent vertex number          */
//   int weight;                   /* edge weight, if any             */
//   struct edgenode *next;        /* next edge in list               */
//} edgenode;

typedef struct edgenode *EDGENODE_PTR;

typedef struct edgenode {
   int y;                        /* adjacent vertex number          */
   int weight;                   /* edge weight, if any             */
   EDGENODE_PTR next;            /* next edge in list               */
} edgenode;

typedef struct {
        edgenode *edges[MAXV+1]; /* adjacency info: list of edges   */
        int degree[MAXV+1];      /* number of edges for each vertex */
        int nvertices;           /* number of vertices in graph     */
        int nedges;              /* number of edges in graph        */
        bool directed;           /* is the graph directed?          */
} graph;

/* Initialize graph  */
void initialize_graph(graph *g, bool directed);

/* insert edge in a graphs */ 
void insert_edge(graph *g, int x, int y, bool directed, int w);

/* Print a graph            */
void print_graph(graph *g);


/* DV abstract version that hides implementation by removing the parent array from the parameter list */
/* leaving only parameters that can be passed as arguments from the application code                  */
bool find_path(int start, int end, int parents[]);

/* adapted from original to return true if it is possible to reach the end from the start */
bool find_path(graph *g, int start, int end);

/** Write the results of the computations to the output file **/
void write_graph_results(FILE* fp_out, int N, int T);

/* reset the path counter */
void reset_path_counter();

 