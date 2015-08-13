#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void main21()
{
	int  a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("a=%p,&a=%p",a,&a);          //a和&a的值一样
	printf("a+1=%p,&a+1=%p",a+1,&a+1);   //a+1和&a+1值不一样，本质原因是a和&a数据类型不一样，步长不一样
	system("pause");
}


void main()
{
	int(*pp)[10];         //指针数组
	int t[10][10];
	int *(ppp[10]) = t;   //数组指针
	int a = 10;
	int *p = &a;
	printf("&a=%d",&a);
	//*((int *)001AFBA0) = 10;
	//printf("%d",a);
	//*((int *)1964580) = 20;
	printf("%d",a);
	system("pause");
}