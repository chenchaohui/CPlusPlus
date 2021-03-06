#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int trimSpace(char *inbuf,char *outbuf)
{
	
	int res = 0;
	//为了不移动传入的指针值，我们需要为两个参数定义两个副本
	char *inbufbak = inbuf;
	char *outbufbak = outbuf;
	if (inbufbak == NULL || outbufbak == NULL)
	{
		res = -1;
		printf("trimSpace:err %d",res);
		return res;
	}
	//当然这里的while循环也可以改写成for循环
	while ((*inbufbak) != '\0')
	{
		if ((*inbufbak) != ' ')
		{
			*outbufbak++ = *inbufbak++;
		}
		else
		{
			inbufbak++;
		}
	}
	*outbufbak = '\0';
	return 0;
}


//采用两头堵模型
int trimSpace_ok(char *mybuf, char *outbuf)
{
	int count = 0;
	int i = 0, j = 0;

	char *p = mybuf;
	j = strlen(p) -1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j]) && j>0)
	{
		j--;
	}
	count = j-i +1;

	//
	printf("count:%d", count);
	//void *  __cdecl memcpy(void *, const void *, size_t);
	memcpy(outbuf, mybuf+i, count);
	outbuf[count] = '\0';
	return 0;
	//system("pause");
}

void main31()
{
	char inbuf[32] = "    sdfgjhsgdf cffsdf    ";
	char outbuf[32] = { 0 };
	int res = 0;
	res = trimSpace(inbuf, outbuf);
	if (res!=0)
	{
		printf("自定义接口函数执行失败！");
	}
	else
	{
		printf("outbuf=%s",outbuf);
	}
	system("pause");
}

