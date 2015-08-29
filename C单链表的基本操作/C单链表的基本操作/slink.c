#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"slink.h"

//����һ��������
int Create_SLIST(SLIST **Head)
{
	int ret = 0;
	int data = 0;
	SLIST *pHead = NULL, *pCur = NULL, *pM = NULL;
	//����һ��ָ��ͷ����ָ��
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{   
		ret = -1;

		printf("func Create_SLIST err %d",ret);
		return ret;
	}
	//ͷ���ĳ�ʼ��
	pHead->data = 0;
	pHead->next = NULL;
	printf("\nPlease enter the data of node(-1:quit)");
	scanf("%d", &data);
	//׼������
	pCur = pHead;
	while (data != -1)
	{
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			ret = -2;
			SLINK_Destory(pHead);
			printf("func Create_SLIST malloc err %d",ret);
			return ret;
		}
		pM->data = data;
		pM->next = NULL;
		pCur->next = pM;
		pCur = pM;
		printf("\nPlease enter the data of node(-1:quit)");
		scanf("%d", &data);
	}
	*Head = pHead;
	return 0;
}

//��ӡһ��������
int SLINK_Print(SLIST *pHead)
{
	int ret = 0;
	SLIST *pCur = NULL;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLINK_Print err %d", ret);
		return ret;
	}
	//����׼��
	pCur = pHead->next;
	while (pCur)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	return 0;
}

//�ڽڵ���ֵΪx��ǰ�����һ��y,��x�����ڣ���y���뵽�����ĩβ
int  SLINK_NodeInset(SLIST *pHead, int x, int y)
{
	int ret = 0;
	//��ס����ʦ��ģ��4-26����
	SLIST * pCur = NULL, *pPre = NULL, *pM = NULL;//�����������Ķ����Ƿǳ���Ҫ��
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLINK_NodeInset err %d", ret);
		return ret;
	}
	//����׼��
	pPre = pHead;
	pCur = pHead->next;
	pM = (SLIST *)malloc(sizeof(SLIST));
	if (pM == NULL)
	{
		ret = -2;
		printf("func SLINK_NodeInset err %d", ret);
		return ret;
	}
	pM->data = y;
	pM->next = NULL;

	while (pCur)
	{
		if (pCur->data == x)
		{
			break;
		}
		pPre = pCur;
		pCur = pCur->next;
	}

	pM->next = pPre->next;           //pCur
	pPre->next = pM;

	return 0;

}

//ɾ���ڵ�Ϊy������ڵ�
int SLINK_NodeDel(SLIST *pHead, int y)
{
	int ret = 0;
	//��ס����ʦ��ģ��4-26����
	SLIST *pPre = NULL, *pCur = NULL, *pTmp = NULL;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLINK_NodeDel err %d\n", ret);
		return ret;
	}
	//����׼��
	pPre = pHead;
	pCur = pHead->next;
	while (pCur)
	{
		if (pCur->data == y)
		{
			break;
		}
		pPre = pCur;
		pCur = pCur->next;
	}
	if (pCur == NULL)
	{
		ret = -2;
		printf("func SLINK_NodeDel err %d\n", ret);
		return ret;
	}
	pPre->next = pCur->next;
	free(pCur);
	return 0;
}

int SLINK_SearchNode(SLIST *pHead, int z)
{
	int ret = 0;
	SLIST* pCur = NULL;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLINK_SearchNode err %d", ret);
		return ret;
	}
	//����׼��
	pCur = pHead->next;
	while (pCur)
	{
		if (pCur->data == z)
		{
			printf("&z=%x", pCur);
			break;
		}
		//��һ���Ǳ�����ѭ���Ĺؼ����裬û����һ����Ȼ�������ѭ��
		pCur = pCur->next;
	}
	if (pCur == NULL)
	{
		ret = -2;
		printf("�Ҳ�����Ӧ������\n");
		return ret;
	}
	return 0;
}

//�޸Ľڵ�Ϊx������ڵ�Ϊy
int SLIST_ModifyNode(SLIST *pHead, int x, int y)
{
    //����Ҳ���Ȳ��ң����޸�
	int ret = 0;
	SLIST* pCur = NULL;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLINK_SearchNode err %d", ret);
		return ret;
	}
	//����׼��
	pCur = pHead->next;
	while (pCur)
	{
		if (pCur->data == x)
		{
			pCur->data = y;
			break;
		}
		//��һ���Ǳ�����ѭ���Ĺؼ����裬û����һ����Ȼ�������ѭ��
		pCur = pCur->next;
	}
	if (pCur == NULL)
	{
		ret = -2;
		printf("�Ҳ�����Ӧ������\n");
		return ret;
	}
	return 0;
}

//����������
int SLINK_Destory(SLIST *pHead)
{
	int ret = 0;
	SLIST *pCur = NULL;
	SLIST *pTmp = NULL;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLINK_Destory err %d", ret);
		return ret;
	}
	//����׼��
	pCur = pHead->next;
	while (pCur)
	{
		pTmp = pCur->next;
		free(pCur);
		pCur = pTmp;
	}
	return 0;
}

//��ȡ����ĳ���
int SLINK_Length(SLIST *pHead,int *mycnt)
{
	int ret = 0;
	SLIST *pCur = NULL;
	int cnt = 0;
	if (pHead == NULL)
	{
		ret = -1;
		printf("Func SLINK_Length err %d\n",ret);
		return ret;
	}
	//����׼��
	pCur = pHead->next;
	while (pCur != NULL)
	{
		cnt++;
		pCur = pCur->next;
	}
	*mycnt = cnt;
	return ret;
}

//����λ�û�ȡ�����е�Ԫ��
SLIST *SLINK_GetElem(SLIST *pHead, int pos)
{
	int cnt = 0;
	SLIST *pCur = NULL;
	//׼������
	pCur = pHead->next;

	while (pCur != NULL)
	{
		if (cnt==pos)
		{
			break;
		}
		pCur = pCur->next;
		//���������������
		cnt++;
	}
	return pCur;
}

//����ɾ�������еĽڵ�
int SLINK_DeleteElem(SLIST *pHead, int pos)
{
	int ret = 0;
	SLIST *pTmp = NULL,*pCur = NULL;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLINK_DeleteElem err %d\n",ret);
		return ret;
	}
	//����׼��
	pCur = pHead->next;
	pTmp = pCur->next;
	free(pCur);
	pHead->next = pTmp;
	return 0;
}

//�������ת����ͷ���β����β���ͷ��
int SLINK_Reverse(SLIST *pHead)
{
	int ret = 0;
	SLIST *p = NULL, *q = NULL, *pTmp = NULL;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func  SLINK_Reverse %d\n",ret);
		return ret;
	}
	//�����жϣ���û�нڵ㣬��ֻ��һ���ڵ��в���Ҫ��ת
	if (pHead->next == NULL||pHead->next->next == NULL)
	{
		printf("����ֻ��ͷ����ֻ��һ���ڵ㣬����Ҫ��ת\n");
		return 0;
	}
	//����׼��
	p = pHead->next;
	q = pHead->next->next;
	while (q != NULL)
	{
		//������ת�����ĺ��Ĵ���
		pTmp = q->next;
		q->next = p;
		p = q;
		q = pTmp;		
	}
	//��ԭ��ͷָ���δָ��Ĵ���
	pHead->next->next = NULL;
	pHead->next = p;
	
	return 0;
}