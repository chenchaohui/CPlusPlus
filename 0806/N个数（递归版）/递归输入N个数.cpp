#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 5
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
//void init(int *p, int index)
//{
//	if (!index)
//	{
//		scanf("%d",&p[index]);
//	}
//	else
//	{
//		init(p, index--);                   //index的值一直没有发生变化，所以程序会出现栈溢出的情况
//		scanf("%d",&p[index]);             //为什么index的值一直没有发生变化，因为每次判断时index的值是在执行完一个init(p,index--)语句后再发生变化的，但是这个语句一直被挂在那里没有执行完全，因此index的值一直没有发生变化。
//	}
//	
//}

//void init(int *p,int index)                //这种该法也是错误的
//{                                          //因为index的值是不能发生变化的
//	if (!index)
//	{
//		scanf("%d",&p[index]);
//	}
//	else
//	{
//		init(p,--index);
//		scanf("%d",&p[index]);
//	}
//}

void init(int *p,int index)
{
  if (!index)
  {
	  scanf("%d",&p[index]);
  }
  else
  {
	  init(p,index-1);
	  scanf("%d",&p[index]);
  }
}

void print(int *p, int index)
{
	if (!index)
	{
		printf("%d ",p[index]);
	}
	else
	{
		print(p,index-1);
		printf("%d ",p[index]);
	}
}

int main()
{

	int array[MAX_SIZE];
	init(array,MAX_SIZE-1);
	print(array,MAX_SIZE-1);
	system("pause");
	return EXIT_SUCCESS;

}