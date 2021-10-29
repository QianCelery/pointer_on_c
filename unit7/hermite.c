/*
* @Author: Celery
* @Date:   2021-10-15 15:59:37
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-15 16:09:04
*/
#include "stdio.h"

int hemite(int n, int x);

int main(void)
{	
	int n = 3;
	int x = 2;

	printf("result: %d\n", hemite(n, x));
	return 0;
}


int hemite(int n, int x)
{
	if(n < 1)
	{
		return 1;
	}
	else if(n == 1)
	{
		return 2 * x;
	}
	else
	{
		return ((2 * x * hemite(n - 1 , x)) - (2 * (n - 1) * hemite(n - 2, x)));
	}
}