#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 3, b = 5;
	int *pa = &a;
	int *&rpa = pa;                                        //����ָ��rpΪָ��p������
	int ** const ppa = &pa;                                //��ָ�����õ��﷨ת��Ϊָ��ָ���(ָ��)�﷨
	cout << "a=" << a << ",b=" << b << endl;
	cout << "&a=" << static_cast<void*>(&a) << ",&b=" << static_cast<void*>(&b) << endl;
	cout << "*pa=" << *pa << ",*rpa=" << *rpa << endl;
	cout << "pa=" << static_cast<void *>(pa) << ",rpa=" <<static_cast<void *>(rpa) << endl;
	*rpa = 8;                                              //ͨ��ָ��a��ָ������øı����a��ֵ
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
	
	//�õ��Ľ����ǣ������ܹ������ý�������ⶼ����ѡ����ָ��ķ�ʽ���


	system("pause");
	return EXIT_SUCCESS;
}
