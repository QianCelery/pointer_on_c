/*
 * @Author: Celery
 * @Date: 2021-10-22 16:34:19
 * @LastEditTime: 2021-10-23 15:28:06
 * @LastEditors: Celery
 * @Description: 单链表操作
 * @FilePath: \unit10c:\source\pointer_on_c\unit12\sll_node.c
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

#define FALSE	0
#define TRUE	1

typedef struct NODE
{
    struct NODE *link;
    int value;
}Node;

int sll_count_node(Node *first);
int sll_insert(register Node **linkp, int new_value);
Node *sll_search_node(Node *first, int value);
Node *sll_reverse(Node *linkptr);
int sll_remove(Node **linkptr, Node *node);

int main(void)
{
    Node *root = NULL;
    Node *test = NULL;
    sll_insert(&root, 1);
    sll_insert(&root, 3);
    sll_insert(&root, 2);

    printf("count:%d\n", sll_count_node(root));
    
    root = sll_reverse(root);
    sll_remove(&root, root);
    

    if((test = sll_search_node(root, 4)) != NULL)
    {
        printf("search success value: %d\n", test->value);
    }
    else
    {
        printf("Not the result of searching.\n");
    }
    
    return 0;
}

int sll_count_node(Node *first)
{
    int count = 1;

    while((first = first->link) != NULL)
    {
        count++;
    }
    return count;
}

Node *sll_search_node(Node *first, int value)
{
    Node *current;

    for(current = first; current->link != NULL; current = current->link)
    {
        if(value == current->value)
        {
            break;
        }
    }
    //到最后一个节点还是没找到对应值
    if(current->value != value)
    {
        return NULL;
    }

    return current;
}

int sll_insert(register Node **linkp, int new_value)
{
    register Node *current;
    register Node *new;
    //寻找正确的插入位置
    while((current = *linkp) != NULL && current->value < new_value)
    {
        linkp = &current->link;
    }
    
    new = (Node *)malloc(sizeof(Node));
    if(new == NULL)
    {
        return FALSE;
    }
    new->value = new_value;
    //在链表中插入新节点
    new->link = current;
    *linkp = new;
    return TRUE;
}

Node *sll_reverse(Node *linkptr)
{
    Node *current = NULL;
    Node *next = NULL;
    Node *tmp_ptr = NULL;
    
    while ((next = linkptr) != NULL)
    {
        linkptr = next->link;
        next->link = current;
        current = next; 
    }

    return current;
}

/**
 * 使用指向头指针的指针作为参数传入
 * 因为如果删除第一个节点，需要修改头指针的指向
 */
int sll_remove(Node **linkptr, Node *node)
{
    Node *current;

    assert(node != NULL);

    while((current = *linkptr) != NULL && current != node)
    {
        linkptr = &current->link;
    }

    if(current == node)
    {
        *linkptr = current->link;
        free(current);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}