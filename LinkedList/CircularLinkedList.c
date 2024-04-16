/**
 * @file CircularLinkedList.c
 * @author Niraj Soni
 * @brief 
 * @version 0.1
 * @date 2024-04-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Global vairables */
struct linkedlist{
    int data;
    struct linkedlist *next;
};

struct linkedlist *head = NULL;

/**
 * @brief Insert node in middle
 * 
 * @param num 
 */
void insertFromMiddle(int num){
    struct linkedlist *temp = (struct linkedlist *)malloc(sizeof(struct linkedlist));

    temp->data = num;
    temp->next = NULL;

    int count = 0;
    struct linkedlist *test = head;

    while(test->next != head){
        ++count;
        test = test->next;
    }

    test = head;

    for(int i=0; i < count/2; i++){
        test = test->next;
    }

    temp->next = test->next;
    test->next = temp;
}

/**
 * @brief insert node at head
 * 
 * @param num 
 */
void insertFromHead(int num){
    struct linkedlist *temp = (struct linkedlist *)malloc(sizeof(struct linkedlist));

    temp->data = num;
    temp->next = head;

    struct linkedlist *test = head;

    while(test->next != head){
        test = test->next;
    }

    head = temp;

    test->next = head;

}

/**
 * @brief insert node from rear
 * 
 * @param num 
 */
void insertFromRear(int num)
{
    struct linkedlist *temp = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    
    temp->data = num;
    temp->next = head;

    if(head == NULL)
    {
        head = temp;
        head->next = head;
        return;
    }

    struct linkedlist *test = head;

    while(test->next != head){
        test = test->next;
    }

    test->next = temp;
}

/**
 * @brief print doubly linkedlist
 * 
 */
void printDLL(){
    struct linkedlist *temp = head;

    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != head);
}


/**
 * @brief main function
 * 
 * @return int 
 */
int main(){

    insertFromRear(1);
    insertFromRear(2);
    insertFromHead(0);
    insertFromMiddle(-1);

    printDLL();

    return 0;
}