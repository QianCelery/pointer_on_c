void dollars(char *dst, char const *src)
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