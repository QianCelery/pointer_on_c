/*
* @Author: Celery
* @Date:   2021-10-14 14:50:48
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-14 15:14:49
*/
#include "stdio.h"

char *find_char(char const *source, char const *chars);
int main(void)
{
	char source[] = "ABCDEFG";
	char chars[] = "qqq";

	char *p;
	p = find_char(source, chars);
	printf("result:%s\n", p);

	return 0;
}


char *find_char(char const *source, char const *chars)
{
	char const *p_source = source;
	char const *p_chars = chars;


	while((*p_chars) != '\0')
	{
		if(p_chars == NULL)
		{
			return (char *)p_chars;
		}
		while((*p_source) != '\0')
		{
			if(p_source == NULL)
			{
				return (char *)p_source;
			}
			if((*p_chars) == (*p_source))
			{
				return (char *)p_source;
			}
			p_source++;
		}
		p_source = source;
		p_chars++;
	}

	return NULL;
}