#ifndef _CLT_SOCKET_H__
#define _CLT_SOCKET_H__
//�ͻ��˻�����ʼ��
int cltSocket_init2(void **handle);

//�ͻ��˷�����
int cltSocket_senddata2(void *handle,unsigned char *buf,int buflen);

//�ͻ����ձ���
int cltSocket_resvdata2(void*handle, unsigned char **buf, int *buflen);
//Ϊʲô����ط�������һ������ָ�룬������������һ���ӿڡ�

int cltSocket_resvdata_free2(unsigned char *buf );

//�ͻ��˻�������
//Ϊʲô����ط���������һ��*
int cltSocket_destory2(void **handle);

#endif