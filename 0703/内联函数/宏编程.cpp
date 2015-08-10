#include<iostream>
#include<cstdio>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b)) 
int main()
{

	int a = 1, b = 0;
	//cout << MAX(a++, b);                  //运算的结果为2，a的值变成了3。等价的形式是（（a++）>(b)?(a++):(b)）
	cout << MAX(a++, b + 10);              //运算的结果为10，a的值变成了2，因为后面的一个a++没有执行。等价的形式为（（a++）>(b+10)?(a++):(b+10)）
	cout << endl;
	cout << "a=" << a;
	system("pause");
	return EXIT_SUCCESS;
}