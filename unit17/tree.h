/*
 * @Author: Celery
 * @Date: 2021-10-30 15:59:38
 * @LastEditTime: 2021-11-01 09:21:29
 * @LastEditors: Celery
 * @Description: 二叉树实现头文件
 * @FilePath: \unit17\tree.h
 * 
 */
#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#define TREE_TYPE int

/**
 * @description: 销毁树，并释放内存,使用后序遍历
 * @param {*}
 * @return {*}
 */
void destroy_tree(void);

/**
 * @description: 在二叉树中插入新值，使用迭代，不使用递归
 * @param {TREE_TYPE} value
 * @return {*}
 */
void insert(TREE_TYPE value);

/**
 * @description: 在二叉树中删除一个值
 * @param {TREE_TYPE} value
 * @return {*}
 */
bool delete(TREE_TYPE value);

/**
 * @description: 在二叉树搜索树中查找值
 * @param {TREE_TYPE} value
 * @return {TREE_TYPE *}成功查找返回该值在数组中地址，未查找到返回NULL
 */
TREE_TYPE *find(TREE_TYPE value);

/**
 * @description: 遍历树
 * @param {TREE_TYPE} value
 * @return {*}
 */
void pre_order_traverse(void (*callback)(TREE_TYPE value));

/**
 * @description: 计算二叉树节点个数
 * @param {*}
 * @return {*}
 */
int get_node_count(void);

/**
 * @description: 按层次遍历树
 * @param {TREE_TYPE} value
 * @return {*}
 */
void breadth_first_traverse(void (*callback)(TREE_TYPE value));

/**
 * @description: 判断是否为二叉树
 * @param {*}
 * @return {*}
 */
bool is_bst(void);

#endif