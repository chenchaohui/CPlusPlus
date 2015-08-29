//------------------第一套api接口---Begin--------------------------------//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _SCK_HANDLE
{
	char  version[16];
	char  serverip[16];
	int   serverport;
	char  *pBuf;
	int   buflen;

}SCK_HANDLE;

//客户端初始化 获取handle上下
__declspec(dllexport)
int cltSocketInit(void **handle /*out*/)
{
	int ret = 0;
	SCK_HANDLE *sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (handle == NULL)
	{
		ret = -1;
		printf("func cltSocketInit err:%d ",ret);
		return ret;
	}
	if (sh == NULL)
	{
		ret = -2;
		printf("func cltSocketInit err:%d ",ret);
		return ret;
	}
	strcpy(sh->version,"1.0.0");
	strcpy(sh->serverip,"192.268.0.0");
	sh->serverport = 8080;
	*handle = sh;
	return 0;
}

//客户端发报文(重缓冲区中赋值到pBuf指向的内存中)
__declspec(dllexport)
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/)
{
	SCK_HANDLE *sh = NULL;
	int ret = 0;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("func cltSocketSend err %d", ret);
		return ret;
	}
	sh = (SCK_HANDLE *)handle;
	sh->pBuf = (char *)malloc(buflen*sizeof(char));
	if (sh->pBuf == NULL)
	{
		ret = -2;
		printf("func cltSocketSend err %d", ret);
		return ret;
	}
	memcpy(sh->pBuf,buf,buflen);
	sh->buflen = buflen;
	return  ret;
}

//客户端收报文（从pBuf指向的内存区中获取报文到buf指向的内存中）
__declspec(dllexport)
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL || buf == NULL || buflen == NULL)
	{
		ret = -1;
		printf("func cltSocketSend err %d", ret);
		return ret;
	}
	sh = (SCK_HANDLE *)handle;
	memcpy(buf,sh->pBuf,sh->buflen);
	*buflen = sh->buflen;
	return ret;

}

//客户端释放资源
__declspec(dllexport)
int cltSocketDestory(void *handle/*in*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL)
	{
		ret = -1;
		printf("func cltSocketSend err %d", ret);
		return ret;
	}
	sh = (SCK_HANDLE *)handle;
	if (sh->pBuf != NULL)
	{
		free(sh->pBuf);
	}
	free(sh);

	return ret;
}