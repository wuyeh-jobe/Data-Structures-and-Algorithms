/* 
   antPathImplementation.cpp - implementation file for a program named anthPath
   ============================================================================

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

 
 
#include "antPath.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {
 
   fprintf(fp,"The message is: %s\n", message);
}

/*This function is used to check if the the location point to be added
is a duplicate and returns 1 if that is true, and 0 otherwise
*/
int foundDuplicate(struct location lcs[], int size, int x, int y){
	int found = 0;
	for(int i=0; i< size; i++){
		if ((lcs[i].x==x) && (lcs[i].y==y)){
			found = 1;
			break;
		}
	}
	return found;
}

#ifdef compile
int truncate(float num){
	if (num<0){
		return (int) ceil(num);
	}
	else if(num>0){
		return (int) floor(num);
	}
	else{
		return (int) num;
	}
		
}

#endif