/*
* @Author: Celery
* @Date:   2021-10-15 16:42:33
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-15 18:53:06
*/
#include "stdio.h"
#include "string.h"

void written_amount(unsigned int amount, char *buffer);
char *written_hundred(unsigned int number, char *buffer);
char *written_word(unsigned int number, char *buffer);

int main(void)
{
	unsigned int test_number = 987654;
	char buffer[1000] = {0};
	written_amount(test_number, buffer);
	printf("%s\n", buffer);

	return 0;
}

void written_amount(unsigned int amount, char *buffer)
{
	int count = 0;
	int tmp_amount = amount;
	int million_tmp = 0;
	int thousan_tmp = 0;
	int hundred_tmp = 0;
	while(tmp_amount != 0)
	{
		count++;
		tmp_amount /= 10;
	}
	tmp_amount = amount;
	if(count > 9 )
	{
		printf("out of scope!!\n");
	}
	else if(count  >= 7)
	{
		million_tmp = tmp_amount / 1000000;
		buffer = written_hundred(million_tmp, buffer);
		buffer = written_word(1000000, buffer);
		thousan_tmp = (tmp_amount % 1000000) / 1000;
		if(thousan_tmp != 0)
		{
			buffer = written_hundred(thousan_tmp, buffer);
			buffer = written_word(1000, buffer);
		}
		hundred_tmp = tmp_amount % 1000;
		if(hundred_tmp != 0)
		{
			buffer = written_hundred(hundred_tmp, buffer);
		}
	}
	else if(count >= 4)
	{
		thousan_tmp = tmp_amount / 1000;
		buffer = written_hundred(thousan_tmp, buffer);
		buffer = written_word(1000, buffer);
		hundred_tmp = tmp_amount % 1000;
		if(hundred_tmp != 0)
		{
			buffer = written_hundred(hundred_tmp, buffer);
		}
	}
	else
	{
		hundred_tmp = tmp_amount;
		buffer = written_hundred(hundred_tmp, buffer);
	}
}

//转换一个百位数
char *written_hundred(unsigned int number, char *buffer)
{
	int tmp = number;
	if(number >= 100)
	{
		buffer = written_word(number / 100, buffer);
		buffer = written_word(100, buffer);
		tmp = number % 100;
		if(tmp % 10 == 0)
		{
			buffer = written_word(tmp, buffer);
		}
		else if(tmp > 20)
		{
			buffer = written_word(tmp / 10 * 10, buffer);
			buffer = written_word(tmp % 10, buffer);
		}
		else
		{
			buffer = written_word(tmp, buffer);
		}
	}
	else if(number >= 10)
	{
		if(tmp % 10 == 0)
		{
			buffer = written_word(tmp, buffer);
		}
		else if(tmp > 20)
		{
			buffer = written_word(tmp / 10 * 10, buffer);
			buffer = written_word(tmp % 10, buffer);
		}
		else
		{
			buffer = written_word(tmp, buffer);
		}
	}
	else
	{
		buffer = written_word(tmp, buffer);
	}

	return buffer;
}

//转换一个数字
char *written_word(unsigned int number, char *buffer)
{
	switch(number)
	{
		case 1: 
		{
			memcpy(buffer, "ONE", 3);
			buffer += 3;
			break;
		}
		case 2:
		{
			memcpy(buffer, "TWO", 3);
			buffer += 3;
			break;
		}
		case 3:
		{
			memcpy(buffer, "THREE", 5);
			buffer += 5;
			break;
		}
		case 4:
		{
			memcpy(buffer, "FOUR", 4);
			buffer += 4;
			break;
		}
		case 5:
		{
			memcpy(buffer, "FIVE", 4);
			buffer += 4;
			break;
		}
		case 6:
		{
			memcpy(buffer, "SIX", 3);
			buffer += 3;
			break;
		}
		case 7:
		{
			memcpy(buffer, "SEVEN", 5);
			buffer += 5;
			break;
		}
		case 8:
		{
			memcpy(buffer, "EIGHT", 5);
			buffer += 5;
			break;
		}
		case 9:
		{
			memcpy(buffer, "NINE", 4);
			buffer += 4;
			break;
		}
		case 10:
		{
			memcpy(buffer, "TEN", 3);
			buffer += 3;
			break;
		}
		case 11: 
		{
			memcpy(buffer, "ELEVEN", 6);
			buffer += 6;
			break;
		}
		case 12:
		{
			memcpy(buffer, "TWELVE", 6);
			buffer += 6;
			break;
		}
		case 13:
		{
			memcpy(buffer, "THIRTEEN", 8);
			buffer += 8;
			break;
		}
		case 14:
		{
			memcpy(buffer, "FOURTEEN", 8);
			buffer += 8;
			break;
		}
		case 15:
		{
			memcpy(buffer, "FIFTEEN", 7);
			buffer += 7;
			break;
		}
		case 16:
		{
			memcpy(buffer, "SIWTEEN", 7);
			buffer += 7;
			break;
		}
		case 17:
		{
			memcpy(buffer, "SEVENTEEN", 9);
			buffer += 9;
			break;
		}
		case 18:
		{
			memcpy(buffer, "EIGHTEEN", 8);
			buffer += 8;
			break;
		}
		case 19:
		{
			memcpy(buffer, "NINETEEN", 8);
			buffer += 8;
			break;
		}
		case 20:
		{
			memcpy(buffer, "TWENTY", 6);
			buffer += 6;
			break;
		}
		case 30:
		{
			memcpy(buffer, "THIRTY", 6);
			buffer += 6;
			break;
		}
		case 40:
		{
			memcpy(buffer, "FOURTY", 6);
			buffer += 6;
			break;
		}
		case 50:
		{
			memcpy(buffer, "FIFTY", 5);
			buffer += 5;
			break;
		}
		case 60:
		{
			memcpy(buffer, "SIXTY", 5);
			buffer += 5;
			break;
		}
		case 70:
		{
			memcpy(buffer, "SEVENTY", 7);
			buffer += 7;
			break;
		}
		case 80:
		{
			memcpy(buffer, "EIGHTY", 6);
			buffer += 6;
			break;
		}
		case 90:
		{
			memcpy(buffer, "NINETY", 6);
			buffer += 6;
			break;
		}
		case 100:
		{
			memcpy(buffer, "HUNDRED", 7);
			buffer += 7;
			break;
		}
		case 1000:
		{
			memcpy(buffer, "THOUSAND", 8);
			buffer += 8;
			break;
		}
		case 1000000:
		{
			memcpy(buffer, "MILLION", 7);
			buffer += 7;
			break;
		}

		default : ;
	}

	*buffer++ = ' ';
	return buffer;
}