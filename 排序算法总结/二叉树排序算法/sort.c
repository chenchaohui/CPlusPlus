#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif

	/*===================================*/
	/*程序名称：sort-7.c                 */
	/*程序目的：二叉树排序               */
	/* WRITTEN  BY  CHEN                 */
	/*===================================*/

	void printArray(int *btree,int index)
	{
		int i = 0;
		for (i = 1;i <= index;i++)
		{
			//打印数据
			printf("%d ",btree[i]);
		}
		printf("\n");
	}

	//创建二叉树《通过测试可知构建二叉树没有出错》
	void binaryTree(int *btree ,int *list, int index)
	{
		int i = 0;
		int level = 1;
		btree[1] = list[1];

		for (i = 2; i <= index; i++)
		{
			level = 1; 
			while ( btree[level] != 0 )
			{
				if (list[i] > btree[level])
				{
					level = 2*level+1;
				}
				else
				{
					level = 2*level;
				}
			}
			btree[level] = list[i];
		}
	}

	//存储树节点值的数组必须先初始化为0
	//二叉树中序遍历<中序遍历的原则是：先遍历左子树上的值--->再遍历根节点---->最后遍历左子树>
	void inOrder(int *btree,int position)
	{
		if ( btree[position] != 0 && position < 2048) //这个地方为什么采用2048 因为：若输入的序列本来就是顺序的且有11行，则生成二叉树后最后一个元素的位置为btree[2047]所以……
		{			
			inOrder(btree,2*position);           //左子树
			if (btree[position] != 0)
			{
				printf("%d ",btree[position]);   //根节点
			}
			inOrder(btree,2*position + 1);       //右子树
		}
	}

#ifdef cplusplus
}
#endif
