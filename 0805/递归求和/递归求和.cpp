#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
using namespace std;

int Sum(int a, int i)                                  
{
	// �ݹ����
	if (i == 1)                                      //�������������Ϊ0����i��ʾʽ�мӺŵĸ���
		return a;                                    //�������������Ϊ1����i��ʾʽ���ж��ٸ���ʽ��
	else
	{
		int res = Sum(a, i - 1);                     //Ƕ�׵ݹ�
		return res * a + a;	                         // �ݹ��߼�������ʽ�����Լ�ѭ����
	}
/*
	Sum(a, 3) = Sum(a, 2) * a + a;
			  = (Sum(a, 1) * a + a) * a + a
			  = ((Sum(a, 0) * a + a) * a + a) * a + a
			  = ((a * a + a) * a + a) * a + a
			  = (a * a * a + a * a + a) * a + a
			  = a * a * a * a + a * a * a + a * a + a
*/
}

int main()
{
	int a, n;
	scanf("%d%d", &a, &n);
/*
	    for (i = 0; i < n; i++)
		sum = sum * a + a;
*/

	printf("sum = %d\n", Sum(a, n));
	system("pause");
	return 0;
}