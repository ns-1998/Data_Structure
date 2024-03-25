/**
 * @file circular_queue.c
 * @author Niraj Soni
 * @brief Circular Queue is Example
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
#define SIZE 5  // Update size

int front, rear;

/**
 * @brief initialize queue.
 * 
 * @param n 
 * @return int* 
 */
int *init_queue(int n){
    int *queue = (int *)malloc(n*sizeof(int));
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
 * @brief check if queue is full i.e. when rear and front are same else both are -1.
 * 
 * @return true -- queue is full
 * @return false -- queue is not full
 */
bool isFull(){
    bool ret = false;

    if(((front == 0) && (rear == SIZE-1)) || ((front==-1) && (rear==-1) && (front==rear)))
        ret = true;

    return ret;
}

/**
 * @brief check if queueu is empty, i.e. front or rear is -1, init state.
 * 
 * @return true -- queue is empty.
 * @return false -- queue is not empty.
 */
bool isEmpty(){
    bool ret = false;

    if(front == -1)
        ret=true;

    return ret;
}

/**
 * @brief Enqueue element if queue is not full.
 * 
 * @param queue 
 * @param num 
 */
void Enqueue(int *queue, int num){
    if(front == -1){
        front = 0;
    }

    if(isFull()){
        printf("Queue is full, fail to Enqueue %d.\n",num);
        return;
    }

    if(rear == SIZE-1)
        rear = -1;

    ++rear;
    queue[rear] = num;
    printf("Enqueue: %d\n",queue[rear]);

    return;
}

/**
 * @brief Dequeue element if queue is not empty.
 * 
 * @param queue 
 */
void Dequeue(int *queue){
    if(isEmpty()){
        printf("Queue is Empty, fail to Dequeue.\n");
        return;
    }

    if(front == SIZE){
        front = 0;
    }

    printf("Dequeue: %d\n",queue[front]);
    
    if(front == rear){
        front = rear = -1;
        return;
    }
    
    ++front;
    return;
}

/**
 * @brief print queue if queue is not empty.
 * 
 * @param queue 
 */
void print_queue(int *queue){
    if(isEmpty()){
        printf("Queue is Empty, nothing to print.\n");
        return;
    }

    int i=0;

    for(i=front; i != rear; i++){
        printf("%d",queue[i]);
        printf(" ");
        
        if(i == SIZE-1)
            i=-1;
    }
    printf("%d\n",queue[i]);

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

    if(q == NULL) {
        printf("Failed to allocate memory for queue.\n");
        return 1;
    }

    Dequeue(q);
    
    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    Enqueue(q, 4);

    print_queue(q);

    Dequeue(q);
    Dequeue(q);
    Dequeue(q);

    // Dequeue(q);
    // Dequeue(q);

    print_queue(q);

    Enqueue(q, 7);
    Enqueue(q, 8);
    Enqueue(q, 9);
    
    print_queue(q);

    Dequeue(q);
    Dequeue(q);
    Dequeue(q);
    Dequeue(q);
    Dequeue(q);

    print_queue(q);

    deinit_queue(q);

    return 0;
}