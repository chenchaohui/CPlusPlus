#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
	/*===================================*/
	/*程序名称：sort-3.c                 */
	/*程序目的：选择排序                 */
	/*WRITTEN  BY  CHEN                  */
	/*===================================*/
	void printArray(int *list,int index)
	{
		int i = 0;
		for (i = 0;i<index;i++)
		{
			//打印数据
			printf("%d ",list[i]);
		}
	}

	void selectSort(int *list,int index)
	{
		int i ,j, k;      // 用于控制循环的三个变量
		int minnode;      // 存储最小数值
		int indexMin;     //存储最小数值的索引
		int tmp;          //数值交换时的暂存变量

		//核心算法一      //要通过画图得到算法核心
		/*for (i = 0;i < index - 1; i++)
		{
			for (j = i+1;j < index; j++)
			{
				if (list[i]>list[j])
				{
					tmp=list[i];
					list[i]=list[j];
					list[j]=tmp;
					printf("\n current sorting result:");
					for (k = 0; k < index; k++)
					{
						printf("%d ",list[k]);
					}
				}
				
			}
		}*/

		//核心算法二
		for (i = 0;i < index - 1; i++)
		{
			minnode=32767;
		    indexMin = 0;
			for (j = i;j < index; j++)
			{
				if (list[j]<minnode)
				{
					minnode=list[j];              //将最小值存储到变量minnode中
					indexMin=j;

					tmp=list[i];                   /*交换两个值*/
					list[i]=list[indexMin];
					list[indexMin]=tmp;

					printf("\n current sorting result:");
					for (k = 0; k < index; k++)
					{
						printf("%d ",list[k]);
					}
				}
				
			}
		}

	}

#ifdef cplusplus
}
#endif
