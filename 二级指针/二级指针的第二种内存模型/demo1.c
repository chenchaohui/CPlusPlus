#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//����ָ��ĵڶ����ڴ�ģ��
void main21()
{
	char strArray[5][10] = { "aaa", "ccc", "bbb", "fff", "ggg" };
	int i, j;
	char buf[10];       //����ط���Ҫ�ر�ע��
	printf("����ǰ��");
		for (i = 0; i < 5;i++)
		{
			printf("%s ",strArray[i]);
		}
		
		//����
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
			//�����
			for (i = 0; i < 5; i++)
			{
				printf("%s ", strArray[i]);
			}

		system("pause");
}

//����ı��ʵ�ԭ���ǣ��βκ�ʵ�ε��������Ͳ�һ��
void printStrArray1(char **str, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("%s ", str[i]);
	}

}



//��ȷ������
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
//			if (strcmp(str[i], str[j]) > 0) //ע������Ĳ��ܲ��ܳ��ֱ���
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
	char buf[30]; //buf����������������Ԫ�صĵ�ַ
	//����
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
	printf("����ǰ:");
	//printStrArray1(strArray,5);
	printStrArray2(strArray, 5);
	printf("\n�����:");
	sortArr23(strArray, 5);
	//printStrArray1(strArray, 5);
	printStrArray2(strArray, 5);
	system("pause");
}