#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//以选择排序为例进行深入学习
//void printArray(int *p)               //这个方法存在bug，因为随着传递的参数的不同，数组的长度也可能不同，也就是程序中的10应该是用一个传进来的变量代替
//{
//	for (int i = 0; i < 10;i++)
//	{
//		printf("%d ",p[i]);
//	}
//
//}

//void printArray(int *p,int len)         //一般选择用这种方法      
//{
//	for (int i = 0; i < len;i++)
//	{
//		printf("%d ",p[i]);
//	}
//
//}

//数组名当函数形参是会退化为指针，如果函数形参中出现int a[10], char str[100],C/C++编译器会将其退化为指针，也不会为其多分配内存空间。
void printArray(int a[10])         //这种方法不可取
{
	for (int i = 0; i < 10;i++)
	{
		printf("%d ",a[i]);
	}
}

void main11()
{
	int i, j,tmp;
	int a[10] = { 1, 3, 44, 2, 3, 44, 4, 4, 6, 67 };
	printf("排序前：\n");

	/*for (i = 0; i < 10;i++)
	{
		printf("%d ",a[i]);
	}*/

	//printArray(a);
	//printArray(a, sizeof(a)/sizeof(int));
	printArray(a);
	for (i = 0; i < 9;i++)
	 {
		 for (j = i + 1; j < 10;j++)
		 {
			 if (a[i]>a[j])
			 { 
				 tmp = a[i];
				 a[i] = a[j];
				 a[j] = tmp;
			 }
		 }
	 }

	printf("\n排序后：\n");
	/*for (i = 0; i < 10;i++)
	{
	printf("%d ", a[i]);
	}*/

	//printArray(a);
	//printArray(a, sizeof(a)/sizeof(int));
	printArray(a);
	system("pause");
}