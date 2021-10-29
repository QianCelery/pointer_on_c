/*
* @Author: Celery
* @Date:   2021-10-15 22:10:48
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-16 22:05:46
*/
#include "stdio.h"
#include "stdbool.h"

bool identity(int *matrix, int n);

int main(void)
{
	int matrix[][10] = 
	{
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	};

	printf("result: %d\n", identity((int *)matrix, 10));
	return 0;
}


bool identity(int *matrix, int n)
{
	int i = 0, j = 0;

	for(i = 0; i < n; i++)
	{
		if(*(matrix + i * n + i) != 1)
		{
			return false;
		}
		for(j = 0; j < n; j++)
		{
			if((*(matrix + i * n + j) != 0) && (i != j))
			{
				return false;
			}
		}
	}

	return true;
}