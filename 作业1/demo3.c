#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findValueByKey(char src[][100],char *key,char *value1)
{
	char (*srcbak)[100]= src;   //在这个地方我们需要特别注意：  int *（p[10]）//有10个指针变量组成的数组，简称指针数组
	char *keybak = key;                                       //int(*p)[10] //数组数据类型指针
	char *value1bak = value1;
	
	int ret = 0;
	int i;
	char *mark;
	if (src == NULL || key == NULL || value1 == NULL)
	{
		ret = -1;
		printf("func findValueByKey err:%d src == NULL || key == NULL || value1 == NULL",ret);
		return ret;
	}

	for (i = 0;i < 5; i++)
	{
		if ((mark = strstr(*(src+i),key)) !=NULL)
		{
			mark = mark + strlen(keybak);
			while (*mark!='\0')
			{
				if (*mark == '=')
				{
					mark++;
					continue;
				}
				else if (*mark == ' ')
				{
					mark++;
					continue;
				}
				else
				{
					*value1++ = *mark++;
				}	    
			}
		}
		*value1 = '\0';
	}
	return 0;
}


void main()
{
	char str[5][100] = {
		                 "key1       =      valude1",
		                 "key2      = valude2",
				         "key3      =      valude3   ",
						 "key4 =      valude4",
						 "key5=     "
                      	};

	char mykey[10] = { 0 };
	char value1[20] = { 0 };
	int ret = 0;
	scanf("%s",mykey);
	ret = findValueByKey(str,mykey,value1);
	if (ret!=-1)
	{
		printf("%s\n",value1);
	}
	system("pause");
}














//#define _CRT_SECURE_NO_WARNINGS
//#include"stdio.h"
//#include"stdlib.h"
//#include"string.h"
///*
//键值对（”key = valude”）字符串，在开发中经常使用
//要求1：请自己定义一个接口，实现根据key获取valude；40分
//要求2：编写测试用例。30分
//要求3：键值对中间可能有n多空格，请去除空格30分
//注意：键值对字符串格式可能如下
//“key1 = valude1”
//“key2 =    valude2    "
//“key3       = valude3   "
//“key4   =   valude4”
//"key5=     "
//*/
//
///*
//思路
//第一步：定义一个字符串数组;把下列的数组保存进去
//第二步：定义需要获取valude的字符数组，以及在顶一个  key的字符数组;
//第三步：定义一个被调用的函数；
//*/
//char MyStr(char p[][100], char *key, char *valude)
//{
//	int ret = 1;
//	char *myp;
//	int i = 0;
//	if (p == NULL || key == NULL || valude == NULL)  //判断传来的地址 是否为空！
//	{
//		ret = -1;
//		printf("func MyStr() err %d  (p == NULL || key == NULL || valude == NULL)", ret);
//		return ret;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		if ((myp = strstr(*(p + i), key)) != NULL)  //判断key是否在这一行字符串中；如果不是NULL则满足条件。继续往下执行
//		{
//			myp = myp + strlen(key); //指针跳到找到的那个字符串后面！
//			while (*myp != '\0')
//			{
//				if (*myp == '=')
//				{
//					myp++;
//					continue;
//				}
//				else if (*myp == ' ')
//				{
//					myp++;
//					continue;
//				}
//				else
//				{
//					*valude++ = *myp++;
//				}
//				//myp不需要加加了因为会得循环继续判断；
//			}
//		}
//		*valude = '\0'; //当判断不成功的时候  在末尾加上结束符号；
//	}
//	return ret;
//}
//
//int main()
//{
//	char str[5][100] = {
//		"key1       =      valude1",
//		"key2      = valude2",
//		"key3      =      valude3   ",
//		"key4 =      valude4",
//		"key5=     "
//	};
//
//	char youkey[100];
//	char Value[100];
//	int rv = 0;
//	scanf("%s", &youkey);
//	rv = MyStr(str, youkey, Value);
//	if (rv != -1)
//	{
//		printf("%s", Value);
//	}
//	system("pause");
//}
