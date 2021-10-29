/*
 * @Author: Celery
 * @Date: 2021-10-23 15:51:41
 * @LastEditTime: 2021-10-23 19:19:57
 * @LastEditors: Celery
 * @Description: 分解(横向匹配首字母，纵向查找)字母链表，一级链表为按照字母进行排序，二级链表按照单词顺序排序
 * @FilePath: \unit10c:\source\pointer_on_c\unit12\concordance_list.c
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef struct WORD_NODE
{
    char word[50];  //可以设置为指针，再进行动态内存分配
    struct WORD_NODE *word_link;
}Word_node;

typedef struct CONCORDANCE_NODE
{
    char alpha;
    struct CONCORDANCE_NODE *alpha_link;
    Word_node  *word_link;
}Concordance_node;

int creat_concordance_list(Concordance_node **rootptr);
int insert_concordance_list(Concordance_node **list, char *string);

int main(void)
{
    Concordance_node *root;
    creat_concordance_list(&root);

    insert_concordance_list(&root, "abcd");
    insert_concordance_list(&root, "bacd");
    insert_concordance_list(&root, "cacd");
    insert_concordance_list(&root, "accd");


    return 0;
}

/**
 * @description: 查找，并在对应二级链表中插入数据
 * @param {Concordance_node} * listptr一级链表头指针的指针
 * @param {char} *string    插入数据
 * @return {*}
 */
int insert_concordance_list(Concordance_node **listptr, char *string)
{
    Concordance_node *current_alpha;
    Word_node **word_linkptr;
    Word_node *current_word;
    Word_node *newnode;

    if(!isalpha(*string))
    {
        return -1;
    }

    //按照字母索引进行查找
    current_alpha = *listptr;
    while ((current_alpha->alpha_link != NULL) && (current_alpha->alpha != (tolower(*string))))
    {
        listptr = &current_alpha->alpha_link;
        current_alpha = *listptr;
    }
    
    word_linkptr = &current_alpha->word_link;
    while(((current_word = *word_linkptr) != NULL) && (strcmp(current_word->word, string) < 0))
    {
        word_linkptr = &current_word->word_link;
    }

    if((current_word != NULL) && (strcmp(current_word->word, string) == 0))
    {
        return -2;
    }

    newnode = (Word_node *)malloc(sizeof(Word_node));
    if(newnode == NULL)
    {
        return 0;
    }
    strcpy(newnode->word, string);

    newnode->word_link = current_word;

    *word_linkptr = newnode;

    return 1;
    
}

/**
 * @description: 创建一级链表
 * @param {Concordance_node} * rootptr : 头指针 
 * @return {*}
 */
int creat_concordance_list(Concordance_node **rootptr)
{
    int i;
    Concordance_node *newnode;
    Concordance_node *current;

    //需要先分配内存，一级链表第一个节点还不存在
    *rootptr = (Concordance_node *)malloc(sizeof(Concordance_node));
    if((*rootptr) == NULL)
    {
        return 0;
    }
    current = *rootptr;
    current->alpha = 'a';
    current->alpha_link = NULL;
    current->word_link = NULL;
    

    for(i = 1; i < 26; i++)
    {
        newnode = (Concordance_node *)malloc(sizeof(Concordance_node));
        if(newnode == NULL)
        {
            return 0;
        }
        newnode->alpha = 'a' + i;
        newnode->word_link = NULL;
        newnode->alpha_link = NULL;
        current->alpha_link = newnode;
        current = newnode;
    }

    return 1;
}