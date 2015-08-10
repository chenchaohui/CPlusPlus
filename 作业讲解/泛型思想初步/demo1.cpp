#include<iostream>
#include<string>
using namespace std;


int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

string add(string a, string b)
{
	return a + b;
}

#define ADD(num1,num2)\
	num1+num2
enum Etype
{
	TYPE_INT,
	TYPE_DOUBLE,
	TYPE_STRING
};
int main()
{
	int type;
	cout << "请您输入操作数的数据类型( 0:TYPE_INT,1:TYPE_DOUBLE,2:TYPE_STRING)";
	cin >> type;
	/*switch (type)
	{
	case TYPE_INT:
	{
	int a, b;
	cin >> a >> b;
	cout << add(a, b) << endl;
	}
	break;
	case TYPE_DOUBLE:
	{
	double a, b;
	cin >> a >> b;
	cout << add(a, b) << endl;
	}
	break;
	case TYPE_STRING:
	{
	string a, b;
	cin >> a >> b;
	cout << add(a, b) << endl;
	}
	break;
	}*/

	switch (type)
	{
	case TYPE_INT:
	{
		int a, b;
		cin >> a >> b;
		cout << ADD(a, b) << endl;
	}
	break;
	case TYPE_DOUBLE:
	{
		double a, b;
		cin >> a >> b;
		cout << ADD(a, b) << endl;
	}
	break;
	case TYPE_STRING:
	{
		string a, b;
		cin >> a >> b;
		cout << ADD(a, b) << endl;
	}
	break;
	}
	system("pause");
	return EXIT_SUCCESS;
}

