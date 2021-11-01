/*
 * @Author: Celery
 * @Date: 2021-10-31 16:58:51
 * @LastEditTime: 2021-10-31 21:17:19
 * @LastEditors: Celery
 * @Description: 
 * @FilePath: \unit17\a_tree.c
 * 
 */
/*
 * @Author: Celery
 * @Date: 2021-10-30 17:03:22
 * @LastEditTime: 2021-10-31 16:54:58
 * @LastEditors: Celery
 * @Description: 数组形式二叉树实现
 * @FilePath: \unit17\a_tree.c
 * 
 */
#include "tree.h"
#include "queen.h"

#define TREE_SIZE 1000
#define ARRAY_SIZE (TREE_SIZE + 1)  //因为数组第一个元素下标为0，使用下标查找节点时不能使用

static TREE_TYPE tree[ARRAY_SIZE];

static void do_pre_order_traverse(int current, void (*callback)(TREE_TYPE value));

/**
 * @description: 计算左孩子下标
 * @param {int} current
 * @return {*}
 */
static int left_child(int current)
{
    return current * 2;
}

/**
 * @description: 计算右孩子下标
 * @param {int} current
 * @return {*}
 */
static int right_child(int current)
{
    return current * 2 + 1;
}

/**
 * @description: 在二叉树中插入新值，使用迭代，不使用递归
 * @param {TREE_TYPE} value
 * @return {*}
 */
void insert(TREE_TYPE value)
{
    int current = 1;    //从根节点开始

    assert(value != 0);

    while (tree[current] != 0)
    {
        if(value < tree[current])
        {
            current = left_child(current);
        }
        else
        {
            assert(value != tree[current]);
            current = right_child(current);
        }
        assert(current < ARRAY_SIZE);
    }
    
    tree[current] = value;
}

/**
 * @description: 删除只含有一个孩子节点的遍历操作
 * @param {int} current
 * @param {int} next
 * @return {*}
 */
void delete_traverse(int current, int next)
{
    if(tree[next] == 0)
    {
        tree[current] = 0;
        return;
    }
    tree[current] = tree[next];
    delete_traverse(left_child(current), left_child(next));
    delete_traverse(right_child(current), right_child(next));
}

/**
 * @description: 在二叉树中删除一个值
 * @param {TREE_TYPE} value
 * @return {*}
 */
bool delete(TREE_TYPE value)
{
    int current;
    int *node = find(value);
    if(node == NULL)
    {
        return false;
    }
    current = node - tree;
    if(tree[left_child(current)] == 0 && tree[right_child(current)] == 0)       //该节点没有孩子
    {
        tree[current] = 0;
    }
    else if(tree[left_child(current)] == 0 || tree[right_child(current)] == 0)  //该节点只有一个孩子
    {
        tree[current] = 0;
        delete_traverse(current, left_child(current)); //因为是数组形式，所以所有子树都需要修改
        delete_traverse(current, right_child(current));
    }
    else    //该节点有两个孩子
    {
        int next = right_child(current);
        while(tree[left_child(next)] != 0) //查找右子树中值最小的节点
        {
            next = left_child(next);
        }
        tree[current] = tree[next];
        tree[next] = 0;
    }

}

/**
 * @description: 在二叉树搜索树中查找值
 * @param {TREE_TYPE} value
 * @return {TREE_TYPE *}成功查找返回该值在数组中地址，未查找到返回NULL
 */
TREE_TYPE *find(TREE_TYPE value)
{
    int current = 1;    //从跟节点开始

    assert(value != 0);

    while(tree[current] != value && current < ARRAY_SIZE)
    {
        if(value < tree[current])
        {
            current = left_child(current);
        }
        else
        {
            current = right_child(current);
        }
    }

    if(current < ARRAY_SIZE)
    {
        return tree + current;
    }
    else
    {
        return NULL;
    }
}

/**
 * @description: 执行1层前序遍历
 * @param {int} current
 * @param {TREE_TYPE} value
 * @return {*}
 */
static void do_pre_order_traverse(int current, void (*callback)(TREE_TYPE value))
{
    if(current < ARRAY_SIZE && tree[current] != 0)
    {
        callback(tree[current]);
        do_pre_order_traverse(left_child(current), callback);
        do_pre_order_traverse(right_child(current), callback);
    }
}

/**
 * @description: 前序遍历遍历树
 * @param {TREE_TYPE} value
 * @return {*}
 */
void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
    do_pre_order_traverse(1, callback);
}

/**
 * @description: 计算二叉树节点个数
 * @param {*}
 * @return {*}
 */
int get_node_count(void)
{
    
}

/**
 * @description: 层次遍历树
 * @param {TREE_TYPE} value
 * @return {*}
 */
void breadth_first_traverse(void (*callback)(TREE_TYPE value))
{
    int current;
    int child;
    
    //把根节点插入到队列中
    queen_insert(1);

    while(!is_queen_empty())
    {
        current = queen_first();
        queen_delete();
        callback(tree[current]);

        child = left_child(current);
        if((child < ARRAY_SIZE) && (tree[child] != 0))
        {
            queen_insert(child);
        }
        child = right_child(current);
        if((child < ARRAY_SIZE) && (tree[child] != 0))
        {
            queen_insert(child);
        }
    }
}

/**
 * @description: 采用递归判断是否为二叉树
 * @param {int} current
 * @param {int} min
 * @param {int} max
 * @return {*}
 */
static bool check_is_bst(int current, int min, int max)
{
    if(tree[current] == 0)
    {
        return true;
    }
    if(tree[current] < min || tree[current] > max)
    {
        return false;
    }
    return check_is_bst(left_child(current), min, tree[current] - 1) && check_is_bst(right_child(current), tree[current] + 1, max);
}

/**
 * @description: 采用中序遍历判断是否为二叉树
 * @param {*}
 * @return {*}
 */
static bool check_is_bst_bft(int current)
{
    static int prev_node = 0;
    if(current == 1)
    {
        prev_node = 0;
    }
    if(tree[current] != 0)
    {
        if(!check_is_bst_bft(left_child(current)))
        {
            return false;
        }
        if(prev_node != 0 && tree[prev_node] >= tree[current])
        {
            return false;
        }
        prev_node = current;
        if(!check_is_bst_bft(right_child(current)))
        {
            return false;
        }
    }
    return true;
}

/**
 * @description: 判断是否为二叉树
 * @param {*}
 * @return {*}
 */
bool is_bst(void)
{
    //测试，暂停最大值为1000
    //check_is_bst(1, 1, 1000);
    check_is_bst_bft(1);
    //tree[3] = 1;
}