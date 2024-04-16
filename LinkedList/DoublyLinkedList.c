/**
 * @file DoublyLinkedList.c
 * @author Niraj Soni
 * @brief Doubly Linked list example
 * @version 0.1
 * @date 2002-01-01
 * 
 * @copyright Copyright (c) 2002
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Global Variables */

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/**
 * @brief Inserts node in middle of LinkedList
 * 
 * @param num 
 */
void insertFromMid(int num){
    int count = 0;

    struct node *test = head;

    while(test != NULL){
        ++count;
        test = test->next;
    }

    test = head;

    for(int i=0; i < count/2; i++){
        test = test->next;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp ->prev = test;
    temp->data = num;
    if(test->next != NULL)
        temp->next = test->next;
    
    if(temp != NULL)
        test->next->prev = temp;
    
    test->next = temp;
}

/**
 * @brief Insert node at head of begining
 * 
 * @param num 
 */
void insertFromFront(int num){
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if(temp == NULL){
        printf("Fail to allocate memory for node.\n");
        return;
    }

    temp->prev = NULL;
    temp->data = num;
    temp->next = head;

    head->prev = temp;

    head = temp;
}

/**
 * @brief Insert node at rear of LinkedList
 * 
 * @param num 
 */
void insertFromRear(int num){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
    if(temp == NULL)
    {
        printf("fail to alloc memory.\n");
        return;
    }
    
    temp->prev = NULL;
    temp->data = num;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        return;
    }

    struct node *test = head;

    while(test->next != NULL){
        test = test->next;
    }

    temp->prev = test;
    test->next = temp;
}

/**
 * @brief Print Linkedlist from head to tail
 * 
 */
void printfwd(){
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief print linkedlist from tail to head
 * 
 */
void printrev(){
    struct node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

/**
 * @brief main function
 * 
 * @return int 
 *         0 -- success
 *         1 -- fail
 */
int main(){
    insertFromRear(1);
    insertFromRear(2);
    insertFromFront(0);
    insertFromMid(-1);

    printfwd();
    printrev();

    return 0;
}