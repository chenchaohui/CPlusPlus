#define _CRT_SECURE_NO_WARNINGS    //ȥ����ȫ����
#include"sort.h"

//��������
void main()
{

	int list[20];             //�洢���������
	int btree[2048]={ 0 };    //ȡbtree[1]--->btree[2047]��ֵ  ע����ȡbtree[2048]���Խ�磻
	                          //��������ط�ΪʲôҪ�����鶨��Ϊ��ô����Ϊ����������б���Ϊ�������У��򽫸���������ת���ɶ���������ʽ�洢����Ҫ�ϴ���ڴ�ռ�
	int index;                //������������ݵĳ���
	int node;                 //��ʱ�洢���������
	int i=0;
	list[0] = 0;
	printf("\n please input the values you want to sort[exit for 0]\n");
	index = 1;
	scanf("%d",&node);        //��node��ֵ

	while (node != 0)
	{
		list[index] = node;    //ͨ��node�����ݸ�ֵ
		index++;
		scanf("%d",&node);
	}
	index--;

	printf("����ǰ:\n");
	printArray(list,index);    //��ӡ����ǰ��״̬

	//����������
	binaryTree(btree,list,index);
	// �������
	printf("\n�����:");
	inOrder(btree,1); 

	//printArray(list,index);   //��ӡ������״̬

	system("pause");
}
