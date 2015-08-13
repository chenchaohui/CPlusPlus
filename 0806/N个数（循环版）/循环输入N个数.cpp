#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 5
#include<iostream>
#include<cstdio>
using namespace std;
void init(int *p,int index)
{
	for (int i = 0; i <= index;i++)
	{
		scanf("%d",p+i);
	}
}

void print(int *p,int index)
{
	for (int i = 0; i <= index;i++)
	{
		printf("%d ",*(p+i));
	}
}

int main()
{
	int array[MAX_SIZE];
	init(array, MAX_SIZE-1);
	print(array,MAX_SIZE-1);
	system("pause");
	return EXIT_SUCCESS;

}
