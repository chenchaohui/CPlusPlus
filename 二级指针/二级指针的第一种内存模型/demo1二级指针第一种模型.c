#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main01()
{ 
	//二级指针的第一种内存模型
	char *arraystr[] = { "aaa", "xxx", "ddd", "yyy", "ooo" };
	int i,j;
	char *tmp;
	//打印排序前
	printf("排序前：");
	for (i = 0; i < 5;i++)
	{
		printf("%s ", arraystr[i]);
	}
	//排序

	for (i = 0; i < 5;i++)
	{
		for (j = i + 1; j < 5;j++)
		{
			if ((strcmp(arraystr[i], arraystr[j]))<0)
			{
				tmp = arraystr[i];
				arraystr[i] = arraystr[j];
				arraystr[j] = tmp;
			}
		}
	}
	//打印排序后
	printf("\n");
	printf("排序后：");
	for (i = 0; i < 5; i++)
	{
		printf("%s ", arraystr[i]);
	}



	printf("%d\n ", sizeof(arraystr) / sizeof(char *));
	system("pause");
}




void  printArrayStr(const char **str, const int num)
{
	
	if (str==NULL)
	{
		printf("printArrayStr022 err: %s","str==NULL");
	}
	for (int i = 0; i < num;i++)
	{
		printf("%s ",str[i]);
	}

}


void sortArrayStr(const char **str, const int num)
{
	const char *tmp = NULL;  //*在const左边，表示指针指向的内存空间不能改变。
	int i, j;               //*在const右边，表示指针变量是一个常量，是不能被改变的，在C语言中const 修饰的变量是伪常量
	if (str == NULL)
	{
		printf("sortArrayStr023 err: %s", "str==NULL");
	}
	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if ((strcmp(str[i], str[j])) < 0)
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}


}

//二级指针的第一种内存模型
void main()
{
	char *arraystr[] = { "aaa", "xxx", "ddd", "yyy", "ooo" };
	int num = sizeof(arraystr) / sizeof(char *);
	printf("排序前：\n");
	printArrayStr(arraystr, num);
	sortArrayStr(arraystr, num);
	printf("\n排序后：\n");
	printArrayStr(arraystr, num);
	system("pause");
}