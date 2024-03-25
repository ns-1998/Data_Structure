/**
 * @file De-queue.c
 * @author Niraj Soni
 * @brief Double Ended Queue
 * @version 0.1
 * @date 2024-03-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Global Variables */
#define SIZE 5	// Update size of queue

int front, rear;

/**
 * @brief function checks if queue is empty before
 * 		  removing element or printing queue.
 * 
 * @return true -- if queue is empty.
 * @return false  -- if queue is not empty.
 */
bool isEmpty(){
	bool ret = false;

	if(front == -1)
		ret = true;
	
	return ret;
}

/**
 * @brief check if queue is full before adding new elemmt.
 * 
 * @return true -- if queue is full.
 * @return false  -- if queue is not full.
 */
bool isFull(){
	bool ret = false;

	if(((front == 0) && (rear == SIZE-1)) || (front == rear+1))
		ret = true;
	
	return ret;
}

/**
 * @brief initalize queue
 * 
 * @param size 
 * @return int* 
 */
int *init_queue(int size){
	int *queue = (int *)malloc(size * sizeof(int));
	front = rear = -1;

	return queue;
}

/**
 * @brief deinit queue
 * 
 * @param queue 
 */
void deinit_queue(int *queue){
	if(queue == NULL){
        printf("Queue is not initalized, unable to deinit\n");
        return;
    }

	front = rear = -1;
	free(queue);
	return;
}

/**
 * @brief print queue till front != rear when front=rear loop break
 * 		  so need to print rear element separately and set queue to 0 when at end.
 * 
 * @param queue 
 */
void print_queue(int *queue){
	if(isEmpty()){
		printf("Queue is Empty, nothing to print.\n");
		return;
	}

	int i;

	for(i=front; i != rear; i++){
		if(i == SIZE){
			i = -1;
			continue;
		}
		
		printf("%d",queue[i]);
		printf(" ");
	}
	printf("%d",queue[i]);
	printf("\n");
}

/**
 * @brief delete_from_rear function dequeue element from rear
 * 
 * @param queue 
 */
void delete_from_rear(int *queue){
	if(isEmpty()){
		printf("Dequeue is Empty can't delete from queue.\n");
		return;
	}

	if(rear == -1)
		rear = SIZE-1;	

	printf("Dequeue from rear %d\n",queue[rear]);
	rear = rear-1;

	if(front == rear+1)
		front = rear = -1;

	return;
}

/**
 * @brief delete_from_front function dequeue element from front
 * 
 * @param queue 
 */
void delete_from_front(int *queue){
	if(isEmpty()){
		printf("Dequeue is Empty can't delete from queue.\n");
		return;
	}

	printf("Dequeue from front %d\n",queue[front]);
	front = front+1;

	if(front == SIZE)
		front = 0;	

	if(front == rear+1)
		front = rear = -1;

	return;
}

/**
 * @brief insert_from_front function enqueue element from front
 * 
 * @param queue 
 * @param num 
 */
void insert_from_front(int *queue, int num)
{
	if(isFull()){
		printf("Dequeue is full can't add %d\n",num);
		return;
	}

	if(front == -1)
		front = SIZE;
	
	if(front == 0)
		front = SIZE;

	front = front-1;
	queue[front] = num;
	printf("Enqueue from front %d\n",queue[front]);

	return;
}

/**
 * @brief insert_from_rear function enqueue element from rear
 * 
 * @param queue 
 * @param num 
 */
void insert_from_rear(int *queue, int num){
	if(isFull()){
		printf("Dequeue is full can't add %d\n",num);
		return;
	}

	if(rear == SIZE)
		rear = -1;

	rear = rear+1;
	queue[rear] = num;
	printf("Enqueue from rear %d\n",queue[rear]);

	return;
}

/**
 * @brief Main function
 * 
 * @return int 
 * 		   0 -- success
 * 		   1 -- fail
 */
int main(){
	int *q = init_queue(SIZE);

	if(q == NULL) {
		printf("Fail to allocate memory for queue\n");
		return 1;
	}

	delete_from_rear(q);

	insert_from_rear(q, 1);
	insert_from_rear(q, 2);
	insert_from_front(q, 3);
	insert_from_front(q, 4);
	insert_from_rear(q, 7);
	insert_from_front(q, 8);

	print_queue(q);

	delete_from_rear(q);
	delete_from_front(q);
	delete_from_rear(q);
	delete_from_front(q);

	print_queue(q);

	insert_from_rear(q, 5);
	insert_from_front(q, 6);

	print_queue(q);

	 deinit_queue(q);

	return 0;
}
