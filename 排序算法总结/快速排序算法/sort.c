#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
	/*===================================*/
	/*�������ƣ�sort-2.c                 */
	/*����Ŀ�ģ���������                 */
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


	int partition(int *list,int low,int high )
	{
		int tmp;
		while (low < high)
		{                                               //�Ե�һ��Ԫ�ص�λ��Ϊ��Ŧ��������ɨ�裬�ҵ���һ������Ŧλ���ϵ�Ԫ��С��Ԫ��
			while (low < high && list[high] > list[low])
			{
				high--;
			}
		    tmp = list[high];                        //�ҵ��󽻻��ߵ�λ���ϵ�Ԫ�أ����Ը�λ��Ϊ��Ŧλ��
			list[high] = list[low];
			list[low] = tmp;

			while (low < high && list[low] < list[high]) //Ȼ���������ɨ�裬�ҵ���һ���ȸ�λ���ϵ�Ԫ�ش��Ԫ��
			{
				low++;
			}
			tmp = list[high];                            //�����ߵ�λ���ϵ�Ԫ�أ����Ե�λ��Ϊ��Ŧλ�ü���ѭ��
			list[high] = list[low];
			list[low] = tmp;
		}
		return low;                                      //�ҵ�һ����Ŧλ�ã�ʹ����Ŧλ����ߵ�Ԫ�ز���ȸ�λ���ϵ�Ԫ�ش��ұߵ�Ԫ�ز�����С
	}
	
	void quickSortHelp(int *list,int low, int high)
	{
		if (low < high)                                  //������ȵݹ�
		{
			int pivotLoc=partition(list,low,high);       //�ҵ���һ�����յ���Ŧλ��
			quickSortHelp(list,low,pivotLoc-1);
			quickSortHelp(list,pivotLoc+1,high);
		}
	}
	//��װquickSortHelp
	void quickSort(int *list,int n)
	{
	   quickSortHelp(list,0,n-1);
	}

#ifdef cplusplus
}
#endif
