#ifndef _CLT_SOCKET_H__
#define _CLT_SOCKET_H__
//客户端环境初始化
int cltSocket_init(void **handle);

//客户端发报文
int cltSocket_senddata(void *handle,unsigned char *buf,int buflen);

//客户端收报文
int cltSocket_resvdata(void*handle, unsigned char *buf, int buflen);

//客户端环境销毁
int cltSocket_destory2(void *handle);

#endif