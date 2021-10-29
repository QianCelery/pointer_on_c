/*
 * @Author: Celery
 * @Date: 2021-10-28 20:55:35
 * @LastEditTime: 2021-10-29 16:22:22
 * @LastEditors: Celery
 * @Description: 
 * @FilePath: \unit16\die.c
 * 
 */
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define MAX_OK_RAND    (int)((((long)RAND_MAX + 1) / 6) * 6 - 1)

int throw_die(void)
{
    static int is_seed = 0;
    int value;

    if(!is_seed )
    {
        is_seed = 1;
        srand((unsigned int)time(NULL));
    }

    do
    {
        value = rand();
    } while (value > MAX_OK_RAND);
    
    return value % 6 + 1;
}

int main(void)
{
    int die_value;

    die_value = throw_die();
    die_value = throw_die();
    die_value = throw_die();
    die_value = throw_die();
    return 0;
}