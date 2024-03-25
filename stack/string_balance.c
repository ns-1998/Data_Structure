/**
 * @file string_balance.c
 * @author Niraj Soni
 * @brief Bases on the number of string print output whether string balanced or not.
 * @version 0.1
 * @date 2024-01-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/************* GLOBAL VARIABLES **************/

#define MAX_LEN 100

/************* LOCAL VARIABLES **************/

static int count;

/************* LOCAL FUNCTIONS **************/

/**
 * @brief check if input string balanced.
 * 
 * @param s 
 * @return int 
 */
static int is_string_balanced(char *s){
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
        {
            ++count;
        }
        else if (s[i] == ')')
        {
            --count;
        }
    }

    return count;
}

/**
 * @brief Get the string object
 * 
 * @return char* 
 */
static char *get_string(){
    char *str = (char *)malloc(MAX_LEN * sizeof(char));

    if (str == NULL)
    {
        printf("string initialization fail.\n");
        assert(0);
    }

    scanf("%s", str);

    if (strlen(str) > MAX_LEN)
    {
        printf("string is too large\n");
        return NULL;
    }

    str = realloc(str, strlen(str));

    return str;
}

int main(){
    char *s = get_string();

    if (s != NULL)
    {
        if (!is_string_balanced(s))
            printf("string is balanced.\n");
        else
            printf("string is not balanced.\n");
    }

    free(s);

    return 0;
}