#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��ӡ��������
void printArray(int *list,int index);

//�鲢�㷨(�����ź�˳������н��кϲ�)
void merge(int *sourceArr,int *tmpArr,int startIndex,int midIndex,int endIndex);


//�鲢����
void mergeSort(int *sourceArr,int *tmpArr,int startIndex,int endIndex);
 