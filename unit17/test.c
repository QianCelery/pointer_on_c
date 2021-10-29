/*
 * @Author: Celery
 * @Date: 2021-10-29 16:44:17
 * @LastEditTime: 2021-10-29 17:37:34
 * @LastEditors: Celery
 * @Description: 测试程序
 * @FilePath: \unit16c:\source\pointers_on_c\unit17\test.c
 * 
 */
#include "stack.h"
#include "stdio.h"

int main(void)
{
    create_stack(100);
    printf("is_empty : %d\n", is_empty());

    for(int i = 0; i < 100; i++)
    {
        push(i);
    }
    printf("top_element:%d\n", top());
    printf("is_full:%d\n", is_full());
    for(int i = 0; i < 100; i++)
    {
        pop();
    }
    printf("is_empty : %d\n", is_empty());
    pop();
}