#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"slink.h"

int  main()
{
	int ret = 0;
	int count = 0;
	int i = 0;
	SLIST *pHead = NULL;
	SLIST *ptmp = NULL;
	//测试穿件单链表
	ret= Create_SLIST(&pHead);
	if (ret != 0)
	{
		ret = -1;
		printf("Create_SLIST,err\n");
		return ret;
	}
	//打印单链表测试
	ret = SLINK_Print(pHead);

	printf("\n");
	if (ret != 0)
	{
		printf("SLINK_Print err\n");
		return ret;
	}
	////链表间数据节点的插入
	//ret = SLINK_NodeInset(pHead, 20, 19);
	//if (ret != 0)
	//{
	//	printf("SLINK_Print err\n");
	//	return ret;
	//}
	//printf("\n");
	//ret = SLINK_Print(pHead);

	////测试一下删除功能
	//ret = SLINK_NodeDel(pHead, 19);
	//printf("\n");
	//ret = SLINK_Print(pHead);
	////测试一下查找功能
	//ret = SLINK_SearchNode(pHead,20);

	//printf("\n");
	//ret = SLIST_ModifyNode(pHead, 20, 100);
	//ret = SLINK_Print(pHead);
	//ret = SLINK_Destory(pHead);
	/*ret = SLINK_Length(pHead, &count);
	if (ret!=0)
	{
		printf("获取链表长度失败!\n");
		return ret;
	}
	printf("%d\n",count);
	for (i = 0; i < count;i++)
	{
		ptmp = SLINK_GetElem(pHead, i);
		if (ptmp != NULL)
		{
			printf("%d ", ptmp->data);
		}
		else
			break;
	}
	printf("\n");
	for (i = 0; i < count; i++)
	{
		ret = SLINK_DeleteElem(pHead, 0);
	}
	
	SLINK_Print(pHead);*/

	ret = SLINK_Reverse(pHead);
	if (ret != 0)
	{
		printf("链表逆转失败!\n");
		return ret;
	}
	else
		SLINK_Print(pHead);
	system("pause");
	return 0;
}