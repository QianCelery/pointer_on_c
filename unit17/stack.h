/*
 * @Author: Celery
 * @Date: 2021-10-29 16:28:17
 * @LastEditTime: 2021-10-29 17:13:13
 * @LastEditors: Celery
 * @Description: 堆栈实现头文件
 * @FilePath: \unit16c:\source\pointers_on_c\unit17\stack.h
 * 
 */

#ifndef __STACK_H__
#define __STACK_H__

#include "assert.h"
#include "stdlib.h"
#include "stdbool.h"

#define STACK_TYPE  int

/**
 * @description: 创建堆栈
 * @param {size_t} size 堆栈可以保存的元素个数
 * @return {*}
 */
void create_stack(size_t size);

/**
 * @description: 销毁堆栈，释放堆栈所使用的内存
 * @param {*}
 * @return {*}
 */
void destroy_stack(void);

/**
 * @description: 把一个新值压入到堆栈中
 * @param {STACK_TYPE} value
 * @return {*}
 */
void push(STACK_TYPE value);

/**
 * @description: 从堆栈顶部弹出一个值，
 * @param {*}
 * @return {*}
 */
void pop(void);

/**
 * @description: 返回堆栈顶部元素的值，但不对堆栈进行修改
 * @param {*}
 * @return {STACK_TYPE} 
 */
STACK_TYPE top(void);

/**
 * @description: 如果堆栈为空返回true，否则返回false
 * @param {*}
 * @return {*}
 */
bool is_empty(void);

/**
 * @description: 如果堆栈已满返回true，否则返回false
 * @param {*}
 * @return {*}
 */
bool is_full(void);
#endif