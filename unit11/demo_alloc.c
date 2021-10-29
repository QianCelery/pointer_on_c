/*
 * @Author: Celery
 * @Date: 2021-10-21 15:17:33
 * @LastEditTime: 2021-10-21 19:41:49
 * @LastEditors: Celery
 * @Description: unit11
 * @FilePath: \unit10c:\source\pointer_on_c\unit11\demo_alloc.c
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define BASE_LENGTH 100

int *dynamic_array(void);
char *dynamic_string(void);

int main(void)
{
    //int *test_array = dynamic_array();
    dynamic_string();
    

    printf("Finish\n");
    return 0;
}

int *dynamic_array(void)
{
    int *array;
    int size;
    int value;
    int count = 0;

    size = BASE_LENGTH;
    array = malloc((size + 1) * sizeof(int));
    if(array == NULL)
    {
        return NULL;
    }

    printf("Enter numbers:\n");
    
    while((scanf("%d", &value)) == 1)
    {
        count++;
        if(count > size)
        {
            size += BASE_LENGTH;
            array = realloc(array, (size + 1) * sizeof(int));
            if(array == NULL)
            {
                return NULL;
            }
        }
        array[count] = value;
    }

    if(count < size)
    {
        array = realloc(array, (count + 1) * sizeof(int));
        if(array == NULL)
        {
            return NULL;
        }
    }
    array[0] = count;
    return array;
}

char *dynamic_string(void)
{
    char *string;
    int size;
    int value;
    int count = 0;

    printf("Enter string\n");

    size = BASE_LENGTH;

    string = malloc((size + 1) * sizeof(char));
    if(string == NULL)
    {
        return NULL;
    }
    
    while(((value = getchar()) != EOF) && (value != '\n'))
    {
        string[count] = value;
        count++;
        if(count > size)
        {
            size += BASE_LENGTH;
            string = realloc(string, (size + 1) * sizeof(char));
            if(string == NULL)
            {
                return NULL;
            }
        }
    }
    if(count < size)
    {
        string = realloc(string, (count + 1) * sizeof(char));
        if(string == NULL)
        {
            return NULL;
        }
    }
    string[count] = '\0';

    return string;
}