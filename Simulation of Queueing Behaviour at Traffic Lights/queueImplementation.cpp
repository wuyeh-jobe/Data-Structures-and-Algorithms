/************************************************************************/
/*                                                                      */
/* Implementation file for queue implementation with front and rear     */
/*                                                                      */
/*                                                                      */
/* Wuyeh Jobe                                                           */
/* AndrewID: jwuyeh                                                     */
/************************************************************************/

#include "queue.h"
/*** initialize the queue pointer to make sure all subsequent checks on its value are valid ***/


void initialize_queue(QUEUE_TYPE *queue){
	*queue = NULL;
}


/*** empty a queue ***/

NODE_TYPE empty(QUEUE_TYPE *queue) {

   NODE_TYPE p, q;
   
   if (*queue != NULL) {

      /* queue exists: delete all nodes including the header */

      q = *queue;

      while (q->next != NULL) {
         p = q;
         q = q->next;
         free(p);
      }
   }
 
   /* now,  create a new empty one with a header node */
      
   if ((q = (NODE_TYPE) malloc(sizeof(NODE))) == NULL) 
      error("function empty: unable to allocate memory");
   else {
      q->next = NULL;
      *queue = q;
   }
   return(q);
}


/*** test to see if a queue is empty  ***/

int is_empty(QUEUE_TYPE *queue) {
	NODE_TYPE q = *queue;
	if (q == NULL) {
		error("non-existent queue");
	}
	else {
		if (front == NULL) 
			return(TRUE);
		else
			return(FALSE);
	}
}




/*** insert an element in a queue ***/

void enqueue(ELEMENT_TYPE e,  QUEUE_TYPE *queue) {
	
	NODE_TYPE newNode;
	if ((newNode = (NODE_TYPE)malloc(sizeof(NODE))) == NULL){
		error("function insert: unable to allocate memory");
	}
	else{
		newNode->element = e;
		newNode -> next = NULL;
		if(is_empty(queue))
			front = rear = newNode;
		else{
			rear -> next = newNode;
			rear = newNode;
		}
	}
}


/*** delete an element in a queue ***/

int dequeue(QUEUE_TYPE *queue) {
	if(is_empty(queue)){
		printf("all items deleted");
		return 0;
	}
	else{
		NODE_TYPE temp = front;
		front = front -> next;
		//printf("\nDeleted element: %d\n", temp->element.car_num);
		free(temp);
		return 1;
	}
}


/*** retrieve first element in a queue ***/

ELEMENT_TYPE retrieve(QUEUE_TYPE *queue) {

	if (*queue == NULL) {
		error("cannot retrieve from a non-existent queue");
	}
	else {
		return(front->element);
	}
}


/*** print all elements in a queue ***/

int print(QUEUE_TYPE *queue) {
	printf("Contents of queue: \n");
	if(is_empty(queue))
		error("Queue is Empty\n");
	else{
		NODE_TYPE temp = front;
		while(temp->next != NULL){
			printf("%d: \n",temp->element.time_arrived);
			temp = temp -> next;
		}
		printf("%d: \n",temp->element.time_arrived);
	}

	return(0);
}


/*** error handler: print message passed as argument and take appropriate action ***/

void error(char *s) {
	printf("Error: %s\n",s);
	exit(0);
}

/*** assign values to an element ***/

void assign_element_values (ELEMENT_TYPE *e, int time_arrived) {
	/*e->string = (char *) malloc(sizeof(char) * (strlen(s)+1));
	if (e->string==NULL) printf("Failed to allocate memory \n"); 

	strcpy(e->string, s);*/

	//e->car_num = car_num;
	e->time_arrived = time_arrived;
}