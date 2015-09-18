#define _CRT_SECURE_NO_WARNINGS    //去除安全警告
#include"sort.h"

//测试用例
void main()
{

	int sourceArr[20];           //存储输入的数据
	int tmpArr[20];    //取btree[1]--->btree[2047]的值  注意若取btree[2048]则会越界
	int index;              //保存输入的数据的长度
	int node;               //临时存储输入的数据
	int i=0;
	//list[0] = 0;
	printf("\n please input the values you want to sort[exit for 0]\n");
	index = 0;
	scanf("%d",&node);        //给node赋值

	while (node != 0)
	{
		sourceArr[index] = node;    //通过node给数据赋值
		index++;
		scanf("%d",&node);
	}
	index--;

	printf("排序前:\n");
	printArray(sourceArr,index);  //打印排序前的状态
	mergeSort(sourceArr, tmpArr, 0, index);
	printf("\n排序后:");
	printArray(sourceArr,index);
	system("pause");
}




//#include<stdlib.h>
//#include<stdio.h>

//void Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex,int endIndex)
//{
//	int i = startIndex,j=midIndex+1,k = startIndex;
//	while(i != midIndex + 1 && j!=endIndex + 1)
//	{
//		//if(sourceArr[i]>sourceArr[j])                                           //从小到大排序算法
//		if(sourceArr[i]<sourceArr[j])
//			tempArr[k++] = sourceArr[i++];
//		else
//			tempArr[k++] = sourceArr[j++];
//	}
//	while(i!=midIndex+1)
//		tempArr[k++] = sourceArr[i++];
//	while(j!=endIndex+1)
//		tempArr[k++] = sourceArr[j++];
//	for(i=startIndex;i<=endIndex;i++)
//		sourceArr[i] = tempArr[i];
//}
//
////内部使用递归
//void MergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex)
//{
//	int midIndex;
//	if(startIndex<endIndex)                                                          //不定深度递归排序
//	{
//		midIndex=(startIndex+endIndex)/2;
//		MergeSort(sourceArr,tempArr,startIndex,midIndex);
//		MergeSort(sourceArr,tempArr,midIndex+1,endIndex);
//		Merge(sourceArr,tempArr,startIndex,midIndex,endIndex);
//	}
//}
//
