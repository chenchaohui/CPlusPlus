#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif

	/*===================================*/
	/*程序名称：sort-8.c                 */
	/*程序目的：归并排序                 */
	/* WRITTEN  BY  CHEN                 */
	/*===================================*/

	void printArray(int *sourceArr,int index)
	{
		int i = 0;
		for (i = 0;i <= index;i++)
		{
			//打印数据
			printf("%d ",sourceArr[i]);
		}
		printf("\n");
	}

	//归并算法(对以排好顺序的数列进行合并)即：将一个数组划分为前后两个部分，两个部分的元素逐一比较，小的元素存入数组tmpArr中，如此比较下去，知道一个部分的元素全部放入数组tmpArr中，最后再将另一组中剩余的元素全部放入数组tmpArr中
	void merge(int *sourceArr,int *tmpArr,int startIndex,int midIndex,int endIndex)
	{
		//环境准备
		int i,j,k;
		i =  startIndex;
		j = midIndex+1;
		k = startIndex;
		while (i != midIndex + 1 &&j != endIndex + 1)
		{
			if ( sourceArr[i] < sourceArr[j] )
			{
				tmpArr[k++] = sourceArr[i++];
			}

			else
			{
				tmpArr[k++] = sourceArr[j++];
			}
		}
		  //上面i和j总有一个先不满足条件，但是具体哪个不满足条件这是由输入的具体的数组的长度决定的
		while (i != midIndex + 1)
		{
			tmpArr[k++] = sourceArr[i++];
		}
		while (j != endIndex + 1)
		{
			tmpArr[k++] = sourceArr[j++];
		}
		for (i = startIndex;i <= endIndex;i++)
		{
			sourceArr[i] = tmpArr[i];
		}
	}


	//归并排序
	void mergeSort(int *sourceArr,int *tmpArr,int startIndex,int endIndex)
	{
		int i=0;
        int midIndex = (startIndex + endIndex)/2;
		if (startIndex < endIndex)
		{
			mergeSort(sourceArr,tmpArr,startIndex,midIndex);
			mergeSort(sourceArr,tmpArr,midIndex + 1,endIndex);
			merge(sourceArr,tmpArr,startIndex,midIndex,endIndex);			
		}		
	}

#ifdef cplusplus
}
#endif
