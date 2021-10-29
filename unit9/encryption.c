/*
 * @Author: Celery
 * @Date: 2021-10-20 14:53:43
 * @LastEditTime: 2021-10-20 16:10:26
 * @LastEditors: Celery
 * @Description: 对数据进行加解密
 * @FilePath: \unit9\encryption.c
 * 
 */
#include "stdio.h"
#include "string.h"
#include "ctype.h"


char alpha_table[27] = "abcdefghijklmnopqrstuvwxyz";

int prepare_key(char *key);
void encrypt(char *data, char const *key);
void decrypt(char *data, char const *key);

int main(void)
{
    char key[27] =  "trailblazers";
    char data[] =  "ATTACK AT DAWN";

    prepare_key(key);
    printf("key: %s\n", key);

    encrypt(data, key);
    printf("data: %s\n", data);

    decrypt(data, key);
    printf("data: %s\n", data);

    return 0;
}

/**
 * @description: 将单词转换为密钥
 * @param {char} *key
 * @return {*}0:异常，1：成功
 */
int prepare_key(char *key)
{
    char *p = key;
    char *p_start = key;
    while(*key != '\0')
    {
        if(!isalnum(*key))  
        {
            return 0;
        }
        *key = towlower(*key);
        p = key;
        while(p != (key = strrchr(key, *key)))
        {
            strcpy(key, key + 1);
            key = p;
        }
        key++;
    }

    for(int i = 0; i < 27; i++)
    {
        if(strchr(p_start, alpha_table[i]) == NULL)
        {
            *key++ = alpha_table[i];
        }
    }
    *key = '\0';
    return 1;
}

/**
 * @description: 对数据进行加密
 * @param {char} *data
 * @return {*}
 */
void encrypt(char *data, char const *key)
{
    int index = 0;
    while(*data != '\0')
    {
        if(islower(*data))
        {
            index = strchr(alpha_table, *data) - alpha_table;
            *data = *(key + index);
        }
        else if(isupper(*data))
        {
            *data = tolower(*data);
            index = strchr(alpha_table, *data) - alpha_table;
            *data = toupper(*(key + index));
        }
        data++;
    }
}

/**
 * @description: 对数据进行解密
 * @param {char} *data
 * @return {*}
 */
void decrypt(char *data, char const *key)
{
    int index = 0;
    while(*data != '\0')
    {
        if(islower(*data))
        {
            index = strchr(key, *data) - key;
            *data = *(alpha_table + index);
        }
        else if(isupper(*data))
        {
            *data = tolower(*data);
            index = strchr(key, *data) - key;
            *data = toupper(*(alpha_table + index));
        }
        data++;
    }
}
