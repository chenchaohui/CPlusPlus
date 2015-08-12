#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int feibo(int n)
{
	if (n==1||n==2)
	{
		return 1;
	}
	return feibo(n - 1) + feibo(n - 2);
}

int main()
{
	printf("%d\n", feibo(3));
	printf("%d\n",feibo(4));
	system("pause");
	return EXIT_SUCCESS;
}