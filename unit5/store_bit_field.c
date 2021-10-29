/*
* @Author: Celery
* @Date:   2021-10-14 14:18:34
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-14 14:49:56
*/
#include "stdio.h"

int store_bit_field(int original_value, int value_to_store, unsigned int starting_bit, unsigned int ending_bit);

int main(void)
{
	int original_value = 0xffff;
	int value_to_store = 0x123;
	unsigned int starting_bit = 13;
	unsigned int ending_bit = 9;

	printf("resule:%x\n", store_bit_field(original_value, value_to_store, starting_bit, ending_bit));
	
	return 0;
}


int store_bit_field(int original_value, int value_to_store, unsigned int starting_bit, unsigned int ending_bit)
{
	int mask = 0;
	int i = 0;

	//设置掩码
	for(i = starting_bit; i >= ending_bit; i--)
	{
		mask |= (1 << i);
	}
	printf("mask: %x\n", mask);
	original_value &= ~mask;
	printf("%x\n", original_value);

	printf("value_to_store: %x\n", value_to_store);
	value_to_store <<= ending_bit;

	value_to_store &= mask;
	printf("value_to_store: %x\n", value_to_store);

	return (original_value | value_to_store);
}

