/*
* @Author: Celery
* @Date:   2021-10-15 21:54:59
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-15 22:09:57
*/
#include "stdio.h"
#include "float.h"

static double income_limits[]
= {0, 23350, 56550, 117950, 256500};
static float base_tax[]
= {0, 3502.50, 12798.50, 31832.50, 81710.50};
static float percentage[]
= {.15, .28, .31, .36, .396};

float single_tax(float income);

int main(void)
{
	float income = 88888;
	printf("result: %f\n", single_tax(income));
	return 0;
}

float single_tax(float income)
{
	int category;

	for(category = 1; income >= income_limits[category]; category++)
		;

	return (base_tax[category] + ((income - income_limits[category]) * percentage[category]));
}