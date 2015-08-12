#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
using namespace std;

int Sum(int a, int i)                                  
{
	// 递归出口
	if (i == 1)                                      //如果将出口设置为0，则i表示式中加号的个数
		return a;                                    //如果将出口设置为1，则i表示式中有多少个子式子
	else
	{
		int res = Sum(a, i - 1);                     //嵌套递归
		return res * a + a;	                         // 递归逻辑（递推式），以及循环体
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