#include<iostream>
#include<cstdio>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b)) 
int main()
{

	int a = 1, b = 0;
	//cout << MAX(a++, b);                  //����Ľ��Ϊ2��a��ֵ�����3���ȼ۵���ʽ�ǣ���a++��>(b)?(a++):(b)��
	cout << MAX(a++, b + 10);              //����Ľ��Ϊ10��a��ֵ�����2����Ϊ�����һ��a++û��ִ�С��ȼ۵���ʽΪ����a++��>(b+10)?(a++):(b+10)��
	cout << endl;
	cout << "a=" << a;
	system("pause");
	return EXIT_SUCCESS;
}