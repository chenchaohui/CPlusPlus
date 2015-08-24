//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int getResBuf( const char *buf1,int buflen,const char *buf,int *mycount,char *src)
//{
//	int ret = -1;
//	char *srcbak = src;
//	char *p = src;
//	//先排除错误情况
//	if (buf1==NULL||buf==NULL||src==NULL)
//	{
//		printf("getResBuf Error:%d,%s",ret,"buf1==NULL||buf==NULL||src==NULL");
//		return ret;
//	}
//	//查找特定字符串在长字符串中出现的次数
//	do 
//	{
//		p = strstr(p,buf);
//		if (p == NULL)
//		{
//			break;
//		}
//		else
//		{
//			(*mycount)++;
//			p = p + strlen(buf);
//		}
//	} while (*p!='\0');
//
//	memcpy(srcbak, buf1, buflen);
//	*(srcbak + buflen) = '\0';
//	return 0;
//}
//void main()
//{
//	int ret = -1;
//	char src[2048] = { "abcd11111abcd2222abcdqqqqq" };
//	char buf1[256] = { "dcba11111dcba2222dcbaqqqqq" };
//	int len = sizeof(buf1) / sizeof(char);
//	char buf[128] = { "abcd" };
//	int count = 0;
//	ret =getResBuf(buf1, len, buf, &count, src);
//
//	if (ret==-1)
//	{
//		printf("获取失败\n");
//		return;
//	}
//	printf("%d\n",count);
//	printf("%s",src);
//	system("pause");
//}