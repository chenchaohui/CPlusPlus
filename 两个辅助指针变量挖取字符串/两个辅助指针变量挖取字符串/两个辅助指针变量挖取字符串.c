#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//两个辅助指针变量挖取字符串，可能要用到字符串函数strstr,strchr ,memcpy 
//需求：
/*
   在一个很长的字符串中，以‘，’为界，挖取各个子字符串，并将得到的字符串放入到一个二维数组中

*/
//分析：
/*
   以一个具体的带’，‘的字符串为例，通过画图得到解题方法

*/
//初级代码
void main01()
{
	//常量字符串最后默认有一个字符结束符\0;
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
			//指针str0走在前面，指针str1走在后面
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

//就业代码
//定义一个接口
//通过分析得到一个这样的函数借口
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
			//指针str0走在前面，指针str1走在后面
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
		printf("分割失败\n");
		return;
	}
	print(strArray,count);

	system("pause");
}