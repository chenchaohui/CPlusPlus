#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findValueByKey(char src[][100],char *key,char *value1)
{
	char (*srcbak)[100]= src;   //������ط�������Ҫ�ر�ע�⣺  int *��p[10]��//��10��ָ�������ɵ����飬���ָ������
	char *keybak = key;                                       //int(*p)[10] //������������ָ��
	char *value1bak = value1;
	
	int ret = 0;
	int i;
	char *mark;
	if (src == NULL || key == NULL || value1 == NULL)
	{
		ret = -1;
		printf("func findValueByKey err:%d src == NULL || key == NULL || value1 == NULL",ret);
		return ret;
	}

	for (i = 0;i < 5; i++)
	{
		if ((mark = strstr(*(src+i),key)) !=NULL)
		{
			mark = mark + strlen(keybak);
			while (*mark!='\0')
			{
				if (*mark == '=')
				{
					mark++;
					continue;
				}
				else if (*mark == ' ')
				{
					mark++;
					continue;
				}
				else
				{
					*value1++ = *mark++;
				}	    
			}
		}
		*value1 = '\0';
	}
	return 0;
}


void main()
{
	char str[5][100] = {
		                 "key1       =      valude1",
		                 "key2      = valude2",
				         "key3      =      valude3   ",
						 "key4 =      valude4",
						 "key5=     "
                      	};

	char mykey[10] = { 0 };
	char value1[20] = { 0 };
	int ret = 0;
	scanf("%s",mykey);
	ret = findValueByKey(str,mykey,value1);
	if (ret!=-1)
	{
		printf("%s\n",value1);
	}
	system("pause");
}














//#define _CRT_SECURE_NO_WARNINGS
//#include"stdio.h"
//#include"stdlib.h"
//#include"string.h"
///*
//��ֵ�ԣ���key = valude�����ַ������ڿ����о���ʹ��
//Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡvalude��40��
//Ҫ��2����д����������30��
//Ҫ��3����ֵ���м������n��ո���ȥ���ո�30��
//ע�⣺��ֵ���ַ�����ʽ��������
//��key1 = valude1��
//��key2 =    valude2    "
//��key3       = valude3   "
//��key4   =   valude4��
//"key5=     "
//*/
//
///*
//˼·
//��һ��������һ���ַ�������;�����е����鱣���ȥ
//�ڶ�����������Ҫ��ȡvalude���ַ����飬�Լ��ڶ�һ��  key���ַ�����;
//������������һ�������õĺ�����
//*/
//char MyStr(char p[][100], char *key, char *valude)
//{
//	int ret = 1;
//	char *myp;
//	int i = 0;
//	if (p == NULL || key == NULL || valude == NULL)  //�жϴ����ĵ�ַ �Ƿ�Ϊ�գ�
//	{
//		ret = -1;
//		printf("func MyStr() err %d  (p == NULL || key == NULL || valude == NULL)", ret);
//		return ret;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		if ((myp = strstr(*(p + i), key)) != NULL)  //�ж�key�Ƿ�����һ���ַ����У��������NULL��������������������ִ��
//		{
//			myp = myp + strlen(key); //ָ�������ҵ����Ǹ��ַ������棡
//			while (*myp != '\0')
//			{
//				if (*myp == '=')
//				{
//					myp++;
//					continue;
//				}
//				else if (*myp == ' ')
//				{
//					myp++;
//					continue;
//				}
//				else
//				{
//					*valude++ = *myp++;
//				}
//				//myp����Ҫ�Ӽ�����Ϊ���ѭ�������жϣ�
//			}
//		}
//		*valude = '\0'; //���жϲ��ɹ���ʱ��  ��ĩβ���Ͻ������ţ�
//	}
//	return ret;
//}
//
//int main()
//{
//	char str[5][100] = {
//		"key1       =      valude1",
//		"key2      = valude2",
//		"key3      =      valude3   ",
//		"key4 =      valude4",
//		"key5=     "
//	};
//
//	char youkey[100];
//	char Value[100];
//	int rv = 0;
//	scanf("%s", &youkey);
//	rv = MyStr(str, youkey, Value);
//	if (rv != -1)
//	{
//		printf("%s", Value);
//	}
//	system("pause");
//}
