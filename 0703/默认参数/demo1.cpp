#include<iostream>
#include<string>
using namespace std;
/*
������Ĭ�ϲ�����
�ڶ���һ��������ʱ�򣬿����ڲ����б�����һ��λ���趨һ��Ĭ�ϵĲ�����
�ú����ڱ�����ʱ�������һ������λ��û�д����µĲ�������ϵͳ����Ĭ��
������
  *ע�⣺Ĭ�ϲ���ֻ�ܷ��ڲ����б�����һ��λ��

 */
//void show(int a, string s = "hello world !"); //����������

void show(int a, string s = "hello world !")
{
	for (int i = 0; i < a; i++)
	{
		cout << s << endl;
	}

}
//��Ĭ�ϲ����ĺ���������������ٶ������ֲ����ض������
void print()
{
	cout << "�������\n";
}

void print(string s = "�� �� ��")
{
	cout << s << endl;

}

int main()
{ 
	//print();//��������Ķ����ԣ���������֪�����ǵ���Ĭ�ϲ����ĺ������ǵ���û�в����ĺ���
	show(3);
	show(2,"I Love You!");
	system("pause");
	return EXIT_SUCCESS;
}
