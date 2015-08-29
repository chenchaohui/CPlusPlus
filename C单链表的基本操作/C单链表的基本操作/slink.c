#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"slink.h"

//创建一个单链表
int Create_SLIST(SLIST **Head)
{
	int ret = 0;
	int data = 0;
	SLIST *pHead = NULL, *pCur = NULL, *pM = NULL;
	//创建一个指向头结点的指针
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{   
		ret = -1;

		printf("func Create_SLIST err %d",ret);
		return ret;
	}
	//头结点的初始化
	pHead->data = 0;
	pHead->next = NULL;
	printf("\nPlease enter the data of node(-1:quit)");
	scanf("%d", &data);
	//准备环境
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

//打印一个单链表
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
	//环境准备
	pCur = pHead->next;
	while (pCur)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	return 0;
}

//在节点数值为x的前面插入一个y,若x不存在，则将y插入到链表的末尾
int  SLINK_NodeInset(SLIST *pHead, int x, int y)
{
	int ret = 0;
	//记住王老师的模型4-26上午
	SLIST * pCur = NULL, *pPre = NULL, *pM = NULL;//这三个变量的定义是非常重要的
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLINK_NodeInset err %d", ret);
		return ret;
	}
	//环境准备
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

//删除节点为y的链表节点
int SLINK_NodeDel(SLIST *pHead, int y)
{
	int ret = 0;
	//记住王老师的模型4-26上午
	SLIST *pPre = NULL, *pCur = NULL, *pTmp = NULL;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLINK_NodeDel err %d\n", ret);
		return ret;
	}
	//环境准备
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
	//环境准备
	pCur = pHead->next;
	while (pCur)
	{
		if (pCur->data == z)
		{
			printf("&z=%x", pCur);
			break;
		}
		//这一步是避免死循环的关键步骤，没有这一步必然会出现死循环
		pCur = pCur->next;
	}
	if (pCur == NULL)
	{
		ret = -2;
		printf("找不到对应的数据\n");
		return ret;
	}
	return 0;
}

//修改节点为x的链表节点为y
int SLIST_ModifyNode(SLIST *pHead, int x, int y)
{
    //本质也是先查找，再修改
	int ret = 0;
	SLIST* pCur = NULL;
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLINK_SearchNode err %d", ret);
		return ret;
	}
	//环境准备
	pCur = pHead->next;
	while (pCur)
	{
		if (pCur->data == x)
		{
			pCur->data = y;
			break;
		}
		//这一步是避免死循环的关键步骤，没有这一步必然会出现死循环
		pCur = pCur->next;
	}
	if (pCur == NULL)
	{
		ret = -2;
		printf("找不到对应的数据\n");
		return ret;
	}
	return 0;
}

//单链表销毁
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
	//环境准备
	pCur = pHead->next;
	while (pCur)
	{
		pTmp = pCur->next;
		free(pCur);
		pCur = pTmp;
	}
	return 0;
}

//获取链表的长度
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
	//环境准备
	pCur = pHead->next;
	while (pCur != NULL)
	{
		cnt++;
		pCur = pCur->next;
	}
	*mycnt = cnt;
	return ret;
}

//根据位置获取链表中的元素
SLIST *SLINK_GetElem(SLIST *pHead, int pos)
{
	int cnt = 0;
	SLIST *pCur = NULL;
	//准备环境
	pCur = pHead->next;

	while (pCur != NULL)
	{
		if (cnt==pos)
		{
			break;
		}
		pCur = pCur->next;
		//不能忘了这个步骤
		cnt++;
	}
	return pCur;
}

//依次删除链表中的节点
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
	//环境准备
	pCur = pHead->next;
	pTmp = pCur->next;
	free(pCur);
	pHead->next = pTmp;
	return 0;
}

//链表的逆转（表头变表尾，表尾变表头）
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
	//先做判断，若没有节点，或只有一个节点有不需要逆转
	if (pHead->next == NULL||pHead->next->next == NULL)
	{
		printf("链表只有头结点或只有一个节点，不需要逆转\n");
		return 0;
	}
	//环境准备
	p = pHead->next;
	q = pHead->next->next;
	while (q != NULL)
	{
		//链表逆转操作的核心代码
		pTmp = q->next;
		q->next = p;
		p = q;
		q = pTmp;		
	}
	//对原来头指针和未指针的处理
	pHead->next->next = NULL;
	pHead->next = p;
	
	return 0;
}