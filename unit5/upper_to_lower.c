/*
* @Author: Celery
* @Date:   2021-10-13 19:52:41
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-13 20:37:18
*/
#include "stdio.h"
#include "ctype.h"
#include "string.h"

int main(void)
{
	char strings[100] = {0};
	int ch;
	int i = 0;
	char tmp;

	while((ch = getchar()) != EOF)
	{
		if(isupper(ch))
			tmp = tolower(ch);
		else
			tmp = ch;
		strings[i] = tmp;
		i++;
	}

	strings[i] = '\0';
	printf("%s\n", strings);

	return 1;
}