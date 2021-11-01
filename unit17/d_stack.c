/*
 * @Author: Celery
 * @Date: 2021-10-29 16:57:54
 * @LastEditTime: 2021-10-31 15:46:32
 * @LastEditors: Celery
 * @Description: 实现动态数组堆栈
 * @FilePath: \unit17\d_stack.c
 * 
 */
#include "stack.h"

//static STACK_TYPE   *stack;
//static size_t       STACK_SIZE;           
//static int          top_elment = -1;     //指向堆栈顶部元素的指针

typedef struct 
{
    int top_elment;
    size_t stack_size;
    STACK_TYPE *stack_ptr;
}Stack;

/**
 * @description: 创建堆栈
 * @param {size_t} size 堆栈可以保存的元素个数
 * @return {int} 返回int类型的索引，本质上是指针，以此简化提供给应用模块的接口
 */
int create_stack(size_t size)
{
    Stack *stack;
    stack = (Stack *)malloc(sizeof(Stack));
    assert(stack != NULL);
    assert(stack != NULL);
    stack->stack_size = size;
    stack->top_elment = -1;
    stack->stack_ptr = (STACK_TYPE *)malloc(size * sizeof(STACK_TYPE));
    return (int)stack;
}

/**
 * @description: 销毁堆栈，释放堆栈所使用的内存
 * @param {int} stack_index 堆栈内存位置索引
 * @return {*}
 */
void destroy_stack(int stack_index)
{
    Stack *stack = (Stack *)stack_index;
    assert(stack->stack_size > 0);
    free(stack->stack_ptr);
    stack->top_elment = -1;
    stack->stack_size = 0;
    free(stack);
    stack = NULL;
}

/**
 * @description: 为堆栈重新分配内存大小
 * @param {int} stack_index 堆栈内存位置索引
 * @param {size_t} size
 * @return {*}
 */
void resize_stack(int stack_index, size_t size)
{
    Stack *stack = (Stack *)stack_index;
    assert(stack->stack_size != 0);
    stack->stack_ptr = (STACK_TYPE *)realloc(stack->stack_ptr, size * sizeof(STACK_TYPE));
    assert(stack != NULL);
    stack->stack_size = size;
    
}

/**
 * @description: 把一个新值压入到堆栈中
 * @param {int} stack_index 堆栈内存位置索引
 * @param {STACK_TYPE} value
 * @return {*}
 */
void push(int stack_index, STACK_TYPE value)
{
    assert(!is_full(stack_index));
    Stack *stack = (Stack *)stack_index;
    stack->top_elment++;
    stack->stack_ptr[stack->top_elment] = value;
}

/**
 * @description: 从堆栈顶部弹出一个值，
 * @param {int} stack_index 堆栈内存位置索引
 * @return {*}
 */
void pop(int stack_index)
{
    assert(!is_empty(stack_index));
    Stack *stack = (Stack *)stack_index;
    stack->top_elment--;
}

/**
 * @description: 返回堆栈顶部元素的值，但不对堆栈进行修改
 * @param {int} stack_index 堆栈内存位置索引
 * @return {STACK_TYPE} 
 */
STACK_TYPE top(int stack_index)
{
    assert(!is_empty(stack_index));
    Stack *stack = (Stack *)stack_index;
    return stack->stack_ptr[stack->top_elment];
}

/**
 * @description: 如果堆栈为空返回true，否则返回false
 * @param {int} stack_index 堆栈内存位置索引
 * @return {*}
 */
bool is_empty(int stack_index)
{
    Stack *stack = (Stack *)stack_index;
    assert(stack->stack_size > 0);
    return stack->top_elment == -1;
}

/**
 * @description: 如果堆栈已满返回true，否则返回false
 * @param {int} stack_index 堆栈内存位置索引
 * @return {*}
 */
bool is_full(int stack_index)
{
    Stack *stack = (Stack *)stack_index;
    assert(stack->stack_size > 0);
    return stack->top_elment == stack->stack_size - 1;
}