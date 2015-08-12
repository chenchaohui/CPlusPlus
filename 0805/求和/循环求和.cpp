#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
using namespace std;

// 算式做了：(n-1) 次加法，n*(n-1)/2 次乘法
// Sn = a + a * a + a * a * a + ... + a * a * ... * a;	// n 个项
//    = a(1 + a + a * a + a * a * a + ... + a * a * ... * a)
//    = a(1 + a(1 + a + a * a + ... + a * a * ... * a))
// 如果 n = 5，那么：
// Sn = a + a * a + a * a * a + a * a * a * a + a * a * a * a * a
//    = a(1 + a + a * a + a * a * a + a * a * a * a)
//    = a(1 + a(1 + a + a * a + a * a * a))
//    = a(1 + a(1 + a(1 + a + a * a)))
//    = ...
//    = a(1 + a(1 + a(1 + a(1 + a))))      //总结就是前面的和乘以a在加上a就是总的和
int main()
{
	int i, j, a, n, sum = 0, mul;
	scanf("%d%d", &a, &n);
	/*for (i = 0; i < n; i++)
		sum = sum * a + a;*/

	sum = 0;
	for (i = 0; i < n; i++)
	{
		mul = 1;			                              // 每次内循环之前就将mul初始化为1
		for (j = 0; j <= i; j++)
			mul = mul * a;
		sum = sum + mul;
	}

	printf("sum = %d\n", sum);
	system("pause");
	return 0;
}
