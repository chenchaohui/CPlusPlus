#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//打印函数声明
void printArray(int *list,int index);

//找到一个枢纽位置的函数声明
int partition(int *list,int low,int high );

//排序辅助函数声明
void quickSortHelp(int *list,int low,int high);

//排序函数声明
void quickSort(int *list,int n);
