/*
 * @Author: Celery
 * @Date: 2021-10-18 21:22:27
 * @LastEditTime: 2021-10-19 20:23:53
 * @LastEditors: Celery
 * @Description: 
 * @FilePath: \unit9\presentage_of_ch.c
 * 
 */

#include "stdio.h"
#include "string.h"
#include "ctype.h"

float presentage_of_ch(char *string);

int main(void)
{
    char string[] = "safsaf134.,,.  \255 --=asdf[];'./.\255";

    printf("result: %f", presentage_of_ch(string));
    return 1;
}

float presentage_of_ch(char *string)
{
    int count = 0;
    int len = strlen(string);
    for(; (*string) != '\0'; string++)
    {
        if((iscntrl(*string)) || (isspace(*string)) || (isalnum(*string)) || (ispunct(*string)) || (!isprint(*string)))
        {
            count++;
        }
    }

    return (float)(len / count);
}

