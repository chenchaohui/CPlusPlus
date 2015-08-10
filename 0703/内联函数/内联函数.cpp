//#include<iostream>
//#include<string>
//using namespace std;
////函数参数的运算顺序是：从右到左
///*
//   递归函数调用不可以是内联，递归不允许展开。
//   调试阶段内联失效，全部被当做普通函数，也就是说内联函数起作用的模式是release模式。
//   内联函数内部代码量尽量短小不可以超过一定的cpu指令周期数，也就是大概20行简单的C语言语句
//   函数内部不要有较为复杂的选择结构，选择结构的展开牺牲空间远大于时间优化的增益
//*/
//
//void show(int a, int b)
//{
//	cout << a << endl;
//	cout << b << endl;
//}
//int main1()
//{ 
//	//int a = 2;
//	show(a, a++);
//
//	system("pause");
//	return EXIT_SUCCESS;
//}
//
//inline int add(int a,int b)
//{
//	return a + b;
//}
//
//
//
//int main()
//{
//	int a, b, res;
//
//	cin >> a >> b;
//	res = add(a, b);
//	cout << res << endl;
//	system("pause");
//	return EXIT_SUCCESS;
//}
//
