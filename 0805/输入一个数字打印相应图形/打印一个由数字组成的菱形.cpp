#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include <cmath>
using namespace std;

/*
	// n = 5 ʱ��
	    1
	   121
	  12321
	 1234321
	123454321
	 1234321
	  12321
	   121
	    1

	���ɣ���ԳƵ�ͼ�Σ�����ֵ������Ӧ��
	|x| ����ѧ���壺x ��������ԭ�� 0 �ĳ��ȣ�|x| = |x - 0|
	�ϰ벿�֣����ٱ�࣬��С�����°벿�֣��ɶ���٣��ɴ��С��
	�κ�һ�У��ȴ�ӡ�ո��ٴ�ӡ���ݣ�����ӡ�س�
	�� N �У��ϰ벿�ֿո���� N - i���ϰ벿�������� 1~N���ٴ� N-1~1������ֻ�� 1 ��
	�� N ���ܽ᣺5 - |N-5|��ÿ�д�ӡ (2N - 1) ����N - |j - N|
*/
int main()
{
	// ����һ����άͼ�Σ����ѭ������ i ��ʾ�б꣬�ڲ�ѭ������ j ��ʾ�б�
	int i, j, n;
	scanf("%d", &n);
	for (i = 1; i < 2 * n; i++)
	{
		// �ȴ�ӡ�ո�
		for (j = n - abs(i - n); j < n; j++)
			printf(" ");

		// �ٴ�ӡ����
		for (j = 1; j < 2 * (n - abs(i - n)); j++)
			printf("%d", n - abs(i - n) - abs(j - (n - abs(i - n))));

		// ����ӡ 1 ������
		printf("\n");
	}
	system("pause");
	return 0;
}
