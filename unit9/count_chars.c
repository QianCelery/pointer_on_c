/*
 * @Author: Celery
 * @Date: 2021-10-19 21:06:37
 * @LastEditTime: 2021-10-19 21:20:23
 * @LastEditors: Celery
 * @Description: 统计传入参数中字符在字符串中出现的数量
 * @FilePath: \unit9\count_chars.c
 * 
 */
#include "stdio.h"

int count_chars(char const *string, char const *chars);

int main(void)
{
    char string[] = "abcdefghijkl";
    char chars[] = "a323asdf";

    printf("count:%d\n", count_chars(string, chars));
    return 0;
}

int count_chars(char const *string, char const *chars)
{
    char const *p = string;
    int count = 0;

    while((*chars) != '\0')
    {
        while((*p) != '\0')
        {
            if(*chars == *p)
            {
                count++;
                break;
            }
            p++;
        }
        chars++;
        p = string;
    }
    return count;
}