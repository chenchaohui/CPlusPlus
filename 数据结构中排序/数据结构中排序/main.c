#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
#include"sort.h"

//≤‚ ‘∞∏¿˝£∫
void main()
{
	int list[20];
	int index;
	int node;
	printf("\n Please input the values you want to sort(Exit for 0):\n");
	index = 0;
	scanf("%d",&node);
	while (node != 0)
	{
		list[index] = node;
		index++;
		scanf("%d", &node);
	}
	printf("≈≈–Ú«∞:\n");
	printArray(list, index);
	bubbleSort(list, index);
	printf("\n≈≈–Ú∫Û:\n");
	printArray(list, index);
	system("pause");
}