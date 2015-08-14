#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find(char *sour,char *des,int *mycount)
{
	char *p = sour;
	char *sub = des;
	int cnt = 0;
	int ret = 0;
	if (sour == NULL || des == NULL || mycount == NULL)
	{
		ret = -1;
		return ret;
	}
	do 
	{
		p = strstr(p, des);
		if (p)
		{
			cnt++;
			p = p + strlen(sub);
		}
		else
		{
			break;
		}
	} while (*p);
	*mycount = cnt;
	return 0;
}
//do……while循环方法
void main21()
{
	char *sstr = "abc";
	char *lstr = "abcdshhabcdhhjabc";
	int cnt = 0;
	int len = strlen(sstr);
	/*char *p;
	int cnt = 0;
	p = lstr;
	do
	{
	p = strstr(p,sstr);
	if (p)
	{
	cnt++;
	p = p + strlen(sstr);
	if(*p=='\0')
	    break;
	}
	else
	{
	break;
	}
	} while (*p);*/

	//cnt = find(lstr, sstr, len);
	printf("%d",cnt);
	system("pause");
}
//while循环方法
void main22()
{
	char *sstr = "abc";
	char *lstr = "abcdshhabcdhhjabc";
	char *p;
	int cnt = 0;
	p = lstr;
	while (p = strstr(p, sstr))
	{
			cnt++;
			p = p + strlen(sstr);
		    if (*p=='\0')
		    {
				break;
		    }
	}
	printf("%d\n",cnt);
	system("pause");
}

void main23()
{
	int ret = 0;
	int count = 0;
	char *p = "dsabcsdhabcdhsihabc";
	char *p2 = "abc";
	ret = find(p, p2, &count);
	if (ret!=0)
	{
		printf("失败！");
	}
	printf("ok count=%d",count);
	system("pause");
}
