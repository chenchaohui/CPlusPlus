#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif

	/*===================================*/
	/*�������ƣ�sort-7.c                 */
	/*����Ŀ�ģ�����������               */
	/* WRITTEN  BY  CHEN                 */
	/*===================================*/

	void printArray(int *btree,int index)
	{
		int i = 0;
		for (i = 1;i <= index;i++)
		{
			//��ӡ����
			printf("%d ",btree[i]);
		}
		printf("\n");
	}

	//������������ͨ�����Կ�֪����������û�г���
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

	//�洢���ڵ�ֵ����������ȳ�ʼ��Ϊ0
	//�������������<���������ԭ���ǣ��ȱ����������ϵ�ֵ--->�ٱ������ڵ�---->������������>
	void inOrder(int *btree,int position)
	{
		if ( btree[position] != 0 && position < 2048) //����ط�Ϊʲô����2048 ��Ϊ������������б�������˳�������11�У������ɶ����������һ��Ԫ�ص�λ��Ϊbtree[2047]���ԡ���
		{			
			inOrder(btree,2*position);           //������
			if (btree[position] != 0)
			{
				printf("%d ",btree[position]);   //���ڵ�
			}
			inOrder(btree,2*position + 1);       //������
		}
	}

#ifdef cplusplus
}
#endif
