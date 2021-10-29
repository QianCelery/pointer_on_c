/*
 * @Author: Celery
 * @Date: 2021-10-29 16:22:39
 * @LastEditTime: 2021-10-29 16:43:48
 * @LastEditors: Celery
 * @Description: 实现静态数组堆栈
 * @FilePath: \unit16c:\source\pointers_on_c\unit17\a_stack.c
 * 
 */
#include "stack.h" 

#define STACK_SIZE  100

static STACK_TYPE   stack[STACK_SIZE];
static int          top_elment = -1;     //指向堆栈顶部元素的指针

/**
 * @description: 把一个新值压入到堆栈中
 * @param {STACK_TYPE} value
 * @return {*}
 */
void push(STACK_TYPE value)
{
    assert(!is_full());
    top_elment ++;
    stack[top_elment] = value;
}

/**
 * @description: 从堆栈顶部弹出一个值，
 * @param {*}
 * @return {*}
 */
void pop(void)
{
    assert(!is_empty());
    top_elment--;
}

/**
 * @description: 返回堆栈顶部元素的值，但不对堆栈进行修改
 * @param {*}
 * @return {STACK_TYPE} 
 */
STACK_TYPE top(void)
{
    assert(!is_empty());
    return stack[top_elment];
}

/**
 * @description: 如果堆栈为空返回true，否则返回false
 * @param {*}
 * @return {*}
 */
bool is_empty(void)
{
    return top_elment == -1;
}

/**
 * @description: 如果堆栈已满返回true，否则返回false
 * @param {*}
 * @return {*}
 */
bool is_full(void)
{
    return top_elment == STACK_SIZE - 1;
}