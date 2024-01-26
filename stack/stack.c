/**
 * @file stack.c
 * @author Niraj Soni
 * @brief Basic Stack example code to understand working, in which will do different operations like
 *        Push, Pop, print stack, peek.
 * @version 0.1
 * @date 2024-01-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/************* GLOBAL VARIABLES **************/

#define MAX 10

typedef struct
{
    /* data */
    int arr[MAX];
    int pos;
}stack;

/************* LOCAL VARIABLES **************/

static stack *s;


/************* LOCAL FUNCTIONS **************/

/**
 * @brief function initialzes the stack.
 * 
 */
static void initialize_stack(){
    s = (stack *)malloc(sizeof(stack));

    if(s == NULL){
        printf("stack initalization failed.\n");
        assert(0);
    }

    s->pos = -1;
    printf("stack initialization successful.\n");
}

/**
 * @brief check if stack empty or not.
 * 
 * @return int 
 */
static int is_empty(){
    if(s->pos == -1)
        return 1;
    else
        return 0;
}

/**
 * @brief check if stack is full or not.
 * 
 * @return int 
 */
static int is_full(){
    if(s->pos == MAX-1)
        return 1;
    else
        return 0;
}

/**
 * @brief function uninitialzes the stack.
 * 
 */
static void uninitialize_stack(){
    if(s != NULL){
        free(s);
        printf("stack uninitalization success.\n");
    }
    else
        printf("unable to uninitalizate stack.\n");
}

/**
 * @brief function push the number into stack
 * 
 * @param n 
 */
static void push(int n){
    if(is_full()){
        printf("stack is full, unable to push more elements.\n");
        return;
    }
    ++s->pos;
    s->arr[s->pos] = n;
    printf("push: %d\n",s->arr[s->pos]);
}

/**
 * @brief function pop the number from stack.
 * 
 */
static void pop(){
    if(is_empty()){
        printf("stack is empty, unable to pop more elements.\n");
        return;
    }
    printf("pop : %d\n",s->arr[s->pos]);
    --s->pos;
}

/**
 * @brief print the top element of stack without removing it.
 * 
 */
static void peek(){
    printf("current peek element is %d\n",s->arr[s->pos]);
}

/**
 * @brief function prints the stack.
 * 
 */
static void print_stack(){
    if(is_empty()){
        printf("stack is empty, nothing to print.\n");
        return;
    }

    printf("stack : ");
    for(int i=0; i <= s->pos; i++){
        printf("%d",s->arr[i]);
        if(i == (s->pos))
            printf("\n");
        else
            printf(" ");
    }
}


/**
 * @brief makes the stack empty.
 * 
 */
static void empty_stack(){
        s->pos = -1;
}

int main(){

    int push_count=0, pop_count=0, num=0;

    initialize_stack();

    printf("Enter number of Element to push :");
    scanf("%d",&push_count);

    printf("Enter Numbers to push :");
    for(int i=0; i < push_count; i++)
    {
        scanf("%d",&num);
        push(num);
    }

    print_stack();

    printf("Enter number of Element to pop :");
    scanf("%d",&pop_count);
    for(int i=0; i < pop_count; i++)
    {
        if(is_empty()){
            break;
        }
        pop();
    }

    print_stack();
    empty_stack();
    uninitialize_stack();

    return 0;
}
