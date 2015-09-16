#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
	/*===================================*/
	/*程序名称：sort-2.c                 */
	/*程序目的：快速排序                 */
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


	int partition(int *list,int low,int high )
	{
		int tmp;
		while (low < high)
		{                                               //以第一个元素的位置为枢纽从右向左扫描，找到第一个比枢纽位置上的元素小的元素
			while (low < high && list[high] > list[low])
			{
				high--;
			}
		    tmp = list[high];                        //找到后交换高低位置上的元素，并以高位置为枢纽位置
			list[high] = list[low];
			list[low] = tmp;

			while (low < high && list[low] < list[high]) //然后从左向右扫描，找到第一个比高位置上的元素大的元素
			{
				low++;
			}
			tmp = list[high];                            //交换高低位置上的元素，并以低位置为枢纽位置继续循环
			list[high] = list[low];
			list[low] = tmp;
		}
		return low;                                      //找到一个枢纽位置，使得枢纽位置左边的元素不会比该位置上的元素大，右边的元素不会它小
	}
	
	void quickSortHelp(int *list,int low, int high)
	{
		if (low < high)                                  //不定深度递归
		{
			int pivotLoc=partition(list,low,high);       //找到第一个最终的枢纽位置
			quickSortHelp(list,low,pivotLoc-1);
			quickSortHelp(list,pivotLoc+1,high);
		}
	}
	//封装quickSortHelp
	void quickSort(int *list,int n)
	{
	   quickSortHelp(list,0,n-1);
	}

#ifdef cplusplus
}
#endif
