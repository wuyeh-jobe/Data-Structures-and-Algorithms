/* 

tlQueuingApplication.cpp - application file for a program named tlQueuing
=====================================================================

This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 

The functionality of the program is defined as follows.

	Write a program to simulate the queuing behaviour of cars in a single lane of traffic as a
	function of the arrival rate of the cars and the traffic light sequencing, i.e. the amount of time
	the lights stay green, amber, and red. The following information is provided as input to the
	program.
	• The arrival rate in vehicles per minute.
	• The average departure time per car in seconds.
	• The running time for the simulation, specified in minutes.
	• The time increment to use for each discrete interval of simulation, specified in
	milliseconds.
	• The traffic light sequencing given by the time the lights stay green, amber, and red,
	specified in seconds.
	The program should calculate the average, median, and maximum lengths of the queue of cars
	and average and maximum waiting time of the cars during the simulation period.
	The program should impose no restriction on the length of the queue.
	The maximum running time is 10 minutes and the minimum time increment is 10
	milliseconds.
	Cars can only proceed when the light is green.
	The arrival of vehicles should be modelled using a Poisson distribution, using the average
	arrival rate as a parameter.

Input data with a test case message is provided in an input file named input.txt.  
This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
where the jwuyeh .exe file resides, the filename used when opening the file is "../data/input.txt".

Output for the test case is written to an output file "../data/output.txt"


Input
-----

-	The first line of input comprises an integer N (0 < N < 1000); this determines the number of
	simulation scenarios in the input file (i.e. the number of sets of seven simulation parameters:
	arrival rate, departure rate, running time, time increment, red light duration, amber light
	duration, green light duration). It is followed by N sets of seven key-value pairs, each pair
	specifying the input parameter and its value. The key-value pairs can appear in any order.
	There will be only one key-value pair for each parameter. All input
	provided is valid and contains no errors


Output
------

- The program writes the statistics in tabular form to a text file, along with the student id
	and the input parameters.


Sample Input
------------

	3
	Arrival 10
	Departure 5
	Runtime 5
	Increment 10
	Green 10
	Amber 1
	Red 30
	Runtime 5
	Arrival 20
	Departure 2
	Increment 100
	Red 15
	Green 5
	Amber 1
	Runtime 2
	Arrival 20
	Departure 10
	Increment 50
	Red 120
	Green 0
	Amber 0


Sample Output
-------------
	jwuyeh
	Arrival rate:   10 cars per min
	Departure rate: 5 s per car
	Runtime:        5 min
	Time increment: 10 ms
	Light sequence: Green 10 s; Amber 1 s; Red 30 s
	Average length: 19 cars
	Median length:  22 cars
	Maximum length: 42 cars
	Average wait:   121 s
	Maximum wait:   238 s

	Arrival rate:   20 cars per min
	Departure rate: 2 s per car
	Runtime:        5 min
	Time increment: 100 ms
	Light sequence: Green 5 s; Amber 1 s; Red 15 s
	Average length: 35 cars
	Median length:  36 cars
	Maximum length: 68 cars
	Average wait:   114 s
	Maximum wait:   207 s

	Arrival rate:   20 cars per min
	Departure rate: 10 s per car
	Runtime:        2 min
	Time increment: 50 ms
	Light sequence: Green 0 s; Amber 0 s; Red 120 s
	Average length: 16 cars
	Median length:  17 cars
	Maximum length: 32 cars
	Average wait:   61 s
	Maximum wait:   116 s


Solution Strategy
-----------------
	- Print andrew ID to the output file
	- Reading the input for each test case and and storing them
		- Read the first line as a string and convert into into a number (this represents the number of test cases)
		- Then for each test case,  read the seven sets of key value pairs. These key value pairs are stored in an 
		  array of struct that has a key as a string and value as integer. This array is then passed into the function
		  that does the simulation for a given test case.

	- Printing the original inputs to the output file
	    - After reading the inputs, they are printed to the output file in the specified format

	- Checking for special case
		- When the arrival rate is zero, make all the statistics are zero and stop the program from continuing 
		  else proceed to section below

	- Simulation of enqueing and dequeing and keeping track of values for statistic computations
		- The simulation function takes in the key value pairs (and the output file, for later) and convert the raw 
		  values into milliseconds (except for increment, which is already in milliseconds) 
		- After converting the raw input values, we calculate the number of cars that arrive within a certain interval
		  using Poisson Distribution function. The poisson distributin function returns the number of cars that arrive
		  given the lamda (the product of the arrival rate and the increment in milliseconds). This is used to simulate
		  the number of cars that arrive within a given interval. Thus, the simulation loop, counts from 0 to runtime
		  for a specific increment and for each increment:
		- The number of cars that have been returned by the poisson distribution are added to a queue (implementation 
		  explained below) one by one with the time that they were added to the queue, and each time increase the 
		  variable that keeps track of the queue length for each interval. This number of cars returned by the poisson
		  distribution is also added to a running total of the number of cars so far.
		- To simulate when the car should move (removed from the queue) two variables, light_timer and departure_timer 
		  are used to keep track of when the next car should move and when the light should change respectively. Another
		  variable, light_sequence is used to keep track of the light that is currently on. The initial state of the light
		  is red. The light timer and the daparture timer are both increased by the increment value. If the departure timer
		  is greater than the average departure period read from the file and the light is green, then the car is removed
		  from the queue. Whenever a  car is removed from the queue, it's waiting time is calculated by subtracting the time 
		  it arrived from current time (given by the sum of the increments so far), and this waiting time is added to the 
		  total waiting time so far. When the waiting time for a car just dequeued is greater than that of the previous 
		  (intial value is 0), the maximum waiting time is updated to this new value. A After a car has left (dequeued),
		  the departure timer is restarted to begin counting for when the next car should leave, and the queue length is
		  reduced by one.
		- During the simulation, if the light_sequence is green and the light_timer is greater than
		  the duration for green, it is changed to amber. If the light_sequence is amber and the light_timer is greater than
		  the duration for amber, it is changed to red. If light_sequence is red and the ligh_timer is greater than the duration
		  for red, it is changed to green. Each time the light sequence is changed, the light_timer is reset to 0. Also, when 
		  the light is changed from red to green, the departure timer is reset to 0 to restart counting for when the next 
		  car should leave.
		- For each interval, the queue length is added to a running total of queue lengths and each queue length is stored in 
		  an array to calculate the median. Each time a queue length is added, an index variable is incremented by one. 
		  This index also signifies the total number of queues produced during the simulation period. 
		- After the simulation loop is ended (runtime is exausted), if there are cars in the queue (determined by the value of
		  length of the last queue, they are dequeued and their waiting times are added to the maximum waiting time and also used
		  to update the maximum waiting time if any of them have a higher waiting time.

	- Calculation of statistics
		- The maximum waiting time is the final value of maximum waiting after all the cars have been dequeued the simulation has ended
		- The average waiting time is the total waiting time divided by the total number of cars
		- The average queue length is the running total of queue lengths divided by the number of queues during the simulation
		- The median queue length calculated as follows:
			- Sorting the array of queue lengths using insertion sort
			- Find the middle of the array by doing integer division (size of the array divide by 2)
			- Check if the size is even or odd using modulo
			- If the size is even, add the two items in the middle (values as at index the middle index and middle-1 index) and divide them by 2
			- If the size is odd, just select the value at the middle index
		- The maximum queue length is the last value in the sorted array for queue legths

	- Printing statistics to the file
		- These statistics are printed to the output in the specified format
	
	Note: Queue Implementation
		- The queue implemented has front and rear and the enqueue and dequeue have constant time complexity


Test Strategy
-------------
	The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

	- When the maximum runtime is 10 minutes and minimum increment is 10ms
	- When the arrival rate is 0
	- When the green light duration is equivalent to the runtime and the rest have 0 s duration
	- When the red light duration is equivalent to the runtime and the rest have 0 s duration
	- When the green light duration is equivalent to the runtime and the rest have 0 s duration and depature time 0 s
	- When the green light duration is equivalent to the runtime and the rest have durations more than 0 s
	- When the amber light duration is equivalent to the runtime and the rest have 0 durations
	- When the red light duration is equivalent to the runtime and the rest have durations more 0 s
	- When all the lights durations are 0 s

Time complexity
---------------
	-  Reading the test cases O(N) where N is the number of simulation scenarious
	-  Simulation loop is O(R/I) complexity where R is the runtime and the I is the increment
	-  Enqueuing all cars has O(C)*O(R/I) complexity where C is the count of cars returned by the poisson distribution
	-  Enqueing is constant time because a rear pointer is used
	-  Sorting the array of queue lengths has O((R/I)^2) complexity because an insertion sort is used
	-  Since the major functions calls vary in their input, it is safe to say that the time complexity of the algorithm
		is O(n^2) which is produced by the sorting algoritm



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

#include "tlQueuing.h"

void main() {

	/**Declare the  files variables**/
	FILE *fp_in, *fp_out;
	char input_string[STRING_LENGTH]; // a line read from the input file
	keyword key; // the key string when reading parameters
	int value; // the value when reading parameters
	int N; //Get number of simulation scenarios
	Key_Value_Pair pairs[NUMBER_OF_KEYS];
	keyword keylist[NUMBER_OF_KEYS] = {
		"arrival",
		"departure",
		"runtime",
		"increment",
		"red",
		"amber",
		"green"
	};

	for(int i=0; i<NUMBER_OF_KEYS;i++){
		strcpy(pairs[i].key, keylist[i]);
	}
	/** Opens the input file for reading **/
	if ((fp_in = fopen("../data/input.txt","r")) == 0) {
		printf("Error can't open input input.txt\n");
	}

	/** Open the output file to write the result**/
	if ((fp_out = fopen("../data/output.txt","w")) == 0) {
		printf("Error can't open output output.txt\n");
	}

	fprintf(fp_out, "jwuyeh\n"); //put andrew id into file
	fgets(input_string, STRING_LENGTH, fp_in);
	sscanf(input_string, "%d", &N);
	printf("Simulating for %d test cases\n", N);

	for (int i=0; i<N;i++){
		for (int j=0; j < NUMBER_OF_KEYS; j++) {
			fgets(input_string, STRING_LENGTH, fp_in); // read a line from the input file
			//printf("Input string: %s",input_string); // writes it out to the terminal to check
			/* extract the key */
			sscanf(input_string, " %s %d", key, &value); // extracts the key and the value from the string

			/* convert the key to lower case to be safe */
			for (int c=0; c < (int) strlen(key); c++){
				key[c] = tolower(key[c]);
			}
			for (int b=0; b<NUMBER_OF_KEYS;b++){
				if (strcmp(key,pairs[b].key) == 0) {
					/* use b to select the variable to which value should be assigned */
					pairs[b].value = value;
					break;
				}
			}

		}
		simulate(pairs, fp_out); //call the simulation function
	}

	fclose(fp_out);
	fclose(fp_in);
	//prompt_and_exit(0);
}
