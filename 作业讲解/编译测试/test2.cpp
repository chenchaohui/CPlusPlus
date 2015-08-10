//#include<iostream>
//using namespace std;
//template<typename ElemType1, typename ElemType2>
//ElemType2 max(ElemType1 a, ElemType2 b)
//{
//	return a > b ? a : b;
//
//}
//int main()
//{
//	cout << max<int,double>(2, 3.0) << endl;
//
//	system("pause");
//	return EXIT_SUCCESS;
//}

//#include<iostream>
//using namespace std;
//template<typename ElemType>
//ElemType max(ElemType a, ElemType b)
//{
//	return a > b ? a : b;
//
//}
//int main()
//{
//	cout << max<int>(2, 3.0) << endl;
//
//	system("pause");
//	return EXIT_SUCCESS;
//}


//重载函数模板与匹配过程
//#include<iostream>
//using namespace std;
//template<typename ElemType>
//ElemType max(ElemType a, ElemType b)
//{
//	return a > b ? a : b;
//}
//
//char * max(char *str1, char *str2)
//{
//	return strcmp(str1,str2)<0?str2:str1;
//}
//int main()
//{
//	cout<<"2和4的较大值是:"<<max(2,4)<<endl;
//	cout << "China和America叫大的是:" << max("China", "America") << endl;
//	system("pause");
//	return EXIT_SUCCESS;
//}

//#include<iostream>
//#include<string>
//using namespace std;
////类模板实例化为模板类然后再定义一个对象（类型参数列表中包含常规参数，
////常规参数必须实例化为一个真正的常量）
//template<typename ElemType>
//class Array
//{
//private:
//	ElemType *elem;
//	int size;
//public:
//	Array(int sz):size(sz)
//	{
//		elem = new ElemType[size];
//	}
//	~Array()
//	{
//		delete[] elem;
//	}
//	void SetElem(ElemType e,int i);
//	ElemType GetElem(int i)const;
//};
//
//template<typename ElemType>
//void Array<ElemType>::SetElem(ElemType e, int i)
//{
//	if (i<0||i>=size)
//	{
//		cout << "元素位置错误" << endl;
//		exit(1);
//	}
//	elem[i] = e;
//}
//
//template<typename ElemType>
//ElemType Array<ElemType>::GetElem(int i)const
//{
//	if (i < 0 || i >= size)
//	{
//		cout << "元素位置错误" << endl;
//		exit(2);
//	}
//	return elem[i];
//}
//
//int main()
//{ 
//	int a[] = { 1, 3, 4, 6, 8, 9 };
//	int n = 6;
//	Array<int>obj(n);
//	for (int i = 0; i < n;i++)
//	{
//		obj.SetElem(a[i], i);
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		cout << obj.GetElem(i) << endl;
//	}
//	system("pause");
//	return EXIT_SUCCESS;
//}


//#include<iostream>
//#include<string>
//using namespace std;
////类模板实例化为模板类然后再定义一个对象（类型参数列表中包含常规参数，
////常规参数必须实例化为一个真正的常量）
//template<typename ElemType,int size>
//class Array
//{
//private:
//	ElemType elem[size];
//public:	
//	void SetElem(ElemType e,int i);
//	ElemType GetElem(int i)const;
//};
//
//template<typename ElemType,int size>
//void Array<ElemType,size>::SetElem(ElemType e, int i)
//{
//	if (i<0||i>=size)
//	{
//		cout << "元素位置错误" << endl;
//		exit(1);
//	}
//	elem[i] = e;
//}
//
//template<typename ElemType,int size>
//ElemType Array<ElemType,size>::GetElem(int i)const
//{
//	if (i < 0 || i >= size)
//	{
//		cout << "元素位置错误" << endl;
//		exit(2);
//	}
//	return elem[i];
//}
//
//int main()
//{ 
//	int a[] = { 1, 3, 4, 6, 8, 9 };
//	const int n = 6;
//	Array<int,n>obj;
//	for (int i = 0; i < n;i++)
//	{
//		obj.SetElem(a[i], i);
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		cout << obj.GetElem(i) << endl;
//	}
//	system("pause");
//	return EXIT_SUCCESS;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//class person
//{
//public:
//	void show()
//	{
//		cout << "调用了show函数" << endl;
//	}
//};
//
//int main()
//{
//	person p;
//	p.show();
//	person *pp = new person;
//	pp->show();
//	system("pause");
//	return EXIT_SUCCESS;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//
//template<typename ElemType>  //类模板
//class person
//{
//private:
//	ElemType m_value;
//public:
//	person(ElemType v) :m_value(v)
//	{
//	}
//	person(const person<ElemType>&obj)              //类模板中构造函数形参表中对对象引用的声明
//	{
//		m_value = obj.m_value;
//	}
//	void show(const person<ElemType>&obj);         //类模板中成员函数形参表中对对象引用的声明
//	template<typename ElemType>                    //类模板中友元函数的声明，以及友元函数形参表中对对象引用的声明。
//	friend void showA(const person<ElemType>&obj);	
//};
//
//template<typename ElemType>
//void person<ElemType>::show(const person<ElemType>&obj)
//{
//	cout << "call function show" << endl;
//}
//
//template<typename ElemType>
//void showA(const person<ElemType>&obj)
//{
//	cout << "call 友元函数" << endl;
//}
//
//int main()
//{
//	person<int> p(1);
//	//person<int>pp(p);
//	p.show(p);
//	showA(p);
//	system("pause");
//	return EXIT_SUCCESS;
//}





#include<iostream>
#include<string>
using namespace std;
class Complex
{
private:
	double real;
	double image;
public:
	Complex(double r = 0, double i = 0) :real(r), image(i){}
	void show()const;
	static Complex add(const Complex &z1,const Complex &z2);

};

void Complex::show()const
{
	if (image < 0)
	{
		cout << real << image << "i" << endl;
	}
	else if (image == 0)
	{
		cout << real << endl;
	}
	if (image > 0)
	{
		cout << real << "+" << image << "i" << endl;
	}
}

Complex Complex::add(const Complex &z1, const Complex &z2)
{
	//double a = real + image;                                     //非静态数据成员的引用必须与特定的对象相对应。
	return Complex(z1.real+z2.real,z1.image+z2.image);
}

int main()
{
	Complex z1(1,2);
	Complex z2(3,4);
	Complex z3 = Complex::add(z1, z2);
	z3.show();
	system("pause");
	return EXIT_SUCCESS;;
}