#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
	/*===================================*/
	/*程序名称：sort-4.c                 */
	/*程序目的：累堆排序                 */
	/*WRITTEN  BY  CHEN                  */
	/*===================================*/
	void printArray(int *heap,int index)
	{
		int i = 0;
		for (i = 1;i<=index;i++)
		{
			//打印数据
			printf("%d ",heap[i]);
		}
		printf("\n");
	}


	//建立累堆
	void createHeap(int *heap,int root,int index)
	{
	   int j;
       int tmp;                         //用于数据交换时的暂存变量
	   int finish;                      //判断累堆是否建成

	   //环境准备
	   j = root*2;                      //子节点的索引
	   tmp = heap[root];                //暂存heap的root值
	   finish = 0;                      //默认累堆建立尚未完成

	   while (j <= index && finish == 0)
	   {
		   if (j < index)
		   {
			   if (heap[j]<heap[j+1])
				   j++;
		   }
		   if (tmp >= heap[j])
		   {
			   finish = 1;          //<从序列中间位置开始使用该方法到根节点找到自己的正确位置-----》累堆建立完成
		   }
		   //为新的根节点找到合适位置的关键步骤
		   else 
		   {
              heap[j/2]=heap[j];    //当前节点值赋值给当前节点的父节点
			  j=j*2;
		   }
	   }
	   heap[j/2]=tmp;               //root值赋值给当前节点的父节点，最后这三条语句的作用是要给root节点找一个合适的位置
	}

	//建立累堆 错误的思想
	//void createHeap(int *heap,int root,int index)
	//{
	//	int j;
	//	int tmp;                         //用于数据交换时的暂存变量
	//	int finish;                      //判断累堆是否建成

	//	//环境准备
	//	j = root*2;                      //子节点的索引
	//	tmp = heap[root];                //暂存heap的root值
	//	finish = 0;                      //默认累堆建立尚未完成

	//	
	//		if (j < index)
	//		{
	//			if (heap[j]<heap[j+1])
	//				j++;
	//		}
	//		if (tmp >= heap[j])
	//		{
	//			finish = 1;          //累堆建立完成
	//		}
	//		else 
	//		{
	//			heap[j/2]=heap[j];    //当前节点值赋值给当前节点的父节点

	//			heap[j]=tmp; 
	//		}		             
	//}


	//累堆排序算法的声明
	void heapSort(int *heap,int index)
	{
		int i,j,tmp;
		//首先将二叉树转化成堆  所谓的堆就是树根元素值最大或最小的完全二叉树
		for (i=(index/2);i>=1;i--)
		{
            createHeap(heap,i,index);
		}
		//进行堆排序
		for (i=index-1;i>=1;i--)
		{
			tmp=heap[i+1];
			heap[i+1]=heap[1];
			heap[1]=tmp;

            //堆其余数值重建累堆
			createHeap(heap,1,i);                  //为新的即就是交换后的根节点找到正确的位置
			printf("\n current sorting result:\n");
			for (j=1;j <= index;j++)
			{
				printf("%d ",heap[j]);
			}
			printf("\n");
		}
	}

	#ifdef cplusplus

}
#endif
