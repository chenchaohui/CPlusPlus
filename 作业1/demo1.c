#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int trimSpace(char *inbuf,char *outbuf)
{
	
	int res = 0;
	//Ϊ�˲��ƶ������ָ��ֵ��������ҪΪ��������������������
	char *inbufbak = inbuf;
	char *outbufbak = outbuf;
	if (inbufbak == NULL || outbufbak == NULL)
	{
		res = -1;
		printf("trimSpace:err %d",res);
		return res;
	}
	//��Ȼ�����whileѭ��Ҳ���Ը�д��forѭ��
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


void main31()
{
	char inbuf[32] = "    sdfgjhsgdf cffsdf    ";
	char outbuf[32] = { 0 };
	int res = 0;
	res = trimSpace(inbuf, outbuf);
	if (res!=0)
	{
		printf("�Զ���ӿں���ִ��ʧ�ܣ�");
	}
	else
	{
		printf("outbuf=%s",outbuf);
	}
	system("pause");
}