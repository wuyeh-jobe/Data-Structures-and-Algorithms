/* 

   sortLocationsApplication.cpp - application file for a program named example
   =====================================================================

   This program is for Assignment No. 2, Course 04-630 Data Structures and Algorithms for Engineers. 

   The functionality of the program is defined as follows.
   
	This program produce a sort a list of 2D ant locations, each location specified by its
	integer x and y coordinates and the time t that the ant visited that location. The list is
	sorted by two keys: the x coordinate and the y coordinate.
	The sorted list has all x coordinates in ascending order and for locations that have the same x
	coordinate, the locations are listed so that y coordinates are in ascending order. If
	locations have the same x and y coordinates, the locations are listed so that the time t is
	in ascending order.

   Input data with test cases is provided in an input file named input.txt.  
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test cases is written to an output file "../data/output.txt"


   Input
   -----

    - The first line of input comprises an integer n (1 <= n <= 10); this indicates the number of test
	   cases to be processed, i.e. the number of ant paths, in the input file. It is followed by n sets of 
	   locations. Each location comprises three numbers: the time, the x coordinate of the location,
	   and the y coordinate of the location. All three are real numbers. The last location in each set is
	   signified by a time value less than zero, e.g. -1.0. There are no more than 27000 fixation points
	   in one ant path sequence and that the coordinates x and y are in the ge -450 <= x, y <= 450.
	   All input provided is valid and contains no errors.


   Output
   ------

	-Andrew Id on first line.
	-Followed by a sequence of sorted list of three numbers comprising the time t, the x
		coordinate, and the y coordinate on separate lines.
	-The list is sorted by x first, then by y, and then by t, in ascending order.
	-The location is given by the integer part of the location coordinates (through truncation).
	-The sorted list for each test case is delimited by dashes
 

   Sample Input
   ------------
		2
		0.000 0.000 0.000
		0.100 0.050 0.000
		0.200 0.100 0.000
		0.300 0.190 0.000
		0.400 0.300 0.000
		0.500 0.400 0.000
		0.600 0.500 0.000
		0.700 0.600 0.000
		0.800 0.700 0.000
		0.900 0.800 0.000
		1.000 0.900 0.000
		1.100 0.000 1.000
		1.200 0.000 1.010
		1.300 0.000 1.020
		1.400 0.000 2.000
		1.500 0.000 2.000
		1.600 0.000 4.000
		1.700 0.000 4.090
		1.800 0.000 5.000
		1.900 0.000 4.000
		2.000 0.000 2.000
		-1.00 0.000 0.000
		60.063 -28.247 20.743
		60.165 -28.292 20.564
		60.267 -28.430 20.522
		60.370 -28.442 20.456
		60.471 -28.476 20.337
		60.573 -28.638 20.146
		60.676 -28.938 20.071
		60.781 -29.181 19.92
		60.885 -29.163 19.891
		60.993 -29.252 19.84
		61.097 -29.269 19.701
		61.201 -29.340 19.658
		61.302 -29.319 19.586
		61.404 -29.453 19.365
		61.507 -29.621 19.112
		61.608 -29.912 19.067
		61.710 -30.145 18.923
		61.811 -30.221 18.872
		61.918 -30.291 18.892
		62.020 -30.365 18.788
		62.122 -30.462 18.663
		62.223 -30.683 18.633
		62.332 -31.042 18.653
		62.436 -31.328 18.606
		62.537 -31.913 18.621
		62.638 -32.051 18.531
		62.740 -32.824 18.672
		62.841 -32.802 18.745
		62.942 -32.756 18.752
		63.044 -32.655 18.718
		63.147 -32.207 18.516
		63.249 -32.002 18.066
		63.350 -31.847 17.958
		63.452 -31.565 17.685
		63.555 -31.320 17.205
		63.656 -30.980 16.569
		63.837 -30.829 16.044
		63.940 -30.632 16.115
		64.044 -30.407 16.049
		64.145 -30.176 16.052
		64.250 -29.799 16.266
		64.352 -29.582 16.433
		64.456 -29.283 17.090
		64.559 -29.019 17.464
		64.667 -28.514 18.610
		-1.00 0.000 0.000


   Sample Output
   -------------

	   jwuyeh
		 0.000    0    0
		 0.100    0    0
		 0.200    0    0
		 0.300    0    0
		 0.400    0    0
		 0.500    0    0
		 0.600    0    0
		 0.700    0    0
		 0.800    0    0
		 0.900    0    0
		 1.000    0    0
		 1.100    0    1
		 1.200    0    1
		 1.300    0    1
		 1.400    0    2
		 1.500    0    2
		 2.000    0    2
		 1.600    0    4
		 1.700    0    4
		 1.900    0    4
		 1.800    0    5
		-----------------
		62.638  -32   18
		62.740  -32   18
		62.841  -32   18
		62.942  -32   18
		63.044  -32   18
		63.147  -32   18
		63.249  -32   18
		63.350  -31   17
		63.452  -31   17
		63.555  -31   17
		62.332  -31   18
		62.436  -31   18
		62.537  -31   18
		63.656  -30   16
		63.837  -30   16
		63.940  -30   16
		64.044  -30   16
		64.145  -30   16
		61.710  -30   18
		61.811  -30   18
		61.918  -30   18
		62.020  -30   18
		62.122  -30   18
		62.223  -30   18
		64.250  -29   16
		64.352  -29   16
		64.456  -29   17
		64.559  -29   17
		60.781  -29   19
		60.885  -29   19
		60.993  -29   19
		61.097  -29   19
		61.201  -29   19
		61.302  -29   19
		61.404  -29   19
		61.507  -29   19
		61.608  -29   19
		64.667  -28   18
		60.063  -28   20
		60.165  -28   20
		60.267  -28   20
		60.370  -28   20
		60.471  -28   20
		60.573  -28   20
		60.676  -28   20
		-----------------



   Solution Strategy
   -----------------
   -1 Read the first line (the number of test cases)
   -2 Print andrew ID into the output file
   -3 Check if the test case is greater than zero. If not print the message "no test cases" into the output file.
   - Else, do from 4 to 8:
   -4 Intialize the counter to zero
   -5 Read ead all the location points for a test case from the input file and put them into an array of location points 
		concurrently, and each time a point is read, the x and y values are truncated), and the counter is incremented
   -6 While reading the points, if the time value of less than zero is encountered (signalling the end of a test case), sort 
		(using insertion sort) the location points (first by t, followed by y and then x, to ensure that priority is given to
		x, y, and t in this order)
	-7 Print the sorted list into the output file
	-8 Print the dash lines to indicate the end of the output for the a test case
	-9 Do from 4 again, and again untill the end of file is reached

		Note: How The Insertion works for the three keys x,y, and t=>
		Insertion sort works by comparing each element with the previous elements to see if they are lesser,
		if this is the case, then the the values are swapped. If at any point, the current element is equal
		to or greater than a previous element, the comparison is halted and we move to the next element. This
		makes it stable and also better than the brute force way.
		For the purpose of this assignment, the insertion sort algorithm is used thrice for each key t, y, and x

		


   Test Strategy
   -------------

	  The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

	   - When number of test cases is zero
	   - When there are duplicate location points ( x and y) with different time values
	   - When the number of test case is one
	   - When the same location points are given in a different test case
	   - When all the location points are the different
	   - When all the location points are the same (interms of time, x and y)
	   - Test with more data than the one provided in the example (27000 points for one test case)
	   - Test with untipycal number of locations

	Order of Complexity
	-------------------
	- Reading the inputs = kn, where k represents the number of test cases (Thus O(n))
	- Sorting by the three keys = 3n^2 (Thus O(n^2))
	- Printing the sorted array = kn, where k represents the number of test cases (Thus O(n))
	- The total order of complexity is kn+3n^2+kn = O(n^2)



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
int main() {
	/** Declare variables for number of test cases and count **/
   int number_of_test_cases,count;
   /** Declare variables for time, and x and y coordinates**/
   float t, x, y;

   /**Declare the  files variables**/
   FILE *fp_in, *fp_out;

   /** Opens the input file for reading **/
   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
   }

   /** Open the output file to write the result**/
   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
   }

   /* declare an array of location points with the maximum number of location points possible*/
   struct location lcs[MAX_NUMBER_OF_LOCATION];

   /* read the number of test cases from a file */
	fscanf(fp_in, "%d", &number_of_test_cases);//note the &

	/* write the number of test cases to file */
	printf("Number of test cases tried: %d \n", number_of_test_cases);

	/* Put andrew ID in file */
	fprintf(fp_out, "jwuyeh\n"); 
	if(number_of_test_cases>0){
		/*Initialize the values of the array for defensive programming*/
		for(int i=0;i<MAX_NUMBER_OF_LOCATION;i++){

			lcs[i].t = 0.0;
		    lcs[i].x = 0;
		    lcs[i].y = 0;
		}
	}
	else{
		/* case for when test case is zero*/
		fprintf(fp_out,"No test cases");
	}
	/* This is used as the index */
	count = 0; 
	while (fscanf(fp_in, "%f %f %f", &t, &x, &y) > 0)/* fscanf returns values corresponding to line that's read*/
	{

		if(t>=0) //check if time isn't less than 0
		{
			/** Stores the location points **/
			storeLocation(lcs,count, t, int(x), int(y));
			/** Increase the counter after adding the location **/
			count++;
		}
		else
		{
			/** The size of the array equals counter at this point **/ 
			int size = count;
			/** Do insertion sort for the three keys **/
			insertionSorts(lcs, count);
			/** Print the sorted list **/
			for(int p=0; p<count; p++) {
				  fprintf(fp_out, "%6.3f %5d %4d\n", lcs[p].t, lcs[p].x, lcs[p].y);
			 }
			/** print the dashes after the printing the sorted list for a test case **/
			fprintf(fp_out, "-----------------\n");

			/** restart counter for the new test case **/
			count = 0;
		}
	}

	/** Close the files **/
	fclose(fp_in);
	fclose(fp_out);
}

