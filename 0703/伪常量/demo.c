#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	const int a = 2; //��C������const ��ǵı�����һ��α����
	                 //��C++������const��ǵı�����һ������

	int *p = (int *)(&a);
	*p = 0;
	printf("%d\n",a);   //���г�����Կ�������a��ֵ��2���ĳ���0������˵��C������const ��ǵı�����һ��α����
	system("pause");
}