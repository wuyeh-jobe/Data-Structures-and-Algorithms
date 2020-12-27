/* 

   anthPath.h - interface file for a program named anthPath
   ======================================================

   This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - anthPathApplication.cpp - for details of the functionality of this program

      
   File organization
   -----------------

   antPath.h                  interface file:      
                              contains the declarations required to use the functions that implement the solution to this problem
                              typically, these will include the definitions of the abstract data types used in the implementation

   antPathImplementation.cpp  implementation file: 
                              contains the definitions of the functions that implement the algorithms used in the implementation
 
   antPathApplication.cpp     application file:    
                              contains the code that instantiates the abstract data types and calls the associated functions
                              in order to effect the required functionality for this application
                                                    
   Author
   ------

   Wuyeh Jobe, Carnegie Mellon University Africa
   15/01/2020


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include <cmath>

#define TRUE 1
#define FALSE 0
#define MAX_NUMBER_OF_LOCATION 27001


/* Define structure to store the locations*/
   struct location{
	   int x;
	   int y;
   };

/* function prototypes go here */

void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);
int foundDuplicate(struct location lcs[], int size, int x, int y);