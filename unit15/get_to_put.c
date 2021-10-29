/*
 * @Author: Celery
 * @Date: 2021-10-27 19:59:18
 * @LastEditTime: 2021-10-27 20:15:36
 * @LastEditors: Celery
 * @Description: 
 * @FilePath: \unit12c:\source\pointer_on_c\unit15\get_to_put.c
 * 
 */
#include "stdio.h"

#define BUFSIZE 82  //需要加上末尾的'0'与换行

void gets_to_puts(char *buf);


int main(void)
{
    char buf[BUFSIZE] = {0};

    gets_to_puts(buf);
    return 0;
}

void gets_to_puts(char *buf)
{
    FILE *filein = fopen("C:\\source\\pointer_on_c\\unit15\\text1.txt", "r");
    FILE *fileout = fopen("C:\\source\\pointer_on_c\\unit15\\text2.txt", "w");
    while (fgets(buf, 80, filein) != NULL)
    {
        fputs(buf, fileout);
    }
    fclose(filein);
    fclose(fileout);
    
}
