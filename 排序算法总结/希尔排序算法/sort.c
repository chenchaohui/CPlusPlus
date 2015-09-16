#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
/*===================================*/
/*�������ƣ�sort-6.c                 */
/*����Ŀ�ģ�ϣ������                 */
/* WRITTEN  BY  CHEN                 */
/*===================================*/

//��ӡ�����е�Ԫ��
void printArray(int *list,int index)
{
    int i = 0;
	for (i = 0;i<index;i++)
	{
		//��ӡ����
		printf("%d ",list[i]);
	}
}

//ϣ���������
void shellSort(int *list,int index)
{
  int i,j,k;                  //���ڿ���ѭ���ı���
  int tmp;                    //�������ݽ������м����
  int group;                  //������Ԫ�صķָ���

  for ( group = index/2; group > 0; group /= 2 )
  {
	  for (i = group;i < index; i++)
	  {
		  for (j = i-group;j > 0;j-=group)
		  {
			  if (list[j] > list[j+group])
			  {

				  tmp = list[j];
				  list[j] = list[j+group];
				  list[j+group]=tmp;
			  }

		  }      
	  }
	  printf("\n current sorting result:");
	  for (k = 0;k < index; k++)
	  {
		  printf("%d ",list[k]);
	  }
  }

}

//void shellSort(int *list,int index)
//{ 	
//	{
//		int group;         // �ָ�ϵļ������
//
//		int i, j, tmp;   //i,j,k ���ڿ���ѭ���ı�����temp �������ݽ������ݴ����
//		int k = 0;
//		for (group = index / 2; group > 0; group /= 2)
//		{
//			for (i = group; i < index; i++)
//			{
//				for (j = i - group; j >= 0; j -= group)
//				{
//					if (list[j] > list[j + group])
//					{
//						tmp = list[j];
//						list[j] = list[j + group];
//						list[j + group] = tmp;
//					}				
//				}				
//			}
//			printf("\n current sorting result:");
//			for ( k =0; k < index; k++)
//			{
//				printf("%d ",list[k]);
//			}
//		}
//	}
//
//} 

#ifdef cplusplus
}
#endif
