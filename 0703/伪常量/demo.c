#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	const int a = 2; //在C语言中const 标记的变量是一个伪常量
	                 //在C++语言中const标记的变量是一个常量

	int *p = (int *)(&a);
	*p = 0;
	printf("%d\n",a);   //运行程序可以看到常量a的值从2被改成了0，所以说在C语言中const 标记的变量是一个伪常量
	system("pause");
}