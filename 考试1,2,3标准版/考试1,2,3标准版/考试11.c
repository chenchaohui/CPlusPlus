//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<ctype.h>
//#include<memory.h>
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
//	memcpy(outbuf,inbuf+i,count);
//	outbuf[count] = '\0';
//}
//
//void main()
//{
//	char inbuf[120] = "    helloworld ";
//	char outbuf[20];
//	//char *p = (char *)malloc(20*sizeof(char));
//	//p = NULL;
//	trimSpace(inbuf, outbuf);
//	printf("%s", outbuf);
//	system("pause");
//
//}