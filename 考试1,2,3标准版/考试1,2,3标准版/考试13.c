//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<memory.h>
//#include<ctype.h>
//
////两头堵模型
////一般情况下不要修改输入的内存快的值
// void trimSpace(char *inbuf,char *outbuf)
//{
//	//这里我自己需要特别注意sizeof和strlen的用法区别
//	//sizeof主要用于求类型和变量的大小，strlen主要用于求指针指向的内存空间和字符串的大小
//	int i = 0;
//	int j = strlen(inbuf) - 1;
//	int count = 0;
//	char *p = NULL;
//	p = inbuf;
//	if (inbuf==NULL||outbuf==NULL)
//	{
//		printf("trimSpace error:%s", "inbuf == NULL || outbuf == NULL");
//	}
//	while (isspace(p[i]))
//	{
//		i++;
//	}
//	while (isspace(p[j]))
//	{
//		j--;
//	}
//	count = j - i + 1;
//	//最关键的一步
//	memcpy(outbuf,inbuf+i,count);
//	outbuf[count] = '\0';
//}
// //通过键获取值
//int getValueByKey(char (*src)[128],char *key,char *keyvalue,int num)
//{
//	int ret = -1;
//	char *p = NULL;
//	if (src==NULL||key==NULL||keyvalue==NULL)
//	{
//		printf("getValueByKey Error:%d", ret);
//		return ret;
//	}
//	//第一步：找key值
//	for (int i = 0; i < num; i++)
//	{
//		p = strstr(src[i], key);	
//		if (p!=NULL)
//		{
//			break;
//		}
//	}
//	if (p == NULL)
//	{
//		printf("找不到对应的key值\n");
//		return ret;
//	}
//	p = p + strlen(key);
//	//第二步：找等号
//	p = strchr(p, '=');
//	if (p == NULL)
//	{
//		printf("无=号无法构成键值对\n");
//		return ret;
//	}
//	p = p + 1;
//	//第三步：去空格
//	trimSpace(p, keyvalue);
//	printf("%s\n", keyvalue);
//	return 0;
//}
//
//
//void main()
//{
//	char src[4][128] = {
//		"key1 =value1",
//		"key2   =value2    ",
//		"key3=value3       ",
//		"key4    =  value4 "
//	};
//	int ret = 0;
//	char key[128] = { 0 };
//	char keyValue[128] = { 0 };
//	int i = 0;
//	scanf("%s",key);
//	getValueByKey(src,key,keyValue,4);
//	system("pause");
//}