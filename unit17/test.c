/*
 * @Author: Celery
 * @Date: 2021-10-29 16:44:17
 * @LastEditTime: 2021-10-31 15:52:06
 * @LastEditors: Celery
 * @Description: 测试程序
 * @FilePath: \unit17\test.c
 * 
 */
#include "stack.h"
#include "stdio.h"

int main(void)
{
    int stack1 = create_stack(100);
    int stack2 = create_stack(100);
    printf("is_empty : %d\n", is_empty(stack1));

    for(int i = 0; i < 100; i++)
    {
        push(stack1, i);
    }
    printf("is_full:%d\n", is_full(stack1));
    resize_stack(stack1, 200);
    printf("is_full:%d\n", is_full(stack1));
    for(int i = 100; i < 200; i++)
    {
        push(stack1, i);
    }

    printf("top_element:%d\n", top(stack1));
    printf("is_full:%d\n", is_full(stack1));
    for(int i = 0; i < 200; i++)
    {
        pop(stack1);
    }
    printf("is_empty : %d\n", is_empty(stack1));
    //pop(stack1);
    printf("is_empty : %d\n", is_empty(stack2));
    //pop(stack2);
    return 1;
}