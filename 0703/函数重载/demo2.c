//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
////函数重载：函数名称相同，参数列表的不同（参数列表不同表现为：参数个数，参数类型，不同类型参数的顺序）
////函数重载与函数的返回值无关，也就是说：函数名称相同，参数列表相同，只有返回值类型不同，这种情况不算函数重载，甚至还会报错
////.cpp文件中存在函数重载；.c文件中不存在函数重载
////void show()
////{
////	printf("hello world\n");
////}
//
////void show(int a)
////{
////	printf("hello world %d",a);
////
////}
//
//int main1()
//{
//	//show();
//	//show(2);	
//	system("pause");
//	return EXIT_SUCCESS;
//}
//
////该程序的测试说明：c语言中不存在函数重载，因为函数的参数不参与程序的编译
////所报的错误是：错误	1	error C2084: 函数“void show()”已有主体	