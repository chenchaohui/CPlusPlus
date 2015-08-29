#ifndef __SLINK_H
#define __SLINK_H

//����һ���ڵ�ṹ��
typedef struct NODE
{
	int data;
	struct NODE *next;
}SLIST;
 

//����һ��������
int Create_SLIST(SLIST **Head);

//��ӡһ��������
int SLINK_Print(SLIST *pHead);

//�ڽڵ���ֵΪx��ǰ�����һ��y,��x�����ڣ���y���뵽�����ĩβ
int  SLINK_NodeInset(SLIST *pHead, int x, int y);

//ɾ���ڵ�Ϊy������ڵ�
int SLINK_NodeDel(SLIST *pHead, int y);

//���ҽڵ�Ϊz������ڵ㣬����ӡ�ýڵ���������ָ����
int SLINK_SearchNode(SLIST *pHead, int z);

//�޸Ľڵ�Ϊx������ڵ�Ϊy
int SLIST_ModifyNode(SLIST *pHead, int x,int y);

//����������
int SLINK_Destory(SLIST *pHead);

//��ȡ����ĳ���
int SLINK_Length(SLIST *pHead,int *mycnt);

//����λ�û�ȡ�����е�Ԫ��
SLIST *SLINK_GetElem(SLIST *pHead, int pos);

//����ɾ�������еĽڵ�
int SLINK_DeleteElem(SLIST *pHead, int pos);

//�������ת����ͷ���β����β���ͷ��
int SLINK_Reverse(SLIST *pHead);

#endif