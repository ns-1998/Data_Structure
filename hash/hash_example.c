#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

struct hash {
    int key;
    int data;
}*arr;

static int getIndex(int k)
{
    return k%MAX;
}

static void printHelp()
{
    printf("Enter Input: \n");
    printf("1 : Add key\n");
    printf("2 : Remove key\n");
    printf("3 : Print keys\n");
}

static bool addKey()
{
    int key, data, index;
    bool ret = true;

    printf("Enter Key:");
    scanf("%d",&key);
    printf("Enter Data:");
    scanf("%d",&data);

    index = getIndex(key);
    if(index > MAX-1)
    {
        printf("Invalid Index.\n");
        ret = false;
        goto result;
    }

    if(arr[index].data == 0)
    {
        arr[index].key = key;
        arr[index].data = data;
    }
    else
    {
        printf("collison occured.\n");
        ret = false;
    }

result:
    return ret;
}

static bool removeKey()
{
    int key, index;
    bool ret = true;

    printf("Enter Key:");
    scanf("%d",&key);

    index = getIndex(key);
    if(index > MAX-1)
    {
        printf("Invalid Index.\n");
        ret = false;
        goto result;
    }

    if(arr[index].data != 0)
    {
        arr[index].key = 0;
        arr[index].data = 0;
    }
    else
    {
        printf("Index is Empty.\n");
        ret = false;
    }

result:
    return ret;
}

static bool printKeys()
{
    bool ret = false;

    for(int i=0; i < MAX; i++)
    {
        if(arr[i].data != 0)
        {
            ret = true;
            printf("printf key %d & data %d\n",arr[i].key, arr[i].data);
        }
    }

    return ret;
}

int main()
{
    bool ret = true;
    int input;

    arr = (struct hash *)malloc(MAX * sizeof(struct hash));

    if(arr == NULL)
    {
        printf("fail to alloc memory.\n");
        ret = false;
        goto done;
    }

    printHelp();

    while(1)
    {
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            ret = addKey();
            if(ret == false)
                printf("Fail to add key.\n");
            break;
        
        case 2:
            ret = removeKey();
            if(ret == false)
                printf("Fail to Remove key.\n");
            break;

        case 3:
            ret = printKeys();
            if(ret == false)
                printf("Nothing to print empty hash.\n");
            break;
        default:
            printf("Invalid Input.\n");
            printHelp();
            break;
        }
    }


done:
    if(ret == false)
        return 1;

    return 0;
}