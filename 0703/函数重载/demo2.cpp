#include<iostream>
#include<string>
using namespace std;
//�������أ�����������ͬ�������б�Ĳ�ͬ�������б�ͬ����Ϊ�������������������ͣ���ͬ���Ͳ�����˳��
//���������뺯���ķ���ֵ�޹أ�Ҳ����˵������������ͬ�������б���ͬ��ֻ�з���ֵ���Ͳ�ͬ������������㺯�����أ��������ᱨ��
//.cpp�ļ��д��ں������أ�.c�ļ��в����ں�������
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
	show("�������");
	show("hello world ",2);
	show(2,"hello world");
	system("pause");
	return EXIT_SUCCESS;
}

//*ע����.cpp�ļ��п����� extern "C" void show();��C++�ļ��еĺ�����C���Եķ�ʽ���б���
