/* 

textAnalysisImplementation.cpp - implementation file for a program named textAnalysis
============================================================================

This program is for Assignment No. 4, Course 04-630 Data Structures and Algorithms for Engineers. 

Please refer to the application file - textAnalysisApplication.cpp - for details of the functionality of this program


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



#include "textAnalysis.h"

void prompt_and_exit(int status) {
	printf("Press any key to continue and close terminal\n");
	getchar();
	exit(status);
}

/** Convert a word to the lowercase **/
void toLower(char word[]){
	unsigned int i;
	for (i=0; i<strlen(word); i++) {
		word[i] = tolower(word[i]);
	}
}

/** Convert a word to the uppercase **/
void toUpper(char word[]){
	int i;
	for (i=0; i<strlen(word); i++) {
		word[i] = toupper(word[i]);
	}
}

/** Remove unwanted characters and 's after a word **/
void removeUnwantedChars(char word[]){
	int i,j;
	int strLength = strlen(word);
	char newword[MAX_STRING_LENGTH];
	j = 0;
	for (i=0; i<strLength; i++) {
		if (isalnum(word[i]) || word[i] == '-') {
			newword[j] = word[i];
			j++;
		}
		else if(word[i] == '\''){
			/*if (i+1 <= strLength-1){
				if(word[i+1] == 's')
					i++;
			}*/
			break;
		}
	}
	if(j !=0){
		newword[j] = '\0';
		strcpy(word, newword);
	}
	
}

/* check the whitespace character after the word to see if it is a newline */
void checkWhiteSpace (FILE * fp_in2, char word[]){
	char ch;
	ch = getc(fp_in2);
	if (ch == '\n') {
		strcat(word,"\n"); // add a newline character so that subsequent text in on the next line
	}
	else {
		strcat(word," ");  // add the whitespace
	}
}