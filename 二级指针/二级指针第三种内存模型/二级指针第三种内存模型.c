#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main000()
{
	char **p = (char **)malloc(5 * sizeof(char *));   //�ö���ָ��ָ�򿪱ٵ��ڴ�ռ�
	int i = 0,j=0;
	char buf[10];
	if (p==NULL)
	{
		printf("err %s:","p==NULL");
		return;
	}

	for (i = 0; i < 5;i++)
	{ 
		p[i] = (char *)malloc(10 * sizeof(char));    //��һ��ָ��ָ�򿪱ٵ��ڴ�ռ�
		if (p[i]==NULL)
		{
			printf("err p[%d]==NULL:",i);
		}
		sprintf(p[i],"%d%d%d",i,i,i);                   //��ʼ��
	}

	printf("����ǰ:");
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

	printf("\n�����:\n");
	for (i = 0; i < 5; i++)
	{
		printf("%s ", p[i]);
	}
	//ǧ��ǵ��ͷ��ڴ�ռ䣬�����ڴ�й¶
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
	char **p = (char **)malloc(5 * sizeof(char *));   //�ö���ָ��ָ�򿪱ٵ��ڴ�ռ�
	int i = 0, j = 0;
	if (p == NULL)
	{
		printf("err %s:", "p==NULL");
		return;
	}

	for (i = 0; i < 5; i++)
	{
		p[i] = (char *)malloc(10 * sizeof(char));    //��һ��ָ��ָ�򿪱ٵ��ڴ�ռ�
		if (p[i] == NULL)
		{
			printf("err p[%d]==NULL:", i);
		}
		sprintf(p[i], "%d%d%d", i, i, i);                   //��ʼ��
	}

	printf("����ǰ:");
	printStrArray(p, 5);
	sortStrArray(p,5);
	printf("\n�����:");
	printStrArray(p, 5);

	//ǧ��ǵ��ͷ��ڴ�ռ䣬�����ڴ�й¶
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