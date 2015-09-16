#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
	/*===================================*/
	/*�������ƣ�sort-4.c                 */
	/*����Ŀ�ģ��۶�����                 */
	/*WRITTEN  BY  CHEN                  */
	/*===================================*/
	void printArray(int *heap,int index)
	{
		int i = 0;
		for (i = 1;i<=index;i++)
		{
			//��ӡ����
			printf("%d ",heap[i]);
		}
		printf("\n");
	}


	//�����۶�
	void createHeap(int *heap,int root,int index)
	{
	   int j;
       int tmp;                         //�������ݽ���ʱ���ݴ����
	   int finish;                      //�ж��۶��Ƿ񽨳�

	   //����׼��
	   j = root*2;                      //�ӽڵ������
	   tmp = heap[root];                //�ݴ�heap��rootֵ
	   finish = 0;                      //Ĭ���۶ѽ�����δ���

	   while (j <= index && finish == 0)
	   {
		   if (j < index)
		   {
			   if (heap[j]<heap[j+1])
				   j++;
		   }
		   if (tmp >= heap[j])
		   {
			   finish = 1;          //<�������м�λ�ÿ�ʼʹ�ø÷��������ڵ��ҵ��Լ�����ȷλ��-----���۶ѽ������
		   }
		   //Ϊ�µĸ��ڵ��ҵ�����λ�õĹؼ�����
		   else 
		   {
              heap[j/2]=heap[j];    //��ǰ�ڵ�ֵ��ֵ����ǰ�ڵ�ĸ��ڵ�
			  j=j*2;
		   }
	   }
	   heap[j/2]=tmp;               //rootֵ��ֵ����ǰ�ڵ�ĸ��ڵ㣬�������������������Ҫ��root�ڵ���һ�����ʵ�λ��
	}

	//�����۶� �����˼��
	//void createHeap(int *heap,int root,int index)
	//{
	//	int j;
	//	int tmp;                         //�������ݽ���ʱ���ݴ����
	//	int finish;                      //�ж��۶��Ƿ񽨳�

	//	//����׼��
	//	j = root*2;                      //�ӽڵ������
	//	tmp = heap[root];                //�ݴ�heap��rootֵ
	//	finish = 0;                      //Ĭ���۶ѽ�����δ���

	//	
	//		if (j < index)
	//		{
	//			if (heap[j]<heap[j+1])
	//				j++;
	//		}
	//		if (tmp >= heap[j])
	//		{
	//			finish = 1;          //�۶ѽ������
	//		}
	//		else 
	//		{
	//			heap[j/2]=heap[j];    //��ǰ�ڵ�ֵ��ֵ����ǰ�ڵ�ĸ��ڵ�

	//			heap[j]=tmp; 
	//		}		             
	//}


	//�۶������㷨������
	void heapSort(int *heap,int index)
	{
		int i,j,tmp;
		//���Ƚ�������ת���ɶ�  ��ν�ĶѾ�������Ԫ��ֵ������С����ȫ������
		for (i=(index/2);i>=1;i--)
		{
            createHeap(heap,i,index);
		}
		//���ж�����
		for (i=index-1;i>=1;i--)
		{
			tmp=heap[i+1];
			heap[i+1]=heap[1];
			heap[1]=tmp;

            //��������ֵ�ؽ��۶�
			createHeap(heap,1,i);                  //Ϊ�µļ����ǽ�����ĸ��ڵ��ҵ���ȷ��λ��
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
