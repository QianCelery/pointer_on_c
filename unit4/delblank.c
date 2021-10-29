#include <stdio.h>
#include <string.h>

void delblank(char *string);

int main(void)
{
	char string[] = "command     failed :   cann'    t";
	printf("%s\n", string);
	delblank(string);

	printf("%s\n", string);
	return 0;
}

void delblank(char *string)
{
	int i = 0, j = 0;
	char *new_string;
	new_string = string;
	printf("%s\n", string);
	for(i = 0; i < strlen(string); i++)
	{
		if(string[i] == '\0')
			break;
		if((string[i] == ' ') && (string[i + 1] == ' '))
		{
			continue;
		}
		new_string[j++] = string[i];
	}
	new_string[j] = '\0';
	string = new_string;
	return;

}