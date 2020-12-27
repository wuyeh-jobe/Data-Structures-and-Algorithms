/* 

   sortLocations.h - interface file for a program named example
   ======================================================

   This program is for Assignment No. 2, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - sortLocationsApplication.cpp - for details of the functionality of this program

      
   File organization
   -----------------

   sortLocations.h                  interface file:      
                              contains the declarations required to use the functions that implement the solution to this problem
                              typically, these will include the definitions of the abstract data types used in the implementation

   sortLocationsImplementation.cpp  implementation file: 
                              contains the definitions of the functions that implement the algorithms used in the implementation
 
   sortLocationsApplication.cpp     application file:    
                              contains the code that instantiates the abstract data types and calls the associated functions
                              in order to effect the required functionality for this application
                                                    
   Author
   ------

   Wuyeh Jobe, Carnegie Mellon University Africa
   17/02/2020


*/

 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

/*** Specify maximum number of locations for the array */
#define MAX_NUMBER_OF_LOCATION 27000


/* Define structure to store the locations*/
 struct location{
	   float t;
	   int x;
	   int y;
 };

/*** Store location points ***/
void storeLocation(struct location lcs[],int index, float t, int x, int y);

/*** exchange the positions of the locations based comparisons ***/
void swap_positions(struct location lcs[], int j);

/** sort the list if locations based on the three keys **/
void insertionSorts(struct location lcs[], int size);


