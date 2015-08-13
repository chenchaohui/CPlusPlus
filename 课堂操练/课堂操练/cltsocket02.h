#ifndef _CLT_SOCKET_H__
#define _CLT_SOCKET_H__
//客户端环境初始化
int cltSocket_init2(void **handle);

//客户端发报文
int cltSocket_senddata2(void *handle,unsigned char *buf,int buflen);

//客户端收报文
int cltSocket_resvdata2(void*handle, unsigned char **buf, int *buflen);
//为什么这个地方换成了一个二级指针，而且又增加了一个接口。

int cltSocket_resvdata_free2(unsigned char *buf );

//客户端环境销毁
//为什么这个地方又增加了一个*
int cltSocket_destory2(void **handle);

#endif