/* 

   sortLocationsImplementation.cpp - implementation file for a program named example
   ============================================================================

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

 
 
#include "sortLocations.h"

/** Stores the location point given the next index and a location point **/
void storeLocation(struct location lcs[], int index, float t, int x, int y){
	lcs[index].t = t;
	lcs[index].x = x;
	lcs[index].y = y;
}

/** Implementation of the insertion that uses the three keys **/
void insertionSorts(struct location lcs[], int size) {
	int i,j;
	for (i=1; i<size; i++) {
		j=i;
		while ((j>0) && (lcs[j].t < lcs[j-1].t)){
			swap_positions(lcs, j);
			j = j-1;
		}
	}

	for (i=1; i<size; i++) {
		j=i;
		while ((j>0) && (lcs[j].y < lcs[j-1].y)){
			swap_positions(lcs, j);
			j = j-1;
		}
	}

	for (i=1; i<size; i++) {
		j=i;
		while ((j>0) && (lcs[j].x < lcs[j-1].x)){
			swap_positions(lcs, j);
			j = j-1;
		}
	}
}

/*** exchange two location points based***/
void swap_positions(struct location lcs[], int j) {

	struct location temp;
	temp = lcs[j-1]; // swap
	lcs[j-1] = lcs[j];
	lcs[j] = temp;

}

