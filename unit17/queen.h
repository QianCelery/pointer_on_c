/*
 * @Author: Celery
 * @Date: 2021-10-31 10:19:04
 * @LastEditTime: 2021-10-31 16:48:09
 * @LastEditors: Celery
 * @Description: 队列实现头文件
 * @FilePath: \unit17\queen.h
 * 
 */
#ifndef __QUEEN_H__
#define __QUEEN_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define QUEEN_TYPE  int

/**
 * @description: 创建动态数组队列
 * @param {size_t} size 队列中元素个数
 * @return {*}
 */
void creat_queen(size_t size);

/**
 * @description: 销毁队列
 * @param {*}
 * @return {*}
 */
void destroy_queen(void);

/**
 * @description: 为动态数组队列重新分配内存大小
 * @param {size_t} size
 * @return {*}
 */
void resize_queen(size_t size);

/**
 * @description: 在队列尾部插入
 * @param {QUEEN_TYPE} value
 * @return {*}
 */
void queen_insert(QUEEN_TYPE value);

/**
 * @description: 在队列头部删除
 * @param {*}
 * @return {*}
 */
void queen_delete(void);

/**
 * @description: 返回队列头部元素
 * @param {*}
 * @return {*}
 */
QUEEN_TYPE queen_first(void);

/**
 * @description: 判断队列是否为空，因为当队列只有一个元素时，front和rear都指向这个元素
 * @param {*}
 * @return {*}
 */
bool is_queen_empty(void);

/**
 * @description: 判断队列是否已满，因为数组始终有一个元素不使用，+2后等于等于front表示已满
 * @param {*}
 * @return {*}
 */
bool is_queen_full(void);

#endif