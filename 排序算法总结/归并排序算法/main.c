#define _CRT_SECURE_NO_WARNINGS    //ȥ����ȫ����
#include"sort.h"

//��������
void main()
{

	int sourceArr[20];           //�洢���������
	int tmpArr[20];    //ȡbtree[1]--->btree[2047]��ֵ  ע����ȡbtree[2048]���Խ��
	int index;              //������������ݵĳ���
	int node;               //��ʱ�洢���������
	int i=0;
	//list[0] = 0;
	printf("\n please input the values you want to sort[exit for 0]\n");
	index = 0;
	scanf("%d",&node);        //��node��ֵ

	while (node != 0)
	{
		sourceArr[index] = node;    //ͨ��node�����ݸ�ֵ
		index++;
		scanf("%d",&node);
	}
	index--;

	printf("����ǰ:\n");
	printArray(sourceArr,index);  //��ӡ����ǰ��״̬
	mergeSort(sourceArr, tmpArr, 0, index);
	printf("\n�����:");
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
//		//if(sourceArr[i]>sourceArr[j])                                           //��С���������㷨
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
////�ڲ�ʹ�õݹ�
//void MergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex)
//{
//	int midIndex;
//	if(startIndex<endIndex)                                                          //������ȵݹ�����
//	{
//		midIndex=(startIndex+endIndex)/2;
//		MergeSort(sourceArr,tempArr,startIndex,midIndex);
//		MergeSort(sourceArr,tempArr,midIndex+1,endIndex);
//		Merge(sourceArr,tempArr,startIndex,midIndex,endIndex);
//	}
//}
//
