/* 

travellingSalesmanImplementation.cpp - application file for the solution of the travelling saleman problem by exhaustive search using backtracking

04-630 Data Structures and Algorithms for Engineers Assignment No. 7

The backtracking code is based on the examples in S. Skiena, The Algorithm Design Manual, 2008.
David Vernon
16 April 2018

*/

#include "travellingSalesman.h"

/* original backtracking code ... needs to be adapted for the assignment */

void backtrack(int a[], int k, int input, int distances[NUMBER_OF_STOPS][NUMBER_OF_STOPS]) {

	int c[MAXCANDIDATES];     /* candidates for next position  */
	int ncandidates;          /* next position candidate count */
	int i;                    /* counter                       */

	if (is_a_solution(a,k,input)) {
		process_solution(a,k,input,distances);
	} 
	else {
		k = k+1;
		construct_candidates(a,k,input,c,&ncandidates); 
		for (i=0; i<ncandidates; i++) {
			a[k] = c[i];
			//make_move(a,k,input);
			backtrack(a,k,input,distances);
			//unmake_move(a,k,input);
		}
	}
}



bool is_a_solution(int a[], int k, int n) {
	return (k == n);
}

int mindistance = 99999;
int bestRoute[NMAX+1];
int rr = 1;
void process_solution(int a[], int k, int input, int distances[NUMBER_OF_STOPS][NUMBER_OF_STOPS]) {

	int i;                       /* counter */
	bool print_permuations;      /* flag ... set to true if you want the permutations listed to the terminal */

	print_permuations = true;    /* set to true if you want the permutations printed to the terminal; false otherwise */


	int total_distance = distances[input][a[1]-1];
	//printf("f: %d t: %d d: %d==>", input+1, a[1], distances[input][a[1]-1]);
	for (i=1; i<k; i++) {
		printf("f: %d t: %d d: %d==>", a[i], a[i+1], distances[a[i]-1][a[i+1]-1]);
		total_distance += distances[a[i]-1][a[i+1]-1];
		//printf(" %d",a[i]);
	}
	//printf("f: %d t: %d d: %d==>", a[k], input+1, distances[a[k]-1][input]);
	total_distance += distances[a[k]-1][input];
	printf("total distance %d :", total_distance);
	if (total_distance < mindistance){
		mindistance = total_distance;
		for (i=1; i<=k; i++) {
			bestRoute[i] = a[i];
			//printf(" %d",a[i]);
		}
		//bestRoute = a;
	}
	rr = k;
	if (print_permuations) {
		for (i=1; i<=k; i++) {
			printf(" %d",a[i]);
		}
		printf("\n");
	}
}

void print_details(FILE* fp_out, struct record_type record[], int n){
	fprintf(fp_out, "%d \n", mindistance);
	fprintf(fp_out,"%s \n", record[rr].string);
	for (int i=1; i<=rr; i++) {
		fprintf(fp_out,"%s \n", record[bestRoute[i]-1].string);
		/*for (int j=1;j<=rr;j++){
			if (bestRoute[j] == record[i-1].key){
				fprintf(fp_out,"%s \n", record[i-1].string);
			}
	}*/
		printf(" %d",bestRoute[i]);
	}
	fprintf(fp_out,"%s \n", record[rr].string);
	printf("\n");
	mindistance = 99999;
	rr = 1;
}


void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {

	int i;                       /* counter */
	bool in_perm[NMAX];          /* who is in the permutation? */
	for (i=1; i<NMAX; i++) {     /* NB: NMAX must be the number of elements in the permutation + 1 to allow for counting from 1, rather than 0 */
		in_perm[i] = FALSE;
	}

	/* the original Skiena code is incorrect ... a[i(==0)] is not a valid element of the permutation since we start storing them at a[1]

	for (i=0; i<k; i++) in_perm[ a[i] ] = TRUE;

	*/

	for (i=1; i<k; i++) in_perm[ a[i] ] = TRUE; // we are finding candidates for a_k, a_k+1, ... a_n
	// when k == 1, all candidates are valid because we haven't selected any yet
	// when k == 2, all candidates except a_1 are valid
	// when k == n, all candidates except a_1 .. a_n-1 are valid
	*ncandidates = 0;
	for (i=1; i<=n; i++) {
		if (in_perm[i] == FALSE) {
			c[ *ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
	}
}


void prompt_and_exit(int status) {
	printf("Press any key to continue and close terminal\n");
	getchar();
	exit(status);
}

void remove_new_line(char string[]) {
	int i;

	i=0;
	while(string[i] != '\0' && string[i] != '\n')
		i++;
	string[i] = '\0';
}

