#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��ӡ��������
void printArray(int *list,int index);

//�ҵ�һ����Ŧλ�õĺ�������
int partition(int *list,int low,int high );

//��������������
void quickSortHelp(int *list,int low,int high);

//����������
void quickSort(int *list,int n);
