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
//		init(p, index--);                   //index��ֵһֱû�з����仯�����Գ�������ջ��������
//		scanf("%d",&p[index]);             //Ϊʲôindex��ֵһֱû�з����仯����Ϊÿ���ж�ʱindex��ֵ����ִ����һ��init(p,index--)�����ٷ����仯�ģ�����������һֱ����������û��ִ����ȫ�����index��ֵһֱû�з����仯��
//	}
//	
//}

//void init(int *p,int index)                //���ָ÷�Ҳ�Ǵ����
//{                                          //��Ϊindex��ֵ�ǲ��ܷ����仯��
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