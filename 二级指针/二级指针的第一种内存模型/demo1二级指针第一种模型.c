#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main01()
{ 
	//����ָ��ĵ�һ���ڴ�ģ��
	char *arraystr[] = { "aaa", "xxx", "ddd", "yyy", "ooo" };
	int i,j;
	char *tmp;
	//��ӡ����ǰ
	printf("����ǰ��");
	for (i = 0; i < 5;i++)
	{
		printf("%s ", arraystr[i]);
	}
	//����

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
	//��ӡ�����
	printf("\n");
	printf("�����");
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
	const char *tmp = NULL;  //*��const��ߣ���ʾָ��ָ����ڴ�ռ䲻�ܸı䡣
	int i, j;               //*��const�ұߣ���ʾָ�������һ���������ǲ��ܱ��ı�ģ���C������const ���εı�����α����
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

//����ָ��ĵ�һ���ڴ�ģ��
void main()
{
	char *arraystr[] = { "aaa", "xxx", "ddd", "yyy", "ooo" };
	int num = sizeof(arraystr) / sizeof(char *);
	printf("����ǰ��\n");
	printArrayStr(arraystr, num);
	sortArrayStr(arraystr, num);
	printf("\n�����\n");
	printArrayStr(arraystr, num);
	system("pause");
}