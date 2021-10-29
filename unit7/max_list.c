/*
* @Author: Celery
* @Date:   2021-10-15 16:35:15
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-15 16:41:51
*/
#include "stdio.h"
#include "stdarg.h"
int max_list(int n, ...);

int main(void)
{
	int result = 0;
	result = max_list(10, 3, 4, 5, 11, 33, 22, 11, 1, -1);
	printf("result: %d\n", result);
	return 0;
}

int max_list(int n, ...)
{
	va_list var_arg;
	int max_value = 0;
	int tmp = 0;

	va_start(var_arg, n);

	for(n; n > 0; n--)
	{
		tmp = va_arg(var_arg, int);
		if(tmp < 0)
		{
			return max_value;
		}
		if(max_value < tmp)
		{
			max_value = tmp;
		}

	}

	return	max_value;
}