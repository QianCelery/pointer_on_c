/*
* @Author: Celery
* @Date:   2021-10-14 18:51:15
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-14 19:10:41
*/
#include "stdio.h"

void reverse_string(char *string);

int main(void)
{
	char string[] = "abcdefg";
	printf("%s\n", string);
	reverse_string(string);
	printf("%s\n", string);

	return 0;
}
/**
 * 反向排列
 * @Author   celery
 * @DateTime 2021-10-14T18:53:22+0800
 * @param    string                   [需要操作的字符串]
 */
void reverse_string(char *string)
{
	int tmp = 0;
	char *p_end = string;

	while(*p_end != '\0')
	{
		p_end++;
	}
	p_end--;

	while(string < p_end)
	{
		tmp = *(p_end);
		*(p_end--) = *string;
		*(string++) = tmp;
	}
}
