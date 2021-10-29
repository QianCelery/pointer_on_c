/*
 * @Author: Celery
 * @Date: 2021-10-29 17:16:33
 * @LastEditTime: 2021-10-29 17:45:02
 * @LastEditors: Celery
 * @Description: 实现链式堆栈
 * @FilePath: \unit16c:\source\pointers_on_c\unit17\l_stack.c
 * 
 */
#include "stack.h"

typedef struct STACK_NODE
{
    STACK_TYPE value;
    struct STACK_NODE *next;
} StackNode;

StackNode *stack;


/**
 * @description: 创建堆栈,链式堆栈无需此操作
 * @param {size_t} size 堆栈可以保存的元素个数
 * @return {*}
 */
void create_stack(size_t size)
{
    
}

/**
 * @description: 销毁堆栈，释放堆栈所使用的内存
 * @param {*}
 * @return {*}
 */
void destroy_stack(void)
{
    while(!is_empty())
    {
        pop();
    }
}

/**
 * @description: 把一个新值压入到堆栈中
 * @param {STACK_TYPE} value
 * @return {*}
 */
void push(STACK_TYPE value)
{
    StackNode *new_node;
    new_node = malloc(sizeof(StackNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next = stack;
    stack = new_node;

}

/**
 * @description: 从堆栈顶部弹出一个值，
 * @param {*}
 * @return {*}
 */
void pop(void)
{
    assert(!is_empty());
    StackNode *first_node;
    first_node = stack;
    stack = first_node->next;
    free(first_node);
}

/**
 * @description: 返回堆栈顶部元素的值，但不对堆栈进行修改
 * @param {*}
 * @return {STACK_TYPE} 
 */
STACK_TYPE top(void)
{
    assert(!is_empty());
    return stack->value;
}

/**
 * @description: 如果堆栈为空返回true，否则返回false
 * @param {*}
 * @return {*}
 */
bool is_empty(void)
{
    return stack == NULL;
}

/**
 * @description: 如果堆栈已满返回true，否则返回false
 * @param {*}
 * @return {*}
 */
bool is_full(void)
{
    return false;
}