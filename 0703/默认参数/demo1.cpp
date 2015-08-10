#include<iostream>
#include<string>
using namespace std;
/*
函数的默认参数：
在定义一个函数的时候，可以在参数列表的最后一个位置设定一个默认的参数，
该函数在被调用时候若最后一个参数位置没有传递新的参数，则系统条用默认
参数。
  *注意：默认参数只能放在参数列表的最后一个位置

 */
//void show(int a, string s = "hello world !"); //函数的声明

void show(int a, string s = "hello world !")
{
	for (int i = 0; i < a; i++)
	{
		cout << s << endl;
	}

}
//带默认参数的函数如果先声明，再定义会出现参数重定义错误
void print()
{
	cout << "你好世界\n";
}

void print(string s = "我 哎 你")
{
	cout << s << endl;

}

int main()
{ 
	//print();//存在语意的二意性，编译器不知道是是调用默认参数的函数还是调用没有参数的函数
	show(3);
	show(2,"I Love You!");
	system("pause");
	return EXIT_SUCCESS;
}
