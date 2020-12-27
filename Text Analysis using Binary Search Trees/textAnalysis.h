/* 

textAnalysis.h - interface file for a program named textAnalysis
======================================================

This program is for Assignment No. 4, Course 04-630 Data Structures and Algorithms for Engineers. 

Please refer to the application file - textAnalysisImplementation.cpp - for details of the functionality of this program


File organization
-----------------

textAnalysis.h                  interface file:      
contains the declarations required to use the functions that implement the solution to this problem
typically, these will include the definitions of the abstract data types used in the implementation

textAnalysisImplementation.cpp  implementation file: 
contains the definitions of the functions that implement the algorithms used in the implementation

textAnalysisApplication.cpp     application file:    
contains the code that instantiates the abstract data types and calls the associated functions
in order to effect the required functionality for this application

Author
------

Wuyeh Jobe, Carnegie Mellon University Africa
03/18/2020

*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_STRING_LENGTH 100

/* function prototypes go here */


void prompt_and_exit(int status);

/** Convert a word to the lowercase **/
void toLower(char word[]);

/** Remove unwanted characters and 's after a word **/
void removeUnwantedChars(char word[]);

/** Convert a word to the uppercase **/
void toUpper(char word[]);

/* check the whitespace character after the word to see if it is a newline */
void checkWhiteSpace (FILE * fp_in2, char word[]);