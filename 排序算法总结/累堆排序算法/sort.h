#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//打印函数声明
void printArray(int *list,int index);

//建立累堆
void createHeap(int *heap,int root,int index);

//选择排序算法的声明
void heapSort(int *list,int index);