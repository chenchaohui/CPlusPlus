//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<ctype.h>
//#include<memory.h>
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
//	memcpy(outbuf,inbuf+i,count);
//	outbuf[count] = '\0';
//}
//
//void main()
//{
//	char inbuf[120] = "    helloworld ";
//	char outbuf[20];
//	//char *p = (char *)malloc(20*sizeof(char));
//	//p = NULL;
//	trimSpace(inbuf, outbuf);
//	printf("%s", outbuf);
//	system("pause");
//
//}