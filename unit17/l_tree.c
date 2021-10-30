/*
 * @Author: Celery
 * @Date: 2021-10-30 19:24:17
 * @LastEditTime: 2021-10-30 20:00:47
 * @LastEditors: Celery
 * @Description: 链式二叉树功能实现
 * @FilePath: \unit17\l_tree.c
 * 
 */
#include "tree.h"

typedef struct TREE_NODE
{
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
}TreeNode;

static TreeNode *tree;

/**
 * @description: 在二叉树中插入新值，使用迭代，不使用递归
 * @param {TREE_TYPE} value
 * @return {*}
 */
void insert(TREE_TYPE value)
{
    TreeNode *current;
    TreeNode **link;

    link = &tree;

    while((current = *link) != NULL)
    {
        if(value < current->value)
        {
            link = &current->left;
        }
        else
        {
            assert(value != current->value);
            link = &current->right;
        }
    }
    current = malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}

/**
 * @description: 在二叉树搜索树中查找值
 * @param {TREE_TYPE} value
 * @return {TREE_TYPE *}成功查找返回该值在数组中地址，未查找到返回NULL
 */
TREE_TYPE *find(TREE_TYPE value)
{
    TreeNode *current;

    current = tree;

    while(current != NULL && current->value != value)
    {
        if(value < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if(current != NULL)
    {
        return &current->value; //其实没有实际意义0.0
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
static void do_pre_order_traverse(TreeNode *current, void (*callback)(TREE_TYPE value))
{
    if(current != NULL)
    {
        callback(current->value);
        do_pre_order_traverse(current->left, callback);
        do_pre_order_traverse(current->right, callback);
    }
}

/**
 * @description: 遍历树
 * @param {TREE_TYPE} value
 * @return {*}
 */
void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
    do_pre_order_traverse(tree, callback);
}