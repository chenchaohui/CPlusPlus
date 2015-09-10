/*=================Program Description==================*/
/*程序名称： Sort_01.c                                  */
/*程序目的： 使用冒泡排序算法设计一个排序程序           */
/* Written By Chen Chao Hui.                            */
/*======================================================*/

/*备注：冒泡排序是一种稳定的排序算法，其时间复杂度为O(n^2),空间复杂度为:*/

#include "sort.h"
#ifdef cplusplus
extern "c"{
#endif
void bubbleSort(int *list, int index)
{
	int i = 0, j = 0;
	int k = 0;
	int tmp;
	for (j = index; j > 0; j--)
	{
		for (i = 0; i < j - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
				printf("\n Current sorting result:");
				for (k = 0; k < index; k++)
				{
					printf("%d ", list[k]);
				}
			}
		}
	}
}

void printArray(int *list, int index)
{
	int i = 0;
	for (i = 0; i < index; i++)
	{
		printf("%d ", list[i]);
	}
}
#ifdef cplusplus
{
#endif