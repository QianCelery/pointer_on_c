/*
 * @Author: Celery
 * @Date: 2021-10-30 17:03:22
 * @LastEditTime: 2021-10-30 18:52:34
 * @LastEditors: Celery
 * @Description: 数组形式二叉树实现
 * @FilePath: \unit17\a_tree.c
 * 
 */
#include "tree.h"

#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE + 1)  //因为数组第一个元素下标为0，使用下标查找节点时不能使用

static TREE_TYPE tree[ARRAY_SIZE];

/**
 * @description: 计算左孩子下标
 * @param {int} current
 * @return {*}
 */
static int left_child(int current)
{
    return current * 2;
}

/**
 * @description: 计算右孩子下标
 * @param {int} current
 * @return {*}
 */
static int right_child(int current)
{
    return current * 2 + 1;
}

/**
 * @description: 在二叉树中插入新值，使用迭代，不使用递归
 * @param {TREE_TYPE} value
 * @return {*}
 */
void insert(TREE_TYPE value)
{
    int current = 1;    //从根节点开始

    assert(value != 0);

    while (tree[current] != 0)
    {
        if(value < tree[current])
        {
            current = left_child(current);
        }
        else
        {
            assert(value != tree[current]);
            current = right_child(current);
        }
        assert(current < ARRAY_SIZE);
    }
    
    tree[current] = value;
}

/**
 * @description: 在二叉树搜索树中查找值
 * @param {TREE_TYPE} value
 * @return {TREE_TYPE *}成功查找返回该值在数组中地址，未查找到返回NULL
 */
TREE_TYPE *find(TREE_TYPE value)
{
    int current = 1;    //从跟节点开始

    assert(value != 0);

    while(tree[current] != value && current < ARRAY_SIZE)
    {
        if(value < tree[current])
        {
            current = left_child(current);
        }
        else
        {
            current = right_child(current);
        }
    }

    if(current < ARRAY_SIZE)
    {
        return tree + current;
    }
    else
    {
        return NULL;
    }
}

/**
 * @description: 执行1层前序遍历
 * @param {int} current
 * @param {TREE_TYPE} value
 * @return {*}
 */
static void do_pre_order_traverse(int current, void (*callback)(TREE_TYPE value))
{
    if(current < ARRAY_SIZE && tree[current] != 0)
    {
        callback(tree[current]);
        do_pre_order_traverse(left_child(current), callback);
        do_pre_order_traverse(right_child(current), callback);
    }
}

/**
 * @description: 遍历树
 * @param {TREE_TYPE} value
 * @return {*}
 */
void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
    do_pre_order_traverse(1, callback);
}