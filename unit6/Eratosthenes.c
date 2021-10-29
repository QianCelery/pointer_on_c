/*
* @Author: Celery
* @Date:   2021-10-14 19:16:18
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-14 19:52:08
*/
#include "stdio.h"
#include "string.h"

int eratosthenes(char *arr, int n);

int main(void)
{
	char arr[100] = {0};

	memset(arr, 1, 100);
	//printf("%d\n", arr[999]);
	printf("result: %d\n", eratosthenes(arr, 100));

	return 0;
}

int eratosthenes(char *arr, int n)
{
	int i = 0;
	int mul = 0;
	int result = 0;

	*arr = 0;
	*(arr + 1) = 0;

	for(mul = 2; mul < n; mul++)
	{
		if(*(arr + mul) == 0)
		{
			continue;
		}
		for(i = 2 * mul; i < n; i +=mul)
		{
			*(arr + i) = 0;
		}
	}

	for(i = 0; i < n; i++)
	{
		if(*(arr + i) == 1)
		{
			result++;
		}
	}

	return result;
}