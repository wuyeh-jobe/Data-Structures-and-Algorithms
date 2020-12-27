/* 

tlQueuing.h - interface file for a program named example
======================================================

This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 

Please refer to the application file - tlQueuingApplication.cpp - for details of the functionality of this program


File organization
-----------------

tlQueuing.h                  interface file:      
contains the declarations required to use the functions that implement the solution to this problem
typically, these will include the definitions of the abstract data types used in the implementation

tlQueuingImplementation.cpp  implementation file: 
contains the definitions of the functions that implement the algorithms used in the implementation

tlQueuingApplication.cpp     application file:    
contains the code that instantiates the abstract data types and calls the associated functions
in order to effect the required functionality for this application

Author
------

Wuyeh Jobe, Carnegie Mellon University Africa
AndrewID: jwuyeh
24/02/2020

*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_MESSAGE_LENGTH 81
#define STRING_LENGTH 20
#define KEY_LENGTH 10
#define NUMBER_OF_KEYS 7
#define MAX_SIMULATIONS_POSSIBLE 1000
#define RED 1
#define GREEN 2
#define AMBER 3
#define MAX_QUEUES int((10*60*1000)/10) //represents the division of max running time and min increment
typedef char keyword[KEY_LENGTH];


typedef struct{
	keyword key;
	int value;
}Key_Value_Pair;



void prompt_and_exit(int status);
int samplePoisson(double lambda);
void simulate(Key_Value_Pair pairs[], FILE* file);
long int wait_time(long int time_arrived, long int time_dequeued);
long int get_max_wait_time(long int cur_wait_time, long int previous_max);
long int get_wait_time(long int time_arrived, long int time_dequeued);
void stats_and_write_to_file(int queue_lengths[], int n_queues, int ave_queue_length,int max_waiting_time, int ave_waiting_time, FILE* file);
void insertionSorts(int queue_lengths[], int size);