#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"socketclient.h"

//�ڶ���API�ӿڵĲ���
void main()
{
	int ret = 0;
	void *handle = NULL;
	unsigned char buf[128];
	int buflen = 11;
	unsigned char *outbuf;
	int outlen = 0;
	strcpy(buf, "aaaaadddddddd");
	//��ʼ������
	ret = cltSocketInit2(&handle);

	//��������
	ret = cltSocketSend2(handle, buf, buflen);

	ret = cltSocketRev2(handle, &outbuf, &outlen);

	printf("outbuf =%s", outbuf);

	ret = cltSocketRev2_Free(&outbuf);

	ret = cltSocketDestory2(&handle/*in*/);

	system("pause");
}