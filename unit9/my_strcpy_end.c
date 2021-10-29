/*
 * @Author: Celery
 * @Date: 2021-10-19 20:47:11
 * @LastEditTime: 2021-10-19 21:04:41
 * @LastEditors: Celery
 * @Description: 自定义strcpy，返回指针指向目标字符串末尾
 * @FilePath: \unit9\my_strcpy_end.c
 * 
 */
#include "stdio.h"

char *my_strcpy_end(char *dst, char const *src);

int main(void)
{
    char dst[] = "abcd";
    char src[] = "1234";

    printf("initial address:%d\n", (int)dst);
    printf("final address:%d\n", (int)my_strcpy_end(dst, src));
    return 0;
}

char *my_strcpy_end(char *dst, char const *src)
{
    while(((*dst++) = (*src++)) != '\0')
        ;
    
    return dst - 1;
}