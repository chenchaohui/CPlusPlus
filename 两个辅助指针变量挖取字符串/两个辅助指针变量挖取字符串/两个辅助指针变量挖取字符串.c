#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��������ָ�������ȡ�ַ���������Ҫ�õ��ַ�������strstr,strchr ,memcpy 
//����
/*
   ��һ���ܳ����ַ����У��ԡ�����Ϊ�磬��ȡ�������ַ����������õ����ַ������뵽һ����ά������

*/
//������
/*
   ��һ������Ĵ����������ַ���Ϊ����ͨ����ͼ�õ����ⷽ��

*/
//��������
void main01()
{
	//�����ַ������Ĭ����һ���ַ�������\0;
	char *str1 = { "aaa,bbbb,ccccc,dddddd," };
	char strArray[10][20] = { 0 };
	char *str0 = str1;
	int count = 0;
	int len = 0;
	do 
	{
		str0 = strchr(str0, ',');
		if (str0 != NULL)
		{
			//ָ��str0����ǰ�棬ָ��str1���ں���
			len = str0 - str1; 
			memcpy(strArray[count], str1, len);
		    str1 = str0;
			str1++;
			str0++;
			count++;
		}
		else
		{
			break;
		}
	
	} while (*str0!='\0');
	

	for (int i = 0; i < count;i++)
	{
		printf("%s ",strArray[i]);
	}

	system("pause");
}

//��ҵ����
//����һ���ӿ�
//ͨ�������õ�һ�������ĺ������
int getstr( char *p,char c,char strArray[10][20],int *mycount)
{
    char *pbak0 = p;
	char *pbak1 = pbak0;
	int len=0;
	int count = 0;
	if (p==NULL||mycount==NULL)
	{
		return -1;
	}
	do 
	{
		pbak0 = strchr(pbak0, c);
		if (pbak0 != NULL)
		{
			//ָ��str0����ǰ�棬ָ��str1���ں���
			len = pbak0 - pbak1;
			memcpy(strArray[count], pbak1, len);
			pbak1 = pbak0;
			pbak1++;
			pbak0++;
			count++;
		}
		else
		{
			break;
		}

	} while (*pbak0!='\0');
	*mycount = count;
	return 0;
}

void print(char a[10][20],int num)
{ 
	int i ;
	for (i = 0; i < num;i++)
	{ 
		printf("%s ",a[i]);
	}

}

void main()
{
	int ret = 0;
	int count = 0;
	char *str1 = { "aaa,bbbb,ccccc,dddddd," };
	char strArray[10][20] = { 0 };
	ret=getstr(str1,',',strArray,&count);
	if (ret==-1)
	{
		printf("�ָ�ʧ��\n");
		return;
	}
	print(strArray,count);

	system("pause");
}