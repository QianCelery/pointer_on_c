/*
 * @Author: Celery
 * @Date: 2021-10-27 10:25:06
 * @LastEditTime: 2021-10-27 10:28:41
 * @LastEditors: Celery
 * @Description: 
 * @FilePath: \unit12c:\source\pointer_on_c\unit13\print_ledger.c
 * 
 */
#include "stdio.h"

void print_ledger(int x)
{
    #ifdef OPTION_LONG
        #defined OK     1
        print_ledger_long(x);
    #endif

    #ifdef OPTION_DETAILED
        #defined OK     1
        print_ledger_detailed(x);
    #endif

    #ifndef OK
        print_ledger_default(x);
    #endif

}