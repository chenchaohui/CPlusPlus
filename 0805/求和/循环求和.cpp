#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
using namespace std;

// ��ʽ���ˣ�(n-1) �μӷ���n*(n-1)/2 �γ˷�
// Sn = a + a * a + a * a * a + ... + a * a * ... * a;	// n ����
//    = a(1 + a + a * a + a * a * a + ... + a * a * ... * a)
//    = a(1 + a(1 + a + a * a + ... + a * a * ... * a))
// ��� n = 5����ô��
// Sn = a + a * a + a * a * a + a * a * a * a + a * a * a * a * a
//    = a(1 + a + a * a + a * a * a + a * a * a * a)
//    = a(1 + a(1 + a + a * a + a * a * a))
//    = a(1 + a(1 + a(1 + a + a * a)))
//    = ...
//    = a(1 + a(1 + a(1 + a(1 + a))))      //�ܽ����ǰ��ĺͳ���a�ڼ���a�����ܵĺ�
int main()
{
	int i, j, a, n, sum = 0, mul;
	scanf("%d%d", &a, &n);
	/*for (i = 0; i < n; i++)
		sum = sum * a + a;*/

	sum = 0;
	for (i = 0; i < n; i++)
	{
		mul = 1;			                              // ÿ����ѭ��֮ǰ�ͽ�mul��ʼ��Ϊ1
		for (j = 0; j <= i; j++)
			mul = mul * a;
		sum = sum + mul;
	}

	printf("sum = %d\n", sum);
	system("pause");
	return 0;
}
