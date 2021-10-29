/*
 * @Author: Celery
 * @Date: 2021-10-20 16:16:11
 * @LastEditTime: 2021-10-20 17:17:18
 * @LastEditors: Celery
 * @Description: 按美元格式化输入字符串
 * @FilePath: \unit9\dollars.c
 * 
 */
#include "stdio.h"
#include "string.h"

void dollars(char *dst, char const *src);

int main(void)
{
    char num[] = "1";
    char dollar[100] = {0};

    dollars(dollar, num);
    printf("dollars: %s\n", dollar);
    return 0;
}

/**
 * @description: 胡言乱语
 * @param {char} *dst
 * @return {*}
 */
// void dollars(char *dst, char const *src)
// {
//     int count_1000  = 0;
//     int index = 0;
//     int len = strlen(src);

//     if((dst == NULL) || (src == NULL))
//     {
//         return;
//     }

//     *dst++ = '$';  

//     if(len > 5)
//     {
//         count_1000 = (len - 6) / 3 + 1;

//         index = (len - 5) % 3;
//     }
//     else if(len >= 3)
//     {
//         index = len;
//     }
//     else
//     {
//         index = 3;
//     }


//     for(int i = 0; i < len + count_1000 + 2; i++)
//     {
//         if(count_1000 != 0)
//         {
            
//             if(index == 0)
//             {
//                 *dst++ = ',';
//                 index = 3;
//                 count_1000--;
//                 if(count_1000 == 0)
//                 {
//                     index = 5;
//                 }
//                 continue;
//             }
//             index--;
//         }
//         else
//         {
//             index--;
//             if(index == 1)
//             {
//                 *dst++ = '.';
//             }
//         }

//         if(len < 3)
//         {
//             if(index >= len)
//             {
//                 *dst++ = '0';
//             }
//             else
//             {
//                 *dst++ = *src++;
//             }
//         }
//         else
//         {
//             *dst++ = *src++;
//         }
        
//     }
    
// }

/**
 * @description: 拙劣的模仿
 * @param {char} *dst
 * @return {*}
 */
void dollars( char *dst,  char const *src)
{
    int len = strlen(src);

    *dst++ = '$';

    if(len >= 3)
    {
        for(int i = len - 2; i > 0;)
        {
            *dst++ = *src++;
            if((--i > 0) && (i % 3 == 0))
            {
                *dst++ = ',';
            }
        }
    }
    else
    {
        *dst++ = '0';
    }

    *dst++ = '.';
    *dst++ = (len < 2 ? '0' : (*src++));
    *dst++ = (len < 1 ? '0' : *src);
    *dst = 0;
    
}
