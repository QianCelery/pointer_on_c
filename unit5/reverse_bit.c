/*
* @Author: Celery
* @Date:   2021-10-14 10:08:31
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-14 11:11:24
*/
#include "stdio.h"

unsigned int reverse_bit(unsigned int value);

int main(void)
{
	unsigned int test_num = 0b11001;

	//test_num = reverse_bit(test_num);

	printf("%u\n", reverse_bit(test_num));
	return 0;
}


unsigned int reverse_bit(unsigned int value)
{
	unsigned int result = 0;
	unsigned int i = 0;

	for(i = 1; i != 0; i <<= 1)
	{
		result <<= 1;
		if(value & 1)
		{
			result |= 1;
		}
		value >>= 1;
		

	}

	return result;
}