# Assigning Unique Identification Numbers to Locations in Ant Paths

 This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers. 

   The functionality of the program is defined as follows.
   
   Process a list of 2D ant locations (each location specified by its x and y coordinates and the time
   t that the ant visitedthat location), assign a unique identification number to each distinct location,
   and produce a list of locations and times with no duplicates (i.e. with the same coordinates).

   Input data with test cases is provided in an input file named input.txt.  

   Output for the test case is written to an output file "output.txt"



   Input
   -----

   - The first line of input comprises an integer n (1 <= n <= 10); this indicates the number of test
   cases to be processed, i.e. the number of ant paths, in the input file. It is followed by n sets of 
   locations. Each location comprises three numbers: the time, the x coordinate of the location,
   and the y coordinate of the location. All three are real numbers. The last location in each set is
   signified by a time value less than zero, e.g. -1.0. There are no more than 27000 fixation points
   in one ant path sequence and that the coordinates x and y are in the ge -450 <= x, y <= 450. Finally,
   you can assume that all input provided is valid and contains no errors.


   Output
   ------

   - Andrew ID on first Line
   - A list of sequence of four numbers comprising a unique location identification number, the x coordinate,
   the y coordinate, and the first time that location was encountered on the ant path. Each set of these
   four numbers are written on a separate line. The location is given the integer part of the location
   coordinates.
   - Dashes to delimit each set of four number sequences
 

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
	1 0.000 0 0
	2 1.100 0 1
	3 1.400 0 2
	4 1.600 0 4
	5 1.800 0 5
	--------------
	1 60.063 -28 20
	2 60.781 -29 19
	3 61.710 -30 18
	4 62.332 -31 18
	5 62.638 -32 18
	6 63.350 -31 17
	7 63.656 -30 16
	8 64.250 -29 16
	9 64.456 -29 17
	10 64.667 -28 18
	--------------


   Solution Strategy
   -----------------
   - Read the first line (the number of test cases)
   - Print andrew ID into the output file
   - Check if the test case is greater than zero. If not print the andrew ID into the outfile and the message "no test cases".
   - Then Loop through the location points (till the end of the file) while looking for a time
      where t is -1, and each time check if the the location point is not already in the array. If it is, continue reading without
	  doing anything. 
   - If it is not in the array, add it to the array. A counter (which is index + 1) is used to signify each unique location point. Thus each time an item
      is added, the counter is incremented. Each time a unique location is added to the array, the unique ID number (counter value), time, and
	  the x and y values are printed to the output file. 
   - While looping through, if a time value of -1 is encountered, the index (counter) is restarted and the boundary line is printed to the output file.
   - This counter value is also used as a boundary of the number of array indices to check starting from 0, and because of this, the size of the array
	  used for each test case is limited to the the number of unique items in the list.


   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

   - When number of test cases is zero
   - When there are duplicate location points with different time values
   - When the number of test cases is one
   - When the same location points are given in a different test case (program detects is a different test, and thus not treated as duplicates)
   - When all the location points are the different
   - When all the location points are the same
   - Test with more data than the one provided in the example



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
