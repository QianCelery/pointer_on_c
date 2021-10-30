/*
 * @Author: Celery
 * @Date: 2021-10-30 18:50:31
 * @LastEditTime: 2021-10-30 19:58:58
 * @LastEditors: Celery
 * @Description: 二叉树测试文件
 * @FilePath: \unit17\tree_test.c
 * 
 */
#include "tree.h"

void test_put_value(int value)
{
    printf("value:%d\n", value);
}


int main(void)
{
    int i = 0;

    for(i = 1; i < 100; i++)
    {
        insert(i);
    }
    pre_order_traverse(test_put_value);

}

