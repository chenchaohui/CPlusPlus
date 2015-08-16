#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//二级指针的第二种内存模型
void main21()
{
	char strArray[5][10] = { "aaa", "ccc", "bbb", "fff", "ggg" };
	int i, j;
	char buf[10];       //这个地方需要特别注意
	printf("排序前：");
		for (i = 0; i < 5;i++)
		{
			printf("%s ",strArray[i]);
		}
		
		//排序：
		for (i = 0; i < 5;i++)
		{
			for (j = i + 1; j < 5;j++)
			{
				if (strcmp(strArray[i], strArray[j]) < 0)
				{
					strcpy(buf, strArray[i]);
					strcpy(strArray[i], strArray[j]);
					strcpy(strArray[j], buf);
				}
			}
		}
			//排序后；
			for (i = 0; i < 5; i++)
			{
				printf("%s ", strArray[i]);
			}

		system("pause");
}

//出错的本质的原因是：形参和实参的数据类型不一致
void printStrArray1(char **str, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("%s ", str[i]);
	}

}



//正确的做法
void printStrArray2( char str[5][10], int num)
{
	int i;
	for (i = 0; i < num;i++)
	{
		printf("%s ",str[i]);
	}

}


//void sortStrArray11222(char str[5][10], int num)
//{
//	int i, j;
//	char buf[30];
//
//	for (i = 0; i < num; i++)
//	{
//		for (j = i + 1; j < num; j++)
//		{
//			if (strcmp(str[i], str[j]) > 0) //注意这里的不能不能出现笔误
//			{
//				strcpy(buf, str[i]);
//				strcpy(str[i], str[j]);
//				strcpy(str[j], buf);
//			}
//		}
//	}
//
//}

void sortArr23(char myArray[5][10], int iNum)
{
	int i = 0, j = 0;
	char buf[30]; //buf数组名代表数组首元素的地址
	//排序
	for (i = 0; i < iNum; i++)
	{
		for (j = i + 1; j < iNum; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				strcpy(buf, myArray[i]);
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], buf);
			}
		}
	}
}


void main()
{
	char strArray[5][10] = { "aaa", "ccc", "bbb", "fff", "ggg" };
	printf("排序前:");
	//printStrArray1(strArray,5);
	printStrArray2(strArray, 5);
	printf("\n排序后:");
	sortArr23(strArray, 5);
	//printStrArray1(strArray, 5);
	printStrArray2(strArray, 5);
	system("pause");
}