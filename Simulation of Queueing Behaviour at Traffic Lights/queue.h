/************************************************************************/
/*                                                                      */
/* Interface file for queue implementation with front and rear          */
/*                                                                      */
/* The rear and front is to ensure O(1) for both enqueue and dequeue    */
/*                                                                      */
/*                                                                      */
/* Wuyeh Jobe                                                           */
/* AndrewID: jwuyeh                                                      */
/* 26/02/2020                                                           */
/*                                                                      */
/************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE  1

typedef  struct {
	long int time_arrived;
} ELEMENT_TYPE;

typedef struct node *NODE_TYPE;


typedef struct node {
	ELEMENT_TYPE element;
	NODE_TYPE next;
} NODE;

static NODE_TYPE front = NULL;
static NODE_TYPE rear = NULL;


typedef NODE_TYPE QUEUE_TYPE;



/*** function prototypes ***/


/*** initialize the queue pointer to make sure all subsequent checks on its value are valid ***/

void initialize_queue(QUEUE_TYPE *queue);

/*** empty a queue ***/

NODE_TYPE empty(QUEUE_TYPE *queue);

/*** test to see if a queue is empty  ***/

int is_empty(QUEUE_TYPE *queue);

/*** insert an element in a queue ***/

void enqueue(ELEMENT_TYPE e,  QUEUE_TYPE *queue );

/*** delete an element in a queue ***/

int dequeue(QUEUE_TYPE *queue);

/*** retrieve an element in a queue ***/

ELEMENT_TYPE retrieve(QUEUE_TYPE *queue);

/*** print all elements in a queue ***/

int print(QUEUE_TYPE *queue);

/*** error handler: print message passed as argument and take appropriate action ***/

void error(char *s);

/*** assign values to an element ***/

void assign_element_values (ELEMENT_TYPE *e, int time_arrived);
