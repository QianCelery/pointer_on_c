/*
 * @Author: Celery
 * @Date: 2021-10-31 11:15:27
 * @LastEditTime: 2021-10-31 16:48:46
 * @LastEditors: Celery
 * @Description: 链式队列实现
 * @FilePath: \unit17\l_queen.c
 * 
 */
#include "queen.h"

typedef struct QUEEN_NODE
{
    QUEEN_TYPE value;
    struct QUEEN_NODE *next;
}QueenNode;

QueenNode *queen;

QueenNode *front;
QueenNode *rear;

/**
 * @description: 创建动态数组队列,对于链式结构来说不需要
 * @param {size_t} size 队列中元素个数
 * @return {*}
 */
void creat_queen(size_t size)
{
    
}

/**
 * @description: 销毁队列
 * @param {*}
 * @return {*}
 */
void destroy_queen(void)
{
    while (!is_empty())
    {
        delete();
    }
}

/**
 * @description: 为动态数组队列重新分配内存大小,链式无需此操作
 * @param {size_t} size
 * @return {*}
 */
void resize_queen(size_t size)
{
    
}

/**
 * @description: 在队列尾部插入
 * @param {QUEEN_TYPE} value
 * @return {*}
 */
void queen_insert(QUEEN_TYPE value)
{
    QueenNode *new_node;
    new_node = (QueenNode *)malloc(sizeof(QueenNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next = NULL;
    if(rear == NULL)    //如果添加第一个节点，front也要指向这个节点
    {
        front = new_node;
    }
    else
    {
        rear->next = new_node;
    }
    rear = new_node;
}

/**
 * @description: 在队列头部删除
 * @param {*}
 * @return {*}
 */
void queen_delete(void)
{
    assert(!is_empty());
    QueenNode *next_node;
    next_node = front->next;
    free(front);
    front = next_node;
    if(front == NULL)   //如果删除的是最后一个节点，rear也要设置为NULL
    {
        rear = NULL;
    }
}

/**
 * @description: 返回队列头部元素
 * @param {*}
 * @return {*}
 */
QUEEN_TYPE queen_first(void)
{
    assert(!is_empty());
    return front->value;
    
}

/**
 * @description: 判断队列是否为空
 * @param {*}
 * @return {*}
 */
bool is_queen_empty(void)
{
    return front == NULL;
}

/**
 * @description: 判断队列是否已满
 * @param {*}
 * @return {*}
 */
bool is_queen_full(void)
{
    return false;
}