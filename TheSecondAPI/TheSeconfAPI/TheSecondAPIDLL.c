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


__declspec(dllexport)
int cltSocketInit2(void **handle)
{
	int ret = 0;
	SCK_HANDLE *sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (handle == NULL)
	{
		ret = -1;
		printf("func cltSocketInit err:%d ", ret);
		return ret;
	}
	if (sh == NULL)
	{
		ret = -2;
		printf("func cltSocketInit err:%d ", ret);
		return ret;
	}
	strcpy(sh->version, "1.0.0");
	strcpy(sh->serverip, "192.268.0.0");
	sh->serverport = 8080;
	*handle = sh;
	return 0;

}

//客户端发报文
__declspec(dllexport)
int cltSocketSend2(void *handle, unsigned char *buf, int buflen)
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
	memcpy(sh->pBuf, buf, buflen);
	sh->buflen = buflen;
	return  ret;
}


//客户端收报文
__declspec(dllexport)
int cltSocketRev2(void *handle, unsigned char **buf, int *buflen)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if ( handle == NULL || buf == NULL|| buflen == NULL )
	{
		ret = -1;
		printf("func cltSocketRev2 err %d",ret);
		return  ret;
	}
	sh = (SCK_HANDLE *)handle;

	unsigned char *buf1 = (char *)malloc(sh->buflen * sizeof(char));

	if (buf1 == NULL)
	{
		ret = -2;
		printf("func cltSocketRev2 err %d", ret);
		return ret;
	}
	memcpy(buf1,sh->pBuf,sh->buflen);
	*buflen = sh->buflen;
	*buf = buf1;
	return ret;
}


__declspec(dllexport)
int cltSocketRev2_Free(unsigned char **buf)
{
	int ret = 0;
	if (buf == NULL)
	{
		ret = -1;
		printf("func cltSocketRev2_Free err %d",ret);
		return ret;
	}
	if ((*buf) != NULL)
	{
		free(*buf);
		*buf = NULL;
	}
	//free(buf);
	return ret;
}


//客户端释放资源
__declspec(dllexport)
int cltSocketDestory2(void **handle)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL)
	{
		ret = -1;
		printf("func cltSocketRev2_Free err %d", ret);
		return ret;
	}
	sh = (SCK_HANDLE *)(*handle);	
	if ( sh!= NULL)
	{
		free(sh->pBuf);
		free(sh);
		sh = NULL;
	}
	//free(handle);
	return ret;
}
