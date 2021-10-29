/*
* @Author: Celery
* @Date:   2021-10-14 11:11:39
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-14 11:23:36
*/
#include "stdio.h"
#include "stdbool.h"

void set_bit(char bit_arry[], unsigned bit_number);

void clear_bit(char bit_arry[], unsigned bit_number);

void assign_bit(char bit_arry[], unsigned bit_number, int value);

bool test_bit(char bit_arry[], unsigned bit_number);

int main(void)
{
	char bit_arry[100] = {0};
	printf("%s\n", bit_arry);
	set_bit(bit_arry, 0);
	set_bit(bit_arry, 1);
	set_bit(bit_arry, 2);
	set_bit(bit_arry, 3);
	printf("%s\n", bit_arry);

	clear_bit(bit_arry, 2);
	printf("%s\n", bit_arry);

	assign_bit(bit_arry, 2, 1);
	printf("%s\n", bit_arry);

	if(test_bit(bit_arry, 2))
		printf("test true1\n");
}

void set_bit(char bit_arry[], unsigned bit_number)
{
	bit_arry[bit_number] = 1;
}

void clear_bit(char bit_arry[], unsigned bit_number)
{
	bit_arry[bit_number] = 0;
}

void assign_bit(char bit_arry[], unsigned bit_number, int value)
{
	if(value == 0)
	{
		bit_arry[bit_number] = 0;
	}
	else
	{
		bit_arry[bit_number] = 1;
	}
}

bool test_bit(char bit_arry[], unsigned bit_number)
{
	if(bit_arry[bit_number] == 1)
	{
		return true;
	}
	if(bit_arry[bit_number] == 0)
	{
		return false;
	}
}