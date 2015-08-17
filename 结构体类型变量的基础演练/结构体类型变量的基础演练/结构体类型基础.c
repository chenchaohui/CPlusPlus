#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student
{
	char name[20];
	int age;
};

void init(struct student *structArr,int num)
{
	int i = 0;
	for (i = 0; i < num;i++)
	{
		printf("ÇëÊäÈëÄêÁä:");
		scanf("%d",&(structArr[i].age));
	}
}

void sortArray(struct student *structArr,int num)    //Ñ¡ÔñÅÅÐòËã·¨
{
	int i = 0, j = 0;
	struct student tmp;
	for (i = 0; i < num;i++)
	{
		for (j = i + 1; j < num;j++)
		{
			if (structArr[i].age<structArr[j].age)
			{
				tmp = structArr[i];
				structArr[i] = structArr[j];
				structArr[j] = tmp;
			}
		}
	}

}

void printArr(struct student *structArr,int num)
{
	int i = 0;
	for (i = 0; i < num;i++)
	{
		printf("%d\n",structArr[i].age);
	}

}
void main()
{

	struct student a[5];
	init(a, 5);
	printf("ÅÅÐòÇ°£º");
	printArr(a,5);
	sortArray(a, 5);
	printf("ÅÅÐòºó£º");
	printArr(a, 5);
	system("pause");
}