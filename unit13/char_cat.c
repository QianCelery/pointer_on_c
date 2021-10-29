/*
 * @Author: Celery
 * @Date: 2021-10-25 19:00:12
 * @LastEditTime: 2021-10-25 19:33:26
 * @LastEditors: Celery
 * @Description: 统计各类字符百分比
 * @FilePath: \unit12c:\source\pointer_on_c\unit13\char_cat.c
 * 
 */
#include "stdio.h"
#include "ctype.h"

int is_not_print(int ch)
{
    return !isprint(ch);
}

int (*test_func[]) (int) =
{
    iscntrl,
    isspace,
    isdigit,
    isupper,
    islower,
    ispunct,
    is_not_print
};

#define N_CATEGORIES ((sizeof(test_func)) / sizeof(test_func[0]))

//每类字符类型的名字
char *label[] = 
{
    "control",
    "whitespace",
    "digit",
    "lower case",
    "upper case",
    "punctuation",
    "non-printable"
};

int count[N_CATEGORIES];
int total;

int main(void)
{
    int ch;
    int categories;

    while((ch = getchar()) != EOF)
    {
        total++;
        for(categories = 0; categories < N_CATEGORIES; categories++)
        {
            if(test_func[categories](ch))
                count[categories]++;
        }
    }

    if(total == 0)
    {
        printf("there is no input char!\n");
    }
    else
    {
        for(categories = 0; categories < N_CATEGORIES; categories++)
        {
            printf("%s:%3.0f%%\n", label[categories], (count[categories] * 100.0) / total );
        }
    }

    return 1;
}
