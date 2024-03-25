/**
 * @file queue.c
 * @author Niraj Soni
 * @brief Basic Queue Example
 * @version 0.1
 * @date 2024-03-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Global Variables */
#define SIZE 5  //Update size of queue

int rear, front;

/**
 * @brief Function to initialize queue
 * 
 * @param num 
 * @return int* 
 */
int* init_queue(int num){
    rear = front = -1;
    int *queue = (int *)malloc(num * sizeof(int));

    if(queue == NULL){
        printf("Fail to allocate memory\n");
    }
    
    return queue;
}

/**
 * @brief Free memory allocated to queue
 * 
 * @param queue 
 */
void deinit_queue(int *queue){
    if(queue == NULL){
        printf("Queue is not initalized, unable to deinit\n");
        return;
    }
    
    rear = front = -1;
    free(queue);
    return;
}

/**
 * @brief check if queue is full, i.e. when front=0 and rear=SIZE-1
 * 
 * @return true if queue is full.
 * @return false if queue is not full.
 */
bool isFull(){
    bool ret = false;
    
    if(rear == SIZE-1)
        ret = true;

    return ret;
}

/**
 * @brief check if queue is Empty, i.e. front & rear == -1 no elemet added yet.
 * 
 * @return true 
 * @return false 
 */
bool isEmpty(){
    bool ret;
    
    if(front==-1)
        ret = true;
    
    return ret;
}

/**
 * @brief Add Element into Queue.
 * 
 * @param queue 
 * @param n 
 */
void Enqueue(int *queue, int n){
    if(isFull()){
        printf("Queue is Full, unable to add more element\n");
        return;
    }

    if(rear == -1)
        front = rear = 0;

    queue[rear] = n;
    printf("Enqueue: %d\n",queue[rear]);
    ++rear;
    
    return;
}

/**
 * @brief Remove element from queue.
 *        set front and rear to -1 if no element left in queue.
 * 
 * @param queue 
 */
void Dequeue(int *queue){
    if(isEmpty()){
        printf("Queue is Empty, unable to remove more element\n");
        return;
    }

    printf("Dequeue: %d\n",queue[front]);
    ++front;

    if(front == rear)
        front = rear = -1;

    return;
}

/**
 * @brief Print Entire queue, all elements in queue.
 * 
 * @param queue 
 */
void print_queue(int *queue){
    if(isEmpty()){
        printf("Queue is Empty, nothing to print\n");
        return;
    }

    for(int i=front; i < rear; i++){
        printf("%d",queue[i]);
        if(i == rear-1)
            printf("\n");
        else
            printf(" ");
    }

    return;
}

/**
 * @brief Main function
 * 
 * @return int 
 *         0 -- success
 *         1 -- fail
 */
int main(){
    int *q = init_queue(SIZE);

    if(q == NULL){
        printf("No memory available to allocate for queue\n");
        return 0;
    }

    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);

    print_queue(q);

    Dequeue(q);
    Dequeue(q);

    print_queue(q);
    deinit_queue(q);

    return 0;
}