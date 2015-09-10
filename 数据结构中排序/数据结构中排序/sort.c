/*=================Program Description==================*/
/*�������ƣ� Sort_01.c                                  */
/*����Ŀ�ģ� ʹ��ð�������㷨���һ���������           */
/* Written By Chen Chao Hui.                            */
/*======================================================*/

/*��ע��ð��������һ���ȶ��������㷨����ʱ�临�Ӷ�ΪO(n^2),�ռ临�Ӷ�Ϊ:*/

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