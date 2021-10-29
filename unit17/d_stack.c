/*
 * @Author: Celery
 * @Date: 2021-10-29 16:57:54
 * @LastEditTime: 2021-10-29 17:27:29
 * @LastEditors: Celery
 * @Description: 实现动态数组堆栈
 * @FilePath: \unit16c:\source\pointers_on_c\unit17\d_stack.c
 * 
 */
#include "stack.h"

static STACK_TYPE   *stack;
static size_t       STACK_SIZE;           
static int          top_elment = -1;     //指向堆栈顶部元素的指针

/**
 * @description: 创建堆栈
 * @param {size_t} size 堆栈可以保存的元素个数
 * @return {*}
 */
void create_stack(size_t size)
{
    assert(STACK_SIZE == 0);    //创建时保证堆栈不存在
    stack = malloc(size * sizeof(STACK_TYPE));
    STACK_SIZE = size;
    assert(stack != NULL);
}

/**
 * @description: 销毁堆栈，释放堆栈所使用的内存
 * @param {*}
 * @return {*}
 */
void destroy_stack(void)
{
    assert(STACK_SIZE > 0);
    STACK_SIZE = 0;
    free(stack);
    stack = NULL;
}

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
    assert(STACK_SIZE > 0);
    return top_elment == -1;
}

/**
 * @description: 如果堆栈已满返回true，否则返回false
 * @param {*}
 * @return {*}
 */
bool is_full(void)
{
    assert(STACK_SIZE > 0);
    return top_elment == STACK_SIZE - 1;
}