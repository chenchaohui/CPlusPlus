#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//打印函数声明
void printArray(int *list,int index);

//归并算法(对以排好顺序的数列进行合并)
void merge(int *sourceArr,int *tmpArr,int startIndex,int midIndex,int endIndex);


//归并排序
void mergeSort(int *sourceArr,int *tmpArr,int startIndex,int endIndex);
 