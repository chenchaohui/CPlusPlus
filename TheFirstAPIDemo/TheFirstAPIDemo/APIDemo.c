#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"socketclient.h"
#include"itcastlog.h"

//��һ��API�ӿڵĲ���
void main()
{
	int ret = 0;
	void *handle = NULL;
	unsigned char buf[128];
	int buflen = 11;
	unsigned char outbuf[128];
	int outlen;
	strcpy(buf,"aaaaadddddddd");
	//��ʼ������
	ret = cltSocketInit(&handle);
	if (ret != 0)
	{
		printf("��ʼ��ʧ�� err %d\n",ret);
		goto END;
	}
	//��������
	ret = cltSocketSend(handle, buf, buflen);
	if (ret != 0)
	{
		printf("���ݷ���ʧ�� err %d\n",ret );
		goto END;
	}

	ret = cltSocketRev(handle, outbuf, &outlen);
	if (ret != 0)
	{
		printf("���ݽ���ʧ�� err %d\n", ret);
		goto END;
	}
	printf("outbuf =%s",outbuf);

END:
	//�ͻ����ͷ���Դ
	if (handle != NULL)
	{
		cltSocketDestory(handle/*in*/);
	}

	ITCAST_LOG(__FILE__, __LINE__, LogLevel[0], 0, "dddddd");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[1], 1, "dddddd");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 2, "dddddd");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[3], 3, "dddddd");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 4, "dddddd");
	system("pause");
}

