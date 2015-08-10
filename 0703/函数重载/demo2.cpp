#include<iostream>
#include<string>
using namespace std;
//函数重载：函数名称相同，参数列表的不同（参数列表不同表现为：参数个数，参数类型，不同类型参数的顺序）
//函数重载与函数的返回值无关，也就是说：函数名称相同，参数列表相同，只有返回值类型不同，这种情况不算函数重载，甚至还会报错
//.cpp文件中存在函数重载；.c文件中不存在函数重载
extern "C" void show()
{
	cout << "hello world !"<<endl;
}

void show(int a)
{
	cout << "hello world ! " << a << endl;

}

void show(string s)
{
	cout << s << endl;
}

void show(string s, int a)
{
	for (int i = 0; i < a;i++)
	{
		cout << s << endl;
	}
}

 void show(int a , string s)
{
	for (int i = 0; i < a; i++)
	{
		cout << s << endl;
	}
}


int main()
{
	show();
	show(2);
	show("你好世界");
	show("hello world ",2);
	show(2,"hello world");
	system("pause");
	return EXIT_SUCCESS;
}

//*注：在.cpp文件中可以用 extern "C" void show();将C++文件中的函数以C语言的方式进行编译
