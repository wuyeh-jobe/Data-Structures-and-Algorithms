/* 

tlQueuingImplementation.cpp - implementation file for a program named tlQueuing
============================================================================

This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 

Please refer to the application file - tlQueuingApplication.cpp - for details of the functionality of this program


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
24/02/2020

*/


#include "tlQueuing.h"
#include "queue.h"

void prompt_and_exit(int status) {
	//printf("Press any key to continue and close terminal\n");
	getchar();
}

/* Get the waiting time for a car */
long int get_wait_time(long int time_arrived, long int time_dequeued){
	return (time_dequeued - time_arrived);
}

/* Get the maximum waiting time given the current waiting time and the previous max */
long int get_max_wait_time(long int cur_wait_time, long int previous_max){
	long int max_wait_time = 0;
	if (cur_wait_time > previous_max) {
		max_wait_time = cur_wait_time; //update max wait time
	}
	else{
		max_wait_time = previous_max;
	}
	return max_wait_time;
}

/** This function writes the outputs file to the file **/
void stats_and_write_to_file(int queue_lengths[], int n_queues, int ave_queue_length,int max_waiting_time, int ave_waiting_time, FILE* file){
	insertionSorts(queue_lengths, n_queues); //sort list for the purpose of calculating median and max length
	/*for(int i=0;i<n_queues;i++){
	printf("%d\n",queue_lengths[i]);
	}*/
	int max_queue_length = queue_lengths[n_queues-1]; //get the max queue length
	int median = 0;
	int middle = n_queues/2; //middle of the array

	/** Check if array size is even or odd and calculate median appropriately **/
	if (n_queues % 2 == 0){
		/** Array size is even so median is calculated by adding two middle numbers
		and dividing by two **/
		median = (queue_lengths[middle] + queue_lengths[middle-1])/2;
	}
	else{
		/** Array size is odd so median is calculated by selecting the middle number **/
		median = queue_lengths[middle];
	}


	fprintf(file, "Average length: %d cars\n", ave_queue_length);
	fprintf(file, "Median length: %1s%d cars\n"," ", median);
	fprintf(file, "Maximum length: %d cars\n", max_queue_length);
	fprintf(file, "Average wait: %2s%d s\n"," ", ave_waiting_time);
	fprintf(file, "Maximum wait: %2s%d s\n"," ", max_waiting_time);
	fprintf(file, "\n");
}

/** Implementation of the insertion **/
void insertionSorts(int queue_lengths[], int size) {
	int i,j, temp;
	for (i=1; i<size; i++) {
		j=i;
		while ((j>0) && (queue_lengths[j] < queue_lengths[j-1])){
			temp = queue_lengths[j-1]; // swap
			queue_lengths[j-1] = queue_lengths[j];
			queue_lengths[j] = temp;
			j = j-1;
		}
	}
}


/* Generate a random sample from a Poisson distribution with a given mean, lambda */
/* Use the function rand to generate a random number */
int samplePoisson(double lambda) {
	static bool first_call = true;
	int count;
	double product;
	double zero_probability;
	/* Seed the random-number generator with current time so */
	/* that the numbers will be different every time we run */
	if (first_call) {
		srand( (unsigned)time( NULL ));
		first_call = false;
	}
	count = 0;
	product = (double) rand() / (double) RAND_MAX;
	zero_probability = exp(-lambda);
	while (product > zero_probability) {
		count++;
		product = product * ((double) rand() / (double) RAND_MAX);
	}
	return(count);
}

/** The main trafic light simulation function. 
It takes in inputs as key value pairs and use them to do the simulation
The file passed is to write to the output file**/
void simulate(Key_Value_Pair pairs[], FILE* file){

	int arrival_rate_input = pairs[0].value; // the arrival rate in cars per minute
	double arrival_rate = ((float) arrival_rate_input) / (60 * 1000); // the arrival rate in cars per millisecond
	long int increment = pairs[3].value; // the period of each simulation interval in milliseconds
	int runtime_input = pairs[2].value; // runtime in minute
	long int runtime = runtime_input * 60 * 1000; // runtime in milliseconds
	int departure_input = pairs[1].value; //average departure time per car in seconds
	long int departure_time = departure_input * 1000; //average departure time per car in milliseconds
	int green_input = pairs[6].value; //green input in seconds
	long int green_duration = green_input * 1000; //green duration in milliseconds
	int red_input = pairs[4].value; //red duration in seconds
	long int red_duration = red_input * 1000; //red duration in milliseconds
	int amber_input = pairs[5].value; //amber duration in seconds
	long int amber_duration =  amber_input*1000; //amber duration in milliseconds

	int count; // the number of cars that arrive in any given
	// simulation interval (i.e time increment)
	double lambda; // the mean number of cars that arrive in any one
	// similation interval (i.e. time increment)


	QUEUE_TYPE queue; //Declare queue type
	ELEMENT_TYPE e, dequeued_element; //Declare element  type
	initialize_queue(&queue);  //Initiallize queue
	empty(&queue); // Ensure queue is empty
	int total_n_cars = 0; //Keep count of total number of cars
	long int total_waiting_time = 0; //Keep track of total waiting time
	long int max_waiting_time = 0; //keep track of maximum waiting time so far
	long int st = 0; //simulation interval variable
	long int departure_timer = 0; //keep track of the number of milliseconds since last car left
	/** Keep track of the light sequence (1 represents RED, 2 represents GREEN, 3 represents amber) **/
	int light_sequence = RED; //Light sequence, initial state is red
	int queue_length = 0; //queue length for each interval
	int total_of_queue_lengths = 0; //Total of the queue lengths for each interval
	int queue_length_for_interval[MAX_QUEUES]; //array to keep track of the queue lengths
	int ql_index = 0; //index to for the queue length values added to the array above
	long int light_timer = 0; //keep track of the duration each light sequence show have
	long int car_wait_time = 0; //keep track of the wait for each car

	/** Writing the original values to the output file **/
	fprintf(file, "Arrival rate: %2s%d cars per min\n"," ", pairs[0].value);
	fprintf(file, "Departure rate: %d s per car\n", pairs[1].value);
	fprintf(file, "Runtime: %7s%d min\n"," ", pairs[2].value);
	fprintf(file, "Time increment: %d ms\n", pairs[3].value);
	fprintf(file, "Light sequence: Green %d s; Amber %d s; Red %d s\n", pairs[6].value,pairs[5].value,pairs[4].value);

	/* Do the simulation only if the runtime is greater than 0 */
	if(runtime_input<=0 /*|| increment<=0*/){
		//fprintf(file, "==>No simulation statistics since the the runtime is 0\n\n");
		fprintf(file, "Average length: %d cars\n", 0);
		fprintf(file, "Median length: %1s%d cars\n"," ", 0);
		fprintf(file, "Maximum length: %d cars\n", 0);
		fprintf(file, "Average wait: %2s%d s\n"," ", 0);
		fprintf(file, "Maximum wait: %2s%d s\n"," ", 0);
		fprintf(file, "\n");
		return;
	}
	if(arrival_rate_input<=0){
		fprintf(file, "Average length: %d cars\n", 0);
		fprintf(file, "Median length: %1s%d cars\n"," ", 0);
		fprintf(file, "Maximum length: %d cars\n", 0);
		fprintf(file, "Average wait: %2s%d s\n"," ", 0);
		fprintf(file, "Maximum wait: %2s%d s\n"," ", 0);
		fprintf(file, "\n");
		//fprintf(file, "==>No simulation statistics since the arrival rate is 0\n\n");
		return;
	}
	if(runtime_input>10){
		fprintf(file, "==>No simulation statistics since runtime is greater than 10\n\n");
		return;
	}


	while(st < runtime){
		/* the Poisson distribution mean, lambda, is the arrival rate of cars during */
		/* the simulation interval, i.e. arrival rate per millisecond multiplied by */
		/* the number of milliseconds in each simulation interval */
		lambda = arrival_rate * increment;
		/* usage of samplePoisson */
		/* Compute the number of cars that have arrived in the current simulation interval */
		count = samplePoisson(lambda);
		total_n_cars = total_n_cars + count;//add to running total of the number of cars 
		for (int c=1; c<=count;c++){
			assign_element_values(&e, st); //assing the value of element as time a car arrived
			enqueue(e, &queue); //Put element in the queue
			queue_length = queue_length + 1; //increase the length of the queue
		}

		departure_timer  = departure_timer  + increment; //increment the departure timer
		light_timer = light_timer + increment; //increment the light timer

		/** Check for light timer and light sequence and change to new light sequence appropriately  **/
		if ((light_sequence == GREEN) && (light_timer> green_duration)){
			light_sequence  = AMBER;
			light_timer = 0;
		}
		else if ((light_sequence == AMBER) && (light_timer> amber_duration)){
			light_sequence  = RED;
			light_timer = 0;
		}
		else if ((light_sequence == RED) && (light_timer> red_duration)){
			light_sequence  = GREEN;
			light_timer = 0;
			departure_timer = 0;
		}


		/** Check if departure timer is greater than average departure time read from the file
		if departure timer is greater and the light is green, then the car should move (i.e. dequeued**/

		if(departure_timer > departure_time){
			/** check if the light sequence is GREEN **/
			if (light_sequence == GREEN){
				/** Check if the queue is not already empty **/
				if(!is_empty(&queue)){
					dequeued_element = retrieve(&queue); // get the element to be dequeued for getting time car arrived
					dequeue(&queue); //remove car from queue
					car_wait_time = get_wait_time(dequeued_element.time_arrived, st); //calculate wait for a car
					/** increment total waiting time for calculating average **/
					total_waiting_time = total_waiting_time + car_wait_time; //running total of waiting time
					queue_length = queue_length - 1; //decrease queue length
					departure_timer = 0; //reset departure timer
					/** keep track of the max wait time so far **/
					max_waiting_time = get_max_wait_time(car_wait_time, max_waiting_time);
				}
			}
		}


		queue_length_for_interval[ql_index] = queue_length; //put queue length in the array for calculating median
		ql_index = ql_index + 1; //increase the index
		total_of_queue_lengths = total_of_queue_lengths + queue_length; //increase the running total of the queue length
		//printf("arrival_rate_input, increment, runtime_input, count: %d, %d, %d, %d \n",arrival_rate_input,increment,runtime_input, count);
		st = st + increment;
	}

	/** Dequeue the remaining cars in the queue and add their waiting time to **/
	for (int i = 0; i< queue_length;i++){
		if (!is_empty(&queue)){
			dequeued_element = retrieve(&queue); // get the element to be dequeued for getting the time car arrived
			dequeue(&queue); //dequeue the car
			car_wait_time = get_wait_time(dequeued_element.time_arrived, runtime); //calculate wait for a car
			/** increment total waiting time for calculating average **/
			total_waiting_time = total_waiting_time + car_wait_time;
			/** keep track of the max wait time so far **/
			max_waiting_time = get_max_wait_time(car_wait_time, max_waiting_time);
		}
	}
	/** Calculating and printing statistics **/

	/* The average waiting time is the total waiting time divided by total number of cars 
	It is divided by 1000 to convert from milliseconds to seconds */
	int average_waiting_time; //for calculating average waiting time
	average_waiting_time =  (total_waiting_time/total_n_cars)/1000;
	/* Convert max waiting time to seconds */
	int max_waiting_time_s = max_waiting_time/1000;
	/** The average queue length is the total of queue lengths divided by total number of queues **/
	int ave_queue_length = total_of_queue_lengths / ql_index;

	/** Call the function that calculate and prints statistics **/
	stats_and_write_to_file(queue_length_for_interval, ql_index,ave_queue_length, max_waiting_time_s, average_waiting_time, file);

}
