//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int add(int a, int b);
//
//int main()
//{
//	int i = 0;
//	int &b = i;
//	const int &a =8;
//
//	int a = add(1,2);
//	system("pause"); 
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Time
//{
//private:
//	int H;
//	int M;
//	int S;
//
//public:
//	/*Time(int h = 0, int m = 0, int s = 0) :H(h), M(m), S(s)
//	{
//
//	}*/
//	Time(int h = 0, int m = 0, int s = 0);
//	~Time();
//	void show()const;
//};
//Time::Time(int h, int m, int s) :H(h), M(m), S(s)
//{
//	cout << "call construction" << endl;
//}
//Time::~Time()
//{
//	cout << "call destruction" << endl;
//}
//void Time::show()const
//{
//	cout << H << "\t" << M << "\t" << S << endl;
//}
//int main()
//{
//	Time t(1, 2, 4);
//	t.show();
//	system("pause");
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//class String
//{
//private:
//	char *strValue;
//public:
//	String(char *s = "")
//	{
//		if (s==nullptr)
//		{
//			s = "";
//		}
//		strValue = new char[strlen(s) + 1];
//		strcpy(strValue,s);
//	}
//	String(const String &copy)
//	{
//		strValue = new char[strlen(copy.strValue) + 1];
//		strcpy(strValue, copy.strValue);
//	}
//	~String()
//	{
//		delete[]strValue;
//	}
//
//	void show()
//	{	
//		cout << strValue << endl;
//	}
//};
//int main()
//{
//  	String s1("test");
//	String s2(s1);
//	s1.show();
//	s2.show();
//	//system("pause");
//	return EXIT_SUCCESS;
//}