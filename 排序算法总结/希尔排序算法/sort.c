#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
/*===================================*/
/*程序名称：sort-6.c                 */
/*程序目的：希尔排序                 */
/* WRITTEN  BY  CHEN                 */
/*===================================*/

//打印数组中的元素
void printArray(int *list,int index)
{
    int i = 0;
	for (i = 0;i<index;i++)
	{
		//打印数据
		printf("%d ",list[i]);
	}
}

//希尔排序代码
void shellSort(int *list,int index)
{
  int i,j,k;                  //用于控制循环的变量
  int tmp;                    //用于数据交换的中间变量
  int group;                  //集合中元素的分割间距

  for ( group = index/2; group > 0; group /= 2 )
  {
	  for (i = group;i < index; i++)
	  {
		  for (j = i-group;j > 0;j-=group)
		  {
			  if (list[j] > list[j+group])
			  {

				  tmp = list[j];
				  list[j] = list[j+group];
				  list[j+group]=tmp;
			  }

		  }      
	  }
	  printf("\n current sorting result:");
	  for (k = 0;k < index; k++)
	  {
		  printf("%d ",list[k]);
	  }
  }

}

//void shellSort(int *list,int index)
//{ 	
//	{
//		int group;         // 分割集合的间隔长度
//
//		int i, j, tmp;   //i,j,k 用于控制循环的变量，temp 用于数据交换的暂存变量
//		int k = 0;
//		for (group = index / 2; group > 0; group /= 2)
//		{
//			for (i = group; i < index; i++)
//			{
//				for (j = i - group; j >= 0; j -= group)
//				{
//					if (list[j] > list[j + group])
//					{
//						tmp = list[j];
//						list[j] = list[j + group];
//						list[j + group] = tmp;
//					}				
//				}				
//			}
//			printf("\n current sorting result:");
//			for ( k =0; k < index; k++)
//			{
//				printf("%d ",list[k]);
//			}
//		}
//	}
//
//} 

#ifdef cplusplus
}
#endif
