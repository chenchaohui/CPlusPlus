#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
	/*===================================*/
	/*�������ƣ�sort-3.c                 */
	/*����Ŀ�ģ�ѡ������                 */
	/*WRITTEN  BY  CHEN                  */
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

	void selectSort(int *list,int index)
	{
		int i ,j, k;      // ���ڿ���ѭ������������
		int minnode;      // �洢��С��ֵ
		int indexMin;     //�洢��С��ֵ������
		int tmp;          //��ֵ����ʱ���ݴ����

		//�����㷨һ      //Ҫͨ����ͼ�õ��㷨����
		/*for (i = 0;i < index - 1; i++)
		{
			for (j = i+1;j < index; j++)
			{
				if (list[i]>list[j])
				{
					tmp=list[i];
					list[i]=list[j];
					list[j]=tmp;
					printf("\n current sorting result:");
					for (k = 0; k < index; k++)
					{
						printf("%d ",list[k]);
					}
				}
				
			}
		}*/

		//�����㷨��
		for (i = 0;i < index - 1; i++)
		{
			minnode=32767;
		    indexMin = 0;
			for (j = i;j < index; j++)
			{
				if (list[j]<minnode)
				{
					minnode=list[j];              //����Сֵ�洢������minnode��
					indexMin=j;

					tmp=list[i];                   /*��������ֵ*/
					list[i]=list[indexMin];
					list[indexMin]=tmp;

					printf("\n current sorting result:");
					for (k = 0; k < index; k++)
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
