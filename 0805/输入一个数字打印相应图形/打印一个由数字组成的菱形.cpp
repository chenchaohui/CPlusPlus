#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include <cmath>
using namespace std;

/*
	// n = 5 时：
	    1
	   121
	  12321
	 1234321
	123454321
	 1234321
	  12321
	   121
	    1

	规律：轴对称的图形，绝对值和它对应。
	|x| 的数学意义：x 距离数轴原点 0 的长度，|x| = |x - 0|
	上半部分，由少变多，由小增大；下半部分，由多变少，由大变小！
	任何一行：先打印空格，再打印内容，最后打印回车
	第 N 行：上半部分空格个数 N - i，上半部分内容是 1~N，再从 N-1~1，换行只有 1 个
	第 N 行总结：5 - |N-5|，每行打印 (2N - 1) 个，N - |j - N|
*/
int main()
{
	// 任意一个二维图形，外层循环变量 i 表示行标，内层循环变量 j 表示列标
	int i, j, n;
	scanf("%d", &n);
	for (i = 1; i < 2 * n; i++)
	{
		// 先打印空格
		for (j = n - abs(i - n); j < n; j++)
			printf(" ");

		// 再打印内容
		for (j = 1; j < 2 * (n - abs(i - n)); j++)
			printf("%d", n - abs(i - n) - abs(j - (n - abs(i - n))));

		// 最后打印 1 个换行
		printf("\n");
	}
	system("pause");
	return 0;
}
