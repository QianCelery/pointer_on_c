#include <stdio.h>

int main(void)
{
	double sqrt, next_result, cur_result;
	next_result = 0;

	printf("input the number : \n");
	scanf("%f", sqrt);
	next_result = 1;
	printf("The current result is : %.15e\n", next_result);
	while(cur_result != next_result)
	{
		cur_result = next_result;
		next_result = (cur_result + (sqrt / cur_result)) / 2;
		printf("The current result is : %.15e\n", next_result);
	}

	printf("The result is : %.15e\n", cur_result);

	return 1;
}