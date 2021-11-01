/*
 * @Author: Celery
 * @Date: 2021-10-31 10:39:56
 * @LastEditTime: 2021-10-31 16:49:17
 * @LastEditors: Celery
 * @Description: 队列功能测试文件
 * @FilePath: \unit17\queen_test.c
 * 
 */
#include "queen.h"

int main(void)
{
    int i = 0;

    //creat_queen(100);
    for(i; i < 100; i++)
    {
        queen_insert(i);
    }
    printf("is_full: %d\n", is_queen_full());
    resize_queen(200);
    printf("is_full: %d\n", is_queen_full());
    for(i = 0; i < 100; i++)
    {
        queen_insert(i);
    }
    printf("is_full: %d\n", is_queen_full());
    for(i = 0; i < 200; i++)
    {
        printf("value: %d\n", queen_first());
        queen_delete();
    }
    printf("is_empty: %d\n", is_queen_empty());
    destroy_queen();
    exit(EXIT_SUCCESS);
}