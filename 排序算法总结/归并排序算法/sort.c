#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif

	/*===================================*/
	/*�������ƣ�sort-8.c                 */
	/*����Ŀ�ģ��鲢����                 */
	/* WRITTEN  BY  CHEN                 */
	/*===================================*/

	void printArray(int *sourceArr,int index)
	{
		int i = 0;
		for (i = 0;i <= index;i++)
		{
			//��ӡ����
			printf("%d ",sourceArr[i]);
		}
		printf("\n");
	}

	//�鲢�㷨(�����ź�˳������н��кϲ�)������һ�����黮��Ϊǰ���������֣��������ֵ�Ԫ����һ�Ƚϣ�С��Ԫ�ش�������tmpArr�У���˱Ƚ���ȥ��֪��һ�����ֵ�Ԫ��ȫ����������tmpArr�У�����ٽ���һ����ʣ���Ԫ��ȫ����������tmpArr��
	void merge(int *sourceArr,int *tmpArr,int startIndex,int midIndex,int endIndex)
	{
		//����׼��
		int i,j,k;
		i =  startIndex;
		j = midIndex+1;
		k = startIndex;
		while (i != midIndex + 1 &&j != endIndex + 1)
		{
			if ( sourceArr[i] < sourceArr[j] )
			{
				tmpArr[k++] = sourceArr[i++];
			}

			else
			{
				tmpArr[k++] = sourceArr[j++];
			}
		}
		  //����i��j����һ���Ȳ��������������Ǿ����ĸ���������������������ľ��������ĳ��Ⱦ�����
		while (i != midIndex + 1)
		{
			tmpArr[k++] = sourceArr[i++];
		}
		while (j != endIndex + 1)
		{
			tmpArr[k++] = sourceArr[j++];
		}
		for (i = startIndex;i <= endIndex;i++)
		{
			sourceArr[i] = tmpArr[i];
		}
	}


	//�鲢����
	void mergeSort(int *sourceArr,int *tmpArr,int startIndex,int endIndex)
	{
		int i=0;
        int midIndex = (startIndex + endIndex)/2;
		if (startIndex < endIndex)
		{
			mergeSort(sourceArr,tmpArr,startIndex,midIndex);
			mergeSort(sourceArr,tmpArr,midIndex + 1,endIndex);
			merge(sourceArr,tmpArr,startIndex,midIndex,endIndex);			
		}		
	}

#ifdef cplusplus
}
#endif
