#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 3, b = 5;
	int *pa = &a;
	int *&rpa = pa;                                        //定义指针rp为指针p的引用
	int ** const ppa = &pa;                                //将指针引用的语法转化为指向指针的(指针)语法
	cout << "a=" << a << ",b=" << b << endl;
	cout << "&a=" << static_cast<void*>(&a) << ",&b=" << static_cast<void*>(&b) << endl;
	cout << "*pa=" << *pa << ",*rpa=" << *rpa << endl;
	cout << "pa=" << static_cast<void *>(pa) << ",rpa=" <<static_cast<void *>(rpa) << endl;
	*rpa = 8;                                              //通过指向a的指针的引用改变变量a的值
	cout << "a=" << a << endl;
	cout <<"-------------------"<< endl;
	rpa = &b;              
	cout << "a=" << a << ",b=" << b << endl;
	cout << "&a=" << static_cast<void*>(&a) << ",&b=" << static_cast<void*>(&b) << endl;
	cout << "*p=" << *pa << ",*rpa=" << *rpa << endl;
	cout << "pa=" << static_cast<void *>(pa) << ",rpa=" << static_cast<void *>(rpa) << endl;
	*rpa = 9;
	cout << "b=" << b << endl;
	cout << "-------------------" << endl;
	
	//得到的结论是：凡是能够用引用解决的问题都可以选择用指针的方式解决


	system("pause");
	return EXIT_SUCCESS;
}
