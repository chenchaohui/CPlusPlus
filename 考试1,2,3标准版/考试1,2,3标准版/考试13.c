//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<memory.h>
//#include<ctype.h>
//
////��ͷ��ģ��
////һ������²�Ҫ�޸�������ڴ���ֵ
// void trimSpace(char *inbuf,char *outbuf)
//{
//	//�������Լ���Ҫ�ر�ע��sizeof��strlen���÷�����
//	//sizeof��Ҫ���������ͺͱ����Ĵ�С��strlen��Ҫ������ָ��ָ����ڴ�ռ���ַ����Ĵ�С
//	int i = 0;
//	int j = strlen(inbuf) - 1;
//	int count = 0;
//	char *p = NULL;
//	p = inbuf;
//	if (inbuf==NULL||outbuf==NULL)
//	{
//		printf("trimSpace error:%s", "inbuf == NULL || outbuf == NULL");
//	}
//	while (isspace(p[i]))
//	{
//		i++;
//	}
//	while (isspace(p[j]))
//	{
//		j--;
//	}
//	count = j - i + 1;
//	//��ؼ���һ��
//	memcpy(outbuf,inbuf+i,count);
//	outbuf[count] = '\0';
//}
// //ͨ������ȡֵ
//int getValueByKey(char (*src)[128],char *key,char *keyvalue,int num)
//{
//	int ret = -1;
//	char *p = NULL;
//	if (src==NULL||key==NULL||keyvalue==NULL)
//	{
//		printf("getValueByKey Error:%d", ret);
//		return ret;
//	}
//	//��һ������keyֵ
//	for (int i = 0; i < num; i++)
//	{
//		p = strstr(src[i], key);	
//		if (p!=NULL)
//		{
//			break;
//		}
//	}
//	if (p == NULL)
//	{
//		printf("�Ҳ�����Ӧ��keyֵ\n");
//		return ret;
//	}
//	p = p + strlen(key);
//	//�ڶ������ҵȺ�
//	p = strchr(p, '=');
//	if (p == NULL)
//	{
//		printf("��=���޷����ɼ�ֵ��\n");
//		return ret;
//	}
//	p = p + 1;
//	//��������ȥ�ո�
//	trimSpace(p, keyvalue);
//	printf("%s\n", keyvalue);
//	return 0;
//}
//
//
//void main()
//{
//	char src[4][128] = {
//		"key1 =value1",
//		"key2   =value2    ",
//		"key3=value3       ",
//		"key4    =  value4 "
//	};
//	int ret = 0;
//	char key[128] = { 0 };
//	char keyValue[128] = { 0 };
//	int i = 0;
//	scanf("%s",key);
//	getValueByKey(src,key,keyValue,4);
//	system("pause");
//}