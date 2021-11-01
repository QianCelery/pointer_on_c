/*
 * @Author: Celery
 * @Date: 2021-10-31 10:24:02
 * @LastEditTime: 2021-10-31 16:59:22
 * @LastEditors: Celery
 * @Description: 静态数组队列实现
 * @FilePath: \unit17\a_queen.c
 * 
 */
#include "queen.h"

#define QUEEN_SIZE  100
#define ARRAY_SIZE  (QUEEN_SIZE + 1)    //为了方便判断队列为空情况，数组中一个元素始终不使用

static QUEEN_TYPE queen[ARRAY_SIZE];
static size_t front = 1;
static size_t rear = 0;

/**
 * @description: 在队列尾部插入
 * @param {QUEEN_TYPE} value
 * @return {*}
 */
void queen_insert(QUEEN_TYPE value)
{
    assert(!is_queen_full());
    rear = (rear + 1) % ARRAY_SIZE;
    queen[rear] = value;
}

/**
 * @description: 在队列头部删除
 * @param {*}
 * @return {*}
 */
void queen_delete(void)
{
    assert(!is_queen_empty());
    front = (front + 1) % ARRAY_SIZE;
}

/**
 * @description: 返回队列头部元素
 * @param {*}
 * @return {*}
 */
QUEEN_TYPE queen_first(void)
{
    assert(!is_queen_empty());
    return queen[front];
}

/**
 * @description: 判断队列是否为空，因为当队列只有一个元素时，front和rear都指向这个元素
 * @param {*}
 * @return {*}
 */
bool is_queen_empty(void)
{
    return (rear + 1) % ARRAY_SIZE == front;
}

/**
 * @description: 判断队列是否已满，因为数组始终有一个元素不使用，+2后等于等于front表示已满
 * @param {*}
 * @return {*}
 */
bool is_queen_full(void)
{
    return (rear + 2) % ARRAY_SIZE == front;
}