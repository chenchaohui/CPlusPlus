#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
/*===================================*/
/*�������ƣ�sort-1.c                 */
/*����Ŀ�ģ�ð������                 */
/* WRITTEN  BY  CHEN                 */
/*===================================*/
void printArray(int *list,int index)
{
    int i = 0;
	for (i = 0;i<index;i++)
	{
		//��ӡ����
		printf("%d ",list[i]);
	}
}

void bubbleSort(int *list,int index)
{
   int i,j,k;
   int tmp;                                    // ���ݽ���ʱ���м����
   for (j = index;j > 0;j--)                   // �������ѭ��
    {
	   for (i = 0;i<j-1;i++)                   //�����ڲ�ѭ��
	    {
		   if (list[i] > list[i+1])
		    {
				//���ݽ���
			     tmp=list[i];
			     list[i]=list[i+1];
				 list[i+1]=tmp;
				 printf("\n current sorting result:\n");

				  for (k = 0;k<index;k++)      //һ�������������������ĵ�ǰ״̬
				  {
					  printf("%d ",list[k]);
				  }

		    }
	    }
    }
}

#ifdef cplusplus
}
#endif
