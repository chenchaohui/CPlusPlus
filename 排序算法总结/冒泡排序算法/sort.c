#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
/*===================================*/
/*程序名称：sort-1.c                 */
/*程序目的：冒泡排序                 */
/* WRITTEN  BY  CHEN                 */
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

void bubbleSort(int *list,int index)
{
   int i,j,k;
   int tmp;                                    // 数据交换时的中间变量
   for (j = index;j > 0;j--)                   // 控制外层循环
    {
	   for (i = 0;i<j-1;i++)                   //控制内层循环
	    {
		   if (list[i] > list[i+1])
		    {
				//数据交换
			     tmp=list[i];
			     list[i]=list[i+1];
				 list[i+1]=tmp;
				 printf("\n current sorting result:\n");

				  for (k = 0;k<index;k++)      //一旦发生交换就输出数组的当前状态
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
