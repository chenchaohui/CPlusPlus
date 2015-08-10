#include<iostream>
using namespace std;

struct STest
{

	double &data;   //结构体内部含有一个引用的声明

};
int main()
{    
	//测试
	int data = 5, obj = 3;
	int *p = &data, &r=data;
	cout << "*p=" << *p << ",data=" << data<<",obj="<<obj<< endl;
	p = &obj;
	cout << "*p=" << *p <<",data="<<data <<",obj="<< obj << endl;
	cout << "r=" << r<<",data="<<data << endl;
	r = obj;
	cout << "r=" << r << ",data=" << data << endl;
	
	//说明：

	//指针与引用的区别
	/*
	(1)指针的指向可以修改，可以为nullptr，引用不能修改指向,不可以为空(nullptr),一经定义就必须初始化为存在的内存实体
	(2)指针的本质是建立一个指向内存的快捷方式，引用的本质是一个常指针，表现形式是取指针所指向的内容。
       这里说明一下常指针：int * const pdata 它与 int &rdata等价
	*/


	//p = nullptr;            //对
	//int &rdata=nullptr      //错

	//在这里证明一下引用的本质是一个常指针
	//用一个声明了但未定义的含有引用声明的结构体

	cout << "sizeof(STest)=" <<sizeof(STest)<< endl; //输出的结果为4，说明引用的声明本质是一个指针的声明
	system("pause");
	return EXIT_SUCCESS;
}