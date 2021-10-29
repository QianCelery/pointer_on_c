/*
* @Author: Celery
* @Date:   2021-10-14 15:15:47
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-14 21:17:28
*/
#include "stdio.h"

int del_substr(char *str, char const *substr);

int main(void)
{
	char str[] = "ABCDEFG";
	char substr[] = "FG";

	printf("result: %d\n", del_substr(str, substr));

	printf("%s\n", str);
	return 0;
}

int del_substr(char *str, char const *substr)
{
	char *p_str = str;
	char const *p_substr = substr;
	int find_result = 0;
	int find_index = 0;
	int len_substr = 0;

	if((p_str == NULL) || (p_substr == NULL))
	{
		return 0;
	}

	while((*p_str) != '\0')
	{
		if((*p_substr) == (*p_str))
		{
			while((*p_substr) != '\0')
			{
				if((*p_str) != (*p_substr))
					break;
				p_substr++;
				p_str++;
				len_substr++;
			}
			if((*p_substr == '\0'))
			{
				find_result =  1;
			}
			p_substr = substr;
		}
		if(find_result == 1)
		{
			break;
		}
		find_index++;
		p_str++;
	}

	p_str = str + find_index;

	if(find_result == 1)
	{
		while(*(p_str + len_substr) != '\0')
		{
			*(p_str) = *(p_str + len_substr);
			p_str++;
		}
		*(p_str) = '\0';
	}

	return find_result;
}

void test(char *str)
{
	return 1;
}