#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LENGTH 128

int main()
{
	FILE *fp;

	char  str[LINE_LENGTH - 1];
	char  cur_str[LINE_LENGTH - 1];
	char  last_str[LINE_LENGTH - 1];

	if((fp = fopen("c:\\source\\pointer_on_c\\unit4\\text.txt", "rt")) == NULL)
	{
		printf("Fail to open file\n");
		exit(0);
	}

	while(fgets(str, LINE_LENGTH, fp) != NULL)
	{
		if(strcmp(str, last_str) == 0)
			continue;
		strcpy(last_str , cur_str);
		strcpy(cur_str, str);
		if(strcmp(last_str, cur_str) == 0)
			printf("%s\n", str);
	}

	fclose(fp);

	return 1;

}