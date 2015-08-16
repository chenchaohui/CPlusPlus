#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main000()
{
	char **p = (char **)malloc(5 * sizeof(char *));   //让二级指针指向开辟的内存空间
	int i = 0,j=0;
	char buf[10];
	if (p==NULL)
	{
		printf("err %s:","p==NULL");
		return;
	}

	for (i = 0; i < 5;i++)
	{ 
		p[i] = (char *)malloc(10 * sizeof(char));    //让一级指针指向开辟的内存空间
		if (p[i]==NULL)
		{
			printf("err p[%d]==NULL:",i);
		}
		sprintf(p[i],"%d%d%d",i,i,i);                   //初始化
	}

	printf("排序前:");
	for (i = 0; i < 5;i++)
	{
		printf("%s ",p[i]);
	}

	for (i = 0; i < 5;i++)
	{
		for (j = i + 1; j < 5;j++)
		{
			if (strcmp(p[i],p[j])<0)
			{
				strcpy(buf,p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],buf);
			}
		}
	}

	printf("\n排序后:\n");
	for (i = 0; i < 5; i++)
	{
		printf("%s ", p[i]);
	}
	//千万记得释放内存空间，避免内存泄露
	for (i = 0; i < 5; i++)
	{
		if (p[i]!=NULL)
		{
			free(p[i]);
		}	
	}
	if (p != NULL)
	{
		free(p);
	}

	system("pause");

}



void printStrArray(char ** p, int num)
{
	if (p == NULL)
	{
		printf("sortStrArray err:%s", "p == NULL");
		return;
	}
	int i = 0;
	for (i = 0; i < num;i++)
    {
		printf("%s ",p[i]);
    }
}



void sortStrArray(char **p,int num)
{
	int i, j;
	char buf[10];
	if (p == NULL)
	{
		printf("sortStrArray err:%s","p == NULL");
		return;
	}
	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (strcmp(p[i], p[j]) < 0)
			{
				strcpy(buf, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], buf);
			}
		}
	}
}
void main()
{
	char **p = (char **)malloc(5 * sizeof(char *));   //让二级指针指向开辟的内存空间
	int i = 0, j = 0;
	if (p == NULL)
	{
		printf("err %s:", "p==NULL");
		return;
	}

	for (i = 0; i < 5; i++)
	{
		p[i] = (char *)malloc(10 * sizeof(char));    //让一级指针指向开辟的内存空间
		if (p[i] == NULL)
		{
			printf("err p[%d]==NULL:", i);
		}
		sprintf(p[i], "%d%d%d", i, i, i);                   //初始化
	}

	printf("排序前:");
	printStrArray(p, 5);
	sortStrArray(p,5);
	printf("\n排序后:");
	printStrArray(p, 5);

	//千万记得释放内存空间，避免内存泄露
	for (i = 0; i < 5; i++)
	{
		if (p[i] != NULL)
		{
			free(p[i]);
		}
	}
	if (p != NULL)
	{
		free(p);
	}

	printf("\n");
	system("pause");

}