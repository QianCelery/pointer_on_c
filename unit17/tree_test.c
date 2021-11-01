/*
 * @Author: Celery
 * @Date: 2021-10-30 18:50:31
 * @LastEditTime: 2021-11-01 10:37:01
 * @LastEditors: Celery
 * @Description: 二叉树测试文件
 * @FilePath: \unit17\tree_test.c
 * 
 */
#include "tree.h"
#include "queen.h"

void test_put_value(int value)
{
    printf("value:%d\n", value);
}

int main(void)
{
    int i = 0;

    // for(i = 1; i < 10; i++)
    // {
    //     insert(i);
    // }
    insert(20);
    insert(12);
    insert(28);
    insert(10);
    insert(17);
    //insert(25);
    insert(30);
    insert(8);
    insert(11);
    insert(16);
    insert(19);
    //insert(21);
    //insert(24);
    insert(29);
    insert(31);
    pre_order_traverse(test_put_value);
    printf("number of node:%d\n", get_node_count());
    //breadth_first_traverse(test_put_value);
    //printf("is_bst: %d\n", is_bst());
    delete(28);
    printf("number of node:%d\n", get_node_count());
    //breadth_first_traverse(test_put_value);
    //destroy_tree();
    pre_order_traverse(test_put_value);
    printf("number of node:%d\n", get_node_count());

}

