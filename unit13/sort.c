/*
 * @Author: Celery
 * @Date: 2021-10-25 19:42:21
 * @LastEditTime: 2021-10-25 20:35:29
 * @LastEditors: Celery
 * @Description: 对任何类型的数组进行排序
 * @FilePath: \unit12c:\source\pointer_on_c\unit13\sort.c
 * 
 */
#include "string.h"
#include "stdio.h"

int compare_char(void const *a, void const *b);
void sort(void *arrary, int num, int length, int (*compare)(void const *, void const *));

char array[10] = {1, 11, 2, 5, 1, 20, 50, 8, 9, 6};
int main(void)
{
    
    sort(array, 10, 1, compare_char);
    
    return 0;
}

/**
 * @description: 
 * @param {void} *arrary 指向需要排序的数组
 * @param {int} num 数组中值得个数
 * @param {int} length  数组元素的长度
 * @return {*}  none
 */
void sort(void *arrary, int num, int length, int (*compare)(void const *, void const *))
{
    int i, j, k;
    char tmp;

    for(i = 0; i < num; i += length)
    {
        for(j = length + i; j < num; j += length)
        {
            if(compare(arrary + i, arrary + j) > 0)
            {
                for(k = 0; k < length; k++)
                {
                    tmp = *(char *)(arrary + i + k);
                    *(char *)(arrary + i + k) = *(char *)(arrary + j + k);
                    *(char *)(arrary + j + k) = tmp;
                }
            }
        }
    }
}

int compare_char(void const *a, void const *b)
{
    if(*(char *)a > *(char *)b)
    {
        return 1;
    }
    else if (*(char *)a == *(char *)b)
    {
        return 0;
    }
    else 
    {
        return -1;
    }
}
