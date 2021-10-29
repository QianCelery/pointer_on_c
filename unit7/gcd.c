/*
* @Author: Celery
* @Date:   2021-10-15 16:09:33
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-15 16:22:10
*/
#include "stdio.h"

int gcd(int m, int n);

int main(void)
{
	int m = 4;
	int n = 25;
	printf("result: %d\n", gcd(m, n));
	return 0;
}

int gcd(int m, int n)
{
	if((m < 0) || (n < 0))
	{
		return 0;
	}
	if(m % n == 0)
	{
		return n;
	}
	else
	{
		return (gcd(n, m % n));
	}
}