#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getstr1str2(char *src,char *buf1,char *buf2)
{
	//为了不改变传递过来的参数的值，现在为各个参数定义一个副本
	//buf1用于存储奇数为上的字符信息，buf2用于存储偶数为上的信息。
	char *srcbak = src;
	char *buf1bak = buf1;
	char * buf2bak = buf2;
	size_t i;
	int ret = 0;
	if (src==NULL||buf1==NULL||buf2==NULL)
	{
		ret = -1;
		printf("getstr1str2:err %d",ret);
		return ret;
	}
	//采用for循环实现题目要求
	//对源字符串奇数为进行操作
	for (i = 0; i< strlen(srcbak);i+=2)
	{
		*buf1bak = srcbak[i];
		buf1bak++;
	}

	//对字符串进行偶数位上的操作
	for (i = 1; i<strlen(srcbak);i+=2)
	{
		*buf2bak = srcbak[i];
		buf2bak++;
	}
	return 0;
}

int main32()
{
	char *src = "1a2b3d4z";
	char buf1[20] = { 0 };
	char buf2[20] = { 0 };
	int ret = 0;
	ret = getstr1str2(src, buf1, buf2);
	if (ret == -1)
	{
		printf("err:%d", ret);
	}
	else
		printf("恭喜您,执行成功!");
	printf("源字符串%s\n",src);
	printf("源字符串奇数位上的字符组成的串%s\n",buf1);
	printf("源字符串偶数位上的字符组成的串%s\n", buf2);
	system("pause");

}