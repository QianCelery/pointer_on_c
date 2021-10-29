/*
 * @Author: Celery
 * @Date: 2021-10-22 17:06:03
 * @LastEditTime: 2021-10-23 15:38:57
 * @LastEditors: Celery
 * @Description: 双链表操作
 * @FilePath: \unit10c:\source\pointer_on_c\unit12\dll_node.c
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

typedef struct NODE
{
    struct NODE *fwd;
    struct NODE *bwd;
    int value;
}Node;

int dll_insert(register Node *rootp, int value);
int dll_insert_ptrmode(Node **root_fwd, Node **root_bwd, int value);
int dll_remove(Node *rootptr, Node *node);

int main(void)
{
    //Node first = {NULL, NULL, 0};
   
    Node root = {NULL, NULL, 0};
    Node *root_fwd = root.fwd;
    Node *root_bwd = root.bwd;

    dll_insert(&root, 1);
    dll_insert(&root, 3);
    dll_insert(&root, 2);
    // root_fwd = root.fwd;
    // root_bwd = root.bwd;
    // dll_insert_ptrmode(&root_fwd, &root_bwd, -1);
    // dll_insert_ptrmode(&root_fwd, &root_bwd, 2);
    // dll_insert_ptrmode(&root_fwd, &root_bwd, 7);
    // dll_insert_ptrmode(&root_fwd, &root_bwd, 0);

    dll_remove(&root, root.fwd);
    dll_remove(&root, root.bwd);
    dll_remove(&root, root.fwd);


    return 0;
}

int dll_insert(register Node *rootp, int value)
{
    register Node *this;
    register Node *next;
    register Node *newnode;
    /**
     * 查看value是否已经存在于链表中，如果是就返回
     * 否则，为新值创建一个新节点（newnode指向它）
     * "this"将指向在新节点之前的那个节点
     * "next"将指向在新节点之后的那个节点
     */
    for(this = rootp; (next = this->fwd) != NULL; this = next)
    {
        if(next->value == value)
        {
            return 0;
        }
        if(next->value > value)
        {
            break;
        }
	}
    newnode = (Node *)malloc(sizeof(Node));
    if(newnode == NULL)
    {
        return -1;
	}
    newnode->value = value;
    
    /**
     * 把新节点添加到链表中
     */
    newnode->fwd = next;
    this->fwd = newnode;
    
    if(this != rootp)
        newnode->bwd = this;
    else
        newnode->bwd = NULL;
    if(next != NULL)
        next->bwd = newnode;
    else
        rootp->bwd = newnode;
    
    return 1;
}

int dll_insert_ptrmode(Node **root_fwd, Node **root_bwd, int value)
{
    Node *this = NULL;
    Node *next = NULL;
    Node *newnode = NULL;

     /**
     * 查看value是否已经存在于链表中，如果是就返回
     * 否则，为新值创建一个新节点（newnode指向它）
     * "this"将指向在新节点之前的那个节点
     * "next"将指向在新节点之后的那个节点
     */
    // for(this = *root_fwd; (next = this->fwd) != NULL; this = next)
    // {
    //     if(next->value == value)
    //     {
    //         return 0;
    //     }
    //     if(next->value > value)
    //     {
    //         break;
    //     }
    // }
    this = *root_fwd;
    next = *root_fwd;
    do
    {
        if(next->value == value)
        {
            return 0;
        }
        if(next->value > value)
        {
            break;
        }
        this = next;
    } while ((next = this->fwd) != NULL);
    

    newnode = (Node *)malloc(sizeof(Node));
    if(newnode == NULL)
    {
        return -1;
    }

    newnode->value = value;

    /**
     * 把新节点添加到链表中
     */
    newnode->fwd = next;
    //this->fwd = newnode;
    

    if(this != *root_fwd)
    {
        newnode->bwd = this;
        this->fwd = newnode;
    }
    else
    {
        newnode->bwd = NULL;
        if(next == *root_fwd)
        {
            *root_fwd = newnode;
        }
        else
        {
            this->fwd = newnode;
        }
    }

    if(next != NULL)
    {
        next->bwd = newnode;
    }
    else
    {
        *root_bwd = newnode;
    }

    return 1;
}

int dll_remove(Node *rootptr, Node *node)
{
    Node *current;
    Node *next;

    for(current = rootptr; (next = current->fwd) != NULL; current = next)
    {
        if(next == node)
        {
            break;
        }
    }

    if(next == node)
    {
        current->fwd = next->fwd;
        if(next->fwd == NULL)    //删除最后一个节点
        {
            rootptr->bwd = current;
        }
        else
        {
            next->fwd->bwd = current;
        }
        free(next);
        return 1;
    }
    else
    {
        return 0;
    }
}