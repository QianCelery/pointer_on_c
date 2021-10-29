/*
* @Author: Celery
* @Date:   2021-10-16 22:24:23
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-17 16:18:26
*/
#include "stdio.h"

int chessboard[8][8] = {0};

int check_postion(int line, int list);
void queens(int line);
void print(void);
int counts = 0;

int main(void)
{
	
	
	queens(0);
	printf("coutn: %d\n", counts);

	return 0;
}

//8皇后问题
void queens(int line)
{
	int list = 0;

	for(list = 0; list < 8; list++)
	{
		if(check_postion(line, list))
		{
			//printf("line:%d\n", line);
			//print();	
			chessboard[line][list] = 1;
			if(line == 7)
			{
				counts++;
				print();
				chessboard[line][list] = 0;
				return;
			}
			queens(line + 1);

			chessboard[line][list] = 0;
		}
	}

}

int check_postion(int line, int list)
{
	int i = 0;

	for(i = 0; i < 8; i++)
	{
		if((chessboard[i][list] == 1) && (i != line))
		{
			return 0;
		}
		if((chessboard[line][i] == 1) && (i != list))
		{
			return 0;
		}
		if(i != 0)
		{
			if(((line - i) >= 0) && ((list - i) >= 0))
			{
				if(chessboard[line - i][list - i] == 1)
				{
					return 0;
				}
			}
			if(((line - i) >= 0) && ((list + i) < 8))
			{
				if(chessboard[line - i][list + i] == 1)
				{
					return 0;
				}
			}
			if(((line + i) < 8) && ((list - i) >= 0))
			{
				if(chessboard[line + i][list - i] == 1)
				{
					return 0;
				}
			}
			if(((line + i) < 8) && ((list + i) < 8))
			{
				if(chessboard[line + i][list + i] == 1)
				{
					return 0;
				}
			}
		}
		
	}
	return 1;
}

void print(void)
{
	int i = 0, j = 0;

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			printf("%d", chessboard[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}