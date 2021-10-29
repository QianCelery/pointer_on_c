/*
* @Author: Celery
* @Date:   2021-10-15 16:18:18
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-15 16:34:45
*/
#include "stdio.h"

int ascii_to_integer(char *string);

int main(void)
{
	char string[] = "12345678";

	printf("result: %d\n", ascii_to_integer(string));
	return 0;
}

//不使用递归，应该使用迭代
int ascii_to_integer(char *string)
{
	int result = 0;	

	while((*string >= '0') && (*string <= '9'))
	{
		result *= 10;
		result += *string++ - '0';
	}

	return result;

}