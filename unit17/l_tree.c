/*
 * @Author: Celery
 * @Date: 2021-10-30 19:24:17
 * @LastEditTime: 2021-11-01 10:36:16
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

static void free_post_order_traverse(TreeNode *current, void (*callback)(void *node));

/**
 * @description: 销毁树，并释放内存,使用后序遍历
 * @param {*}
 * @return {*}
 */
void destroy_tree(void)
{
    free_post_order_traverse(tree, free);
    tree = NULL;
}

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
 * @description: 在二叉树中删除一个值
 * @param {TREE_TYPE} value
 * @return {*}
 */
bool delete(TREE_TYPE value)
{
    TreeNode *current;
    TreeNode *parent;
    current = tree;
    //查找节点
    while(current != NULL && current->value != value)
    {
        if(value < current->value)
        {
            parent = current;
            current = current->left;
        }
        else
        {
            parent = current;
            current = current->right;
        }
    }

    if(current == NULL)
    {
        return false;
    }
    if(current->left == NULL && current->right == NULL) //该节点没有孩子
    {
        free(current);
        if(current == parent->left)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }

    }
    else if(current->left == NULL)
    {
        if(current == parent->left)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
        free(current);
    }
    else if(current->right == NULL)
    {
        if(current == parent->left)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
        free(current);
    }
    else
    {
        TreeNode *next = current->right;    //查找右子树中值最小的节点
        while(next->left != NULL)   
        {
            parent = next;
            next = next->left;
        }
        current->value = next->value;
        free(next);
        if(next == parent->left)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
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
 * @description: 使用后序遍历删除所有节点
 * @param {TreeNode} *current
 * @param {TreeNode} *node
 * @return {*}
 */
static void free_post_order_traverse(TreeNode *current, void (*callback)(void *node))
{
    if(current != NULL)
    {
        free_post_order_traverse(current->left, callback);
        free_post_order_traverse(current->right, callback);
        callback(current);
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

/**
 * @description: 遍历二叉树，对每个节点进行计数
 * @param {int} *count
 * @return {*}
 */
static void count_pre_order_traverse(TreeNode *current, int *count)
{
    if(current != NULL)
    {
        (*count)++;
        count_pre_order_traverse(current->left, count);
        count_pre_order_traverse(current->right, count);
    }
}

/**
 * @description: 计算二叉树节点个数
 * @param {*}
 * @return {*}
 */
int get_node_count(void)
{
    int count = 0;

    count_pre_order_traverse(tree, &count);
    
    return count;
}