#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��ѡ������Ϊ����������ѧϰ
//void printArray(int *p)               //�����������bug����Ϊ���Ŵ��ݵĲ����Ĳ�ͬ������ĳ���Ҳ���ܲ�ͬ��Ҳ���ǳ����е�10Ӧ������һ���������ı�������
//{
//	for (int i = 0; i < 10;i++)
//	{
//		printf("%d ",p[i]);
//	}
//
//}

//void printArray(int *p,int len)         //һ��ѡ�������ַ���      
//{
//	for (int i = 0; i < len;i++)
//	{
//		printf("%d ",p[i]);
//	}
//
//}

//�������������β��ǻ��˻�Ϊָ�룬��������β��г���int a[10], char str[100],C/C++�������Ὣ���˻�Ϊָ�룬Ҳ����Ϊ�������ڴ�ռ䡣
void printArray(int a[10])         //���ַ�������ȡ
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
	printf("����ǰ��\n");

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

	printf("\n�����\n");
	/*for (i = 0; i < 10;i++)
	{
	printf("%d ", a[i]);
	}*/

	//printArray(a);
	//printArray(a, sizeof(a)/sizeof(int));
	printArray(a);
	system("pause");
}