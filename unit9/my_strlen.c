/*
 * @Author: Celery
 * @Date: 2021-10-19 20:36:14
 * @LastEditTime: 2021-10-19 20:45:51
 * @LastEditors: Celery
 * @Description: 自定义strlen,消除字符串不移'\0'结尾的异常
 * @FilePath: \unit9\my_strlen.c
 * 
 */
#include "stdio.h"
#include "stddef.h"
#include "string.h"

size_t my_strlen(char *string, int size);

int main(void)
{
    char string[5] = "abcde";

    printf("result: %d\n", (int)my_strlen(string, 5));
    printf("result: %d\n", (int)strlen(string));
    return 0;
}

size_t my_strlen(char *string, int size)
{
    register size_t length;
    
    for(length = 0; length < size; length++)
    {
        if((*(string++)) == '\0')
            break;
    }

    return length;
}