#define _CRT_SECURE_NO_WARNINGS    //去除安全警告
#include"sort.h"

//测试用例
void main()
{

	int list[20];             //存储输入的数据
	int btree[2048]={ 0 };    //取btree[1]--->btree[2047]的值  注意若取btree[2048]则会越界；
	                          //至于这个地方为什么要把数组定义为这么大，因为若输入的序列本来为有序序列，则将该有序序列转化成二叉树的形式存储是需要较大的内存空间
	int index;                //保存输入的数据的长度
	int node;                 //临时存储输入的数据
	int i=0;
	list[0] = 0;
	printf("\n please input the values you want to sort[exit for 0]\n");
	index = 1;
	scanf("%d",&node);        //给node赋值

	while (node != 0)
	{
		list[index] = node;    //通过node给数据赋值
		index++;
		scanf("%d",&node);
	}
	index--;

	printf("排序前:\n");
	printArray(list,index);    //打印排序前的状态

	//创建二叉树
	binaryTree(btree,list,index);
	// 中序遍历
	printf("\n排序后:");
	inOrder(btree,1); 

	//printArray(list,index);   //打印排序后的状态

	system("pause");
}
