/*
 * @Author: Celery
 * @Date: 2021-10-31 10:46:58
 * @LastEditTime: 2021-10-31 16:48:30
 * @LastEditors: Celery
 * @Description: 动态数组队列实现
 * @FilePath: \unit17\d_queen.c
 * 
 */
#include "queen.h"

static QUEEN_TYPE *queen;
static size_t queen_size;
static size_t array_size;

static size_t front = 1;
static size_t rear = 0;

/**
 * @description: 创建动态数组队列
 * @param {size_t} size 队列中元素个数
 * @return {*}
 */
void creat_queen(size_t size)
{
    assert(queen_size == 0);    //确保创建时队列还不存在
    queen = (QUEEN_TYPE *)malloc((size + 1) * sizeof(QUEEN_TYPE));    //为了方便判断队列为空，数组中一个元素时钟不使用
    assert(queen != NULL);
    queen_size = size;
    array_size = queen_size + 1;
}

/**
 * @description: 销毁队列
 * @param {*}
 * @return {*}
 */
void destroy_queen(void)
{
    assert(queen_size > 0);
    queen_size = 0;
    free(queen);
    queen = NULL;
}

/**
 * @description: 为动态数组队列重新分配内存大小
 * @param {size_t} size
 * @return {*}
 */
void resize_queen(size_t size)
{
    assert(queen_size != 0);
    queen = (QUEEN_TYPE *)realloc(queen, (size + 1) * sizeof(QUEEN_TYPE));  //为了方便判断队列为空，数组中一个元素时钟不使用
    assert(queen != NULL);
    queen_size = size;
    array_size = queen_size + 1;
}

/**
 * @description: 在队列尾部插入
 * @param {QUEEN_TYPE} value
 * @return {*}
 */
void queen_insert(QUEEN_TYPE value)
{
    assert(!is_full());
    rear = (rear + 1) % array_size;
    queen[rear] = value;
}

/**
 * @description: 在队列头部删除
 * @param {*}
 * @return {*}
 */
void queen_delete(void)
{
    assert(!is_empty());
    front = (front + 1) % array_size;
}

/**
 * @description: 返回队列头部元素
 * @param {*}
 * @return {*}
 */
QUEEN_TYPE queen_first(void)
{
    assert(!is_empty());
    return queen[front];
}

/**
 * @description: 判断队列是否为空，因为当队列只有一个元素时，front和rear都指向这个元素
 * @param {*}
 * @return {*}
 */
bool is_queen_empty(void)
{
    assert(queen_size > 0);
    return (rear + 1) % array_size == front;
}

/**
 * @description: 判断队列是否已满，因为数组始终有一个元素不使用，+2后等于等于front表示已满
 * @param {*}
 * @return {*}
 */
bool is_queen_full(void)
{
    assert(queen_size > 0);
    return (rear + 2) % array_size == front;
}