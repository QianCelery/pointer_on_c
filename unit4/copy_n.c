#include <stdio.h>

void copy_n(char dst[], char src[], int n);

int main(void)
{
	char dst[] = "abcdefgh";
	char src[] = "qwertqwer";
	//printf("%s\n", src);
	//printf("%s\n", *(&src));
	//printf("%d\n", sizeof(&src));
	copy_n(dst, src, 7);
	printf("%s\n", dst);
	return 1;
}

void copy_n(char dst[], char src[], int n)
{
	int i = 0;

	// printf("%d\n", src);
	// printf("%d\n", &src);

	// printf("%d\n", *src);	
	// printf("%s\n", *(&src));
	printf("%d\n", sizeof(&src));

	//此处需要使用&src,而非src，因为数组传递过来会退化成一个指针，使用sizeof得到的是指针类型字节数
	if(sizeof(&src) >= n)				
	{
		for(i = 0; i < n; i++)
		{
			dst[i] = src[i];
		}
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			if(i <= sizeof(&src))
				dst[i] = src[i];
			else
				dst[i] = '\0';
		}

	}
}