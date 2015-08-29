#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"socketclient.h"
#include"itcastlog.h"

//第一个API接口的测试
void main()
{
	int ret = 0;
	void *handle = NULL;
	unsigned char buf[128];
	int buflen = 11;
	unsigned char outbuf[128];
	int outlen;
	strcpy(buf,"aaaaadddddddd");
	//初始化环境
	ret = cltSocketInit(&handle);
	if (ret != 0)
	{
		printf("初始化失败 err %d\n",ret);
		goto END;
	}
	//发送数据
	ret = cltSocketSend(handle, buf, buflen);
	if (ret != 0)
	{
		printf("数据发送失败 err %d\n",ret );
		goto END;
	}

	ret = cltSocketRev(handle, outbuf, &outlen);
	if (ret != 0)
	{
		printf("数据接收失败 err %d\n", ret);
		goto END;
	}
	printf("outbuf =%s",outbuf);

END:
	//客户端释放资源
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

