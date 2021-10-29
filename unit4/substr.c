#include <stdio.h>
#include <string.h>

//#define LENGTH 128
int substr(char dst[], char src[], int start, int len);
int main(void)
{
	char dst[] = "command failed: can't read";
	char src[] = "implement design";

	substr(dst, src, 3, 7);

	printf("%s\n", dst);


	return 0;
}

int substr(char dst[], char src[], int start, int len)
{
	int i = 0;

	if((start > strlen(src)) || (len < 0))
	{
		strset(dst, '\0');
		return 0;
	}

	for(i = 0; i < len; i++)
	{
		if(i == strlen(dst))
		{
			dst[i] = '\0';
			return i;
		}
		dst[i] = src[start + i];
	}

	dst[i] = '\0';

	return i;
}