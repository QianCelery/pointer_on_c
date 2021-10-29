/*
 * @Author: Celery
 * @Date: 2021-10-19 21:23:18
 * @LastEditTime: 2021-10-19 21:37:42
 * @LastEditors: Celery
 * @Description: 验证字符串是否为回文
 * @FilePath: \unit9\palindrome.c
 * 
 */
#include "stdio.h"
#include "string.h"
#include "ctype.h"

int palindrome(char *string);

int main(void)
{
    char string[] = "abc123e13a";

    printf("result: %d\n", palindrome(string));
    return 0;
}

int palindrome(char *string)
{
    char *p_start = string;
    char *p_end = string + strlen(string);

    while(p_end > p_start)
    {
        while(!isalpha(*p_start))
            p_start++;
        while(!isalpha(*p_end))
            p_end--;
        if(tolower(*p_start) != tolower(*p_end))
        {
            return 0;
        }
        p_start++;
         p_end--;
    }

    return 1;
}