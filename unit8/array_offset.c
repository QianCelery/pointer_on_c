/*
* 定义了一个维数组，虽然以向量形式存储，但通过array_offset()函数以多维数组形式进行访问
* @Author: Celery
* @Date:   2021-10-16 21:43:09
* @Last Modified by:   Celery
* @Last Modified time: 2021-10-16 22:20:21
*/
#include "stdio.h"
#include "stdarg.h"

int array_offset(int arrayinfo[], ...);

int main(void)
{
	int m_array[] = {3, 4, 6, 1, 5, -3, 3};

	printf("result: %d\n", array_offset(m_array, 6, 3, 1));

	return 0;
}

/**
 * [计算所传入下标在伪数组中的偏移值]
 * @Author   celery
 * @DateTime 2021-10-16T21:59:24+0800
 * @param    arrayinfo                [维数组信息，[0]:数组维数，[1]，[2]第一维下限和上限，后续以此类推，最多10维]
 * @param    ...                	  [可变参数，按顺序传入对应维数下标]			
 * @return                            [传入下标在距起始地址偏移值]
 */
int array_offset(int arrayinfo[], ...)
{
	int dimension = arrayinfo[0];	//数组维数
	va_list var_arg;
	int subinfo[10] = {0};
	int i = 0;
	int loc = 0;	

	//判断所出入维数是否合法
	if((dimension < 1) || (dimension > 10))
	{
		return -1;
	}

	va_start(var_arg, arrayinfo[0]);

	//获取下标参数
	for(i = 0; i < dimension; i++)
	{
		subinfo[i] = va_arg(var_arg, int);
		//判断所传入下标是否合法
		if((subinfo[i] > arrayinfo[i * 2 + 2]) || (subinfo[i] < arrayinfo[i * 2 + 1]))
		{
			return -1;
		}
		loc = (loc * (arrayinfo[i * 2 + 2] - arrayinfo[i * 2 + 1] + 1)) + subinfo[i] - arrayinfo[i * 2 + 1];
	}



	return loc;
}