#include"sort.h"
#ifdef cplusplus
extern "c"{
#endif
/*===================================*/
/*程序名称：sort-5.c                 */
/*程序目的：插入排序                 */
/* WRITTEN  BY  CHEN                 */
/*===================================*/
void printArray(int *list,int index)
{
    int i = 0;
	for (i = 0;i<index;i++)
	{
		//打印数据
		printf("%d ",list[i]);
	}
}

void insertSort(int *list,int index)
{
   int i,j,k;
   int insertnode;
    for (i=1;i<index;i++)
    {
		insertnode = list[i];
		j=i-1;
		while (j>=0 && insertnode < list[j])
		{
			list[j+1]=list[j];
			j--;
		}
		list[j+1]=insertnode;
		printf("\ncurrent sorting result:");
		for (k=0;k<index;k++)
		{
			printf("%d ",list[k]);
		}

    }


} 

#ifdef cplusplus
}
#endif
