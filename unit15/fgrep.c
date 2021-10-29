/*
 * @Author: Celery
 * @Date: 2021-10-27 20:22:24
 * @LastEditTime: 2021-10-27 21:08:24
 * @LastEditors: Celery
 * @Description: 实现fgrep程序,在指定的文件中，查找并打印所有包含字符串的文本行
 * @FilePath: \unit12c:\source\pointer_on_c\unit15\fgrep.c
 * 
 */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define BUFSIZE 512

void search(char *filename, FILE *stream, char *string);

int main(int argc, char **argv)
{
    char *string;
    FILE *stream;
    if(argc <= 1)
    {
        fprintf(stderr, "Usage of string file!");
        exit(EXIT_FAILURE);
    }

    string = *++argv;

    if(argc <= 2)
    {
        search(NULL, stdin, string);
    }
    else
    {
        while(*++argv != NULL)
        {
            stream = fopen(*argv, "r");
            if(stream == NULL)
            {
                perror(*argv);
            }
            search(*argv, stream, string);
            fclose(stream);
        }
    }
    return EXIT_SUCCESS;
}

void search(char *filename, FILE *stream, char *string)
{
    char buf[BUFSIZE];

    while(fgets(buf, BUFSIZE, stream) != NULL)
    {
        if(strstr(buf, string) != NULL)
        {
            if(filename != NULL)
            {
                printf("%s :", filename);
            }
            fputs(buf, stdout);
        }
    }
}
