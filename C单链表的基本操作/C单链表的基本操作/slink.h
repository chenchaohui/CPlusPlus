#ifndef __SLINK_H
#define __SLINK_H

//定义一个节点结构体
typedef struct NODE
{
	int data;
	struct NODE *next;
}SLIST;
 

//创建一个单链表
int Create_SLIST(SLIST **Head);

//打印一个单链表
int SLINK_Print(SLIST *pHead);

//在节点数值为x的前面插入一个y,若x不存在，则将y插入到链表的末尾
int  SLINK_NodeInset(SLIST *pHead, int x, int y);

//删除节点为y的链表节点
int SLINK_NodeDel(SLIST *pHead, int y);

//查找节点为z的链表节点，并打印该节点的数据域和指针域
int SLINK_SearchNode(SLIST *pHead, int z);

//修改节点为x的链表节点为y
int SLIST_ModifyNode(SLIST *pHead, int x,int y);

//单链表销毁
int SLINK_Destory(SLIST *pHead);

//获取链表的长度
int SLINK_Length(SLIST *pHead,int *mycnt);

//根据位置获取链表中的元素
SLIST *SLINK_GetElem(SLIST *pHead, int pos);

//依次删除链表中的节点
int SLINK_DeleteElem(SLIST *pHead, int pos);

//链表的逆转（表头变表尾，表尾变表头）
int SLINK_Reverse(SLIST *pHead);

#endif