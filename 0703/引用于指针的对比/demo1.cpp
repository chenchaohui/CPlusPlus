#include<iostream>
using namespace std;

struct STest
{

	double &data;   //�ṹ���ڲ�����һ�����õ�����

};
int main()
{    
	//����
	int data = 5, obj = 3;
	int *p = &data, &r=data;
	cout << "*p=" << *p << ",data=" << data<<",obj="<<obj<< endl;
	p = &obj;
	cout << "*p=" << *p <<",data="<<data <<",obj="<< obj << endl;
	cout << "r=" << r<<",data="<<data << endl;
	r = obj;
	cout << "r=" << r << ",data=" << data << endl;
	
	//˵����

	//ָ�������õ�����
	/*
	(1)ָ���ָ������޸ģ�����Ϊnullptr�����ò����޸�ָ��,������Ϊ��(nullptr),һ������ͱ����ʼ��Ϊ���ڵ��ڴ�ʵ��
	(2)ָ��ı����ǽ���һ��ָ���ڴ�Ŀ�ݷ�ʽ�����õı�����һ����ָ�룬������ʽ��ȡָ����ָ������ݡ�
       ����˵��һ�³�ָ�룺int * const pdata ���� int &rdata�ȼ�
	*/


	//p = nullptr;            //��
	//int &rdata=nullptr      //��

	//������֤��һ�����õı�����һ����ָ��
	//��һ�������˵�δ����ĺ������������Ľṹ��

	cout << "sizeof(STest)=" <<sizeof(STest)<< endl; //����Ľ��Ϊ4��˵�����õ�����������һ��ָ�������
	system("pause");
	return EXIT_SUCCESS;
}