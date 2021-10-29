/*
* @Author: Celery
* @Date:   2021-10-16 20:35:43
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-16 21:04:42
*/
#include "stdio.h"

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z);

int main(void)
{
	int m1[3][2] = 
	{
		{2, -6},
		{3, 5},
		{1, -1}
	};
	int m2[2][4] = 
	{
		{4, -2, -4, -5},
		{-7, -3, 6, 7}
	};
	int r[3][4] = {0};
	int i = 0;

	matrix_multiply((int *)m1, (int *)m2, (int *)r, 3, 2, 4);
	for(i = 0; i < 3; i++)
	{
		printf("%d %d %d %d\n", r[i][0], r[i][1], r[i][2], r[i][3]);
	}

	return 0;
}

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{
	int i = 0, j = 0, k = 0;

	for(i = 0; i < x; i++)
	{
		for(j = 0; j < z; j++)
		{
			for(k = 0; k< y; k++)
			{
				*r += (*(m1 + i * y + k)) * (*(m2 + j + k * z));
			}
			r++;
		}

	}
}