#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 20
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
//����Ҫ��ͨ��ѭ���ķ��������쳲��������е�ÿ���
//�������£�
//쳲����������ֽ����ƽ����С���f(x)=1 1 2 3 5 8 13����
//                              lim[f(x+1)/f(x)]=(sqrt(5)+1)/2Լ����0.618
                             // x->�����


int main1()
{
	int  num = 1;
	const double ratio = (sqrt(5) + 1.0) / 2.0;
	printf("%d %d ",num,num);
	for (int i = 3; i <= MAX_SIZE;i++)
	{
		num = static_cast<int>(num*ratio + 0.5);
		printf("%d ",num);
	}

	system("pause");
	return 0;
}