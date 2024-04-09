/**
 * @file LinkedList.c
 * @author Niraj Soni
 * @brief 
 * @version 0.1
 * @date 2024-04-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/** Global Variables */

#define MAX 5

int cnt = 0;

/** LinkedList Structure */
struct LinkedList
{
    int data;
    struct LinkedList *next;
};

/** Local Functions */

/**
 * @brief Insert Node in middle of LinkedList
 * 
 * @param list 
 * @param num 
 */
void InsertMid(struct LinkedList **list, int num){
    if(cnt == MAX){
        printf("LinkedList is full.\n");
        return;
    }

    struct LinkedList *temp = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    if(temp == NULL){
        printf("Fail to create node.\n");
        return;
    }
    temp->data = num;
    temp->next = NULL;

    if(*list == NULL){
        *list = temp;
        ++cnt;
        return;
    }

    int count=0;
    struct LinkedList *t = *list;

    while(t != NULL){
        ++count;
        t = t->next;
    }

    t = *list;

    for(int i=0; i < (count/2)-1; i++){
        t = t->next;
    }

    temp->next = t->next;
    t->next = temp;

    ++cnt;
}

/**
 * @brief Insert Node at front of LinkedList
 * 
 * @param list 
 * @param num 
 */
void InsertFront(struct LinkedList **list, int num){
    if(cnt == MAX){
        printf("LinkedList is full.\n");
        return;
    }
    struct LinkedList *temp = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    if(temp == NULL){
        printf("fail to create node.\n");
        return;
    }

    temp->data = num;
    temp->next = *list;
    *list = temp;
    ++cnt;
}

/**
 * @brief Insert Node at rear of LinkedList
 * 
 * @param list 
 * @param num 
 */
void InsertRear(struct LinkedList **list, int num){
    if(cnt == MAX){
        printf("LinkedList is full.\n");
        return;
    }
    struct LinkedList *temp = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    struct LinkedList *t = *list;

    if(temp == NULL){
        printf("Fail to allocate memory for node.\n");
        return;
    }

    temp->data = num;
    temp->next = NULL;

    if(*list == NULL){
        *list = temp;
        ++cnt;
        return;
    }

    while(t->next != NULL){
        t = t->next;
    }

    t->next = temp;

    ++cnt;
}

/**
 * @brief Delete Node from rear of the LinkedList
 * 
 * @param list 
 */
void deleteRear(struct LinkedList **list){

    if(*list == NULL){
        printf("LinkedList is Empty.\n");
        return;
    }


    if((*list)->next == NULL){
        *list = NULL;
        --cnt;
        return;
    }
    
    struct LinkedList *temp = *list;

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    --cnt;
}

/**
 * @brief Delete Node at front of the LinkedList
 * 
 * @param list 
 */
void deleteFront(struct LinkedList **list){

    if(*list == NULL){
        printf("LinkedList is Empty.\n");
        return;
    }

    *list = (*list)->next;
    --cnt;
}

/**
 * @brief Delete Node at Middle of the LinkedList
 * 
 * @param list 
 */
void deleteMid(struct LinkedList **list){
    if(*list == NULL){
        printf("LinkedList is Empty.\n");
        return;
    }
    
    if((*list)->next == NULL){
        *list = NULL;
        --cnt;
        return;
    }

    struct LinkedList *t = *list, *temp;

    int count=0;

    while(t != NULL){
        ++count;
        t = t->next;
    }

    t = *list;

    for(int i=0; i < (count/2); i++){
        temp = t;
        t = t->next;
    }

    temp->next = t->next;
    --cnt;
}

/**
 * @brief Print Whole LinkedList
 * 
 * @param list 
 */
void Print_ll(struct LinkedList **list){
    if(*list == NULL){
        printf("LinkedList is Empty.\n");
        return;
    }

    struct LinkedList *temp = *list;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Find node with data in LinkedList
 * 
 * @param list 
 * @param num 
 */
void FindElement(struct LinkedList **list, int num){
    struct LinkedList *temp = *list;

    while(temp != NULL){
        if(temp->data == num){
            printf("Node found.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Node not found.\n");
}

/**
 * @brief sort LinkedList
 * 
 * @param list 
 */
void sort_ll(struct LinkedList **list){
    struct LinkedList *prev = *list, *t, *temp = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    for(; prev != NULL; prev = prev->next){
        for(t=prev->next; t != NULL; t=t->next){
            if(prev->data > t->data){
                temp->data = prev->data;
                prev->data = t->data;
                t->data = temp->data;
            }
        }
    }
    free(temp);
}

/**
 * @brief Process Find Operation of given data in LinkedList
 * 
 * @param list 
 */
void find(struct LinkedList **list){
    int num = 0;

    printf("Enter Number to search");
    scanf("%d",&num);

    FindElement(list, num);
}

/**
 * @brief Process Insert operation at different position in LinkedList
 *        as per user Input
 * 
 * @param list 
 */
void Insert(struct LinkedList **list){
    printf("Enter Input: \n");
    printf("R - Insert at Rear\n");
    printf("F - Insert at Front\n");
    printf("M - Insert at Middle\n");

    char c = getch();
    int num;

    printf("Enter number to add");
    scanf("%d",&num);

    switch (c)
    {
    case 'R':
    case 'r':
        InsertRear(list, num);
        break;
    
    case 'F':
    case 'f':
        InsertFront(list, num);
        break;

    case 'M':
    case 'm':
        InsertMid(list, num);
        break;

    default:
        printf("Invalid Input to Insert.\n");
        break;
    }
}

/**
 * @brief Process Delete Operation on LinkedList as per user Input.
 * 
 * @param list 
 */
void Delete(struct LinkedList **list){
    printf("Enter Input: \n");
    printf("R - Delete at Rear\n");
    printf("F - Delete at Front\n");
    printf("M - Delete at Middle\n");

    char c = getch();

    switch (c)
    {
    case 'R':
    case 'r':
        deleteRear(list);
        break;
    
    case 'F':
    case 'f':
        deleteFront(list);
        break;

    case 'M':
    case 'm':
        deleteMid(list);
        break;

    default:
        printf("Invalid Input to Delete.\n");
        break;
    }
}

/**
 * @brief Main Function
 * 
 * @return int 
 */

int main(){
    struct LinkedList *head = NULL;
    
    while(1){
        printf("Enter Input : \n");
        printf("I - Insert LinkedList\n");
        printf("D - Delete LinkedList\n");
        printf("S - Sort LinkedList\n");
        printf("F - Find in LinkedList\n");
        printf("P - Print LinkedList\n");

        char c = getch();
        switch (c)
        {
        case 'I':
        case 'i':
            Insert(&head);
            break;
        
        case 'D':
        case 'd':
            Delete(&head);
            break;

        case 'S':
        case 's':
            sort_ll(&head);
            break;

        case 'F':
        case 'f':
            find(&head);
            break;

        case 'P':
        case 'p':
            Print_ll(&head);
            break;

        default:
            printf("Invalid Input.\n");
            break;
        }
    }

    return 0;
}