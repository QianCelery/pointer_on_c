#include <stdio.h>

int main(int argc, char const *argv[])
{
	int const a = 25;
	enum LIQUID{
		OUNCE = 1,
		CUP = 8,
		PINT =16,
		QUART = 32,
		GALLON = 128
	};

	enum LIQUID	jar;
	jar = QUART;
	printf("%d\n", jar);
	jar = jar + 1;
	printf("%d\n", jar);


	return 0;
}