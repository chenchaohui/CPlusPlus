//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int getStr1Str2(char *src,char *str1,char *str2)
//{
//	int ret = 0;
//	int i = 0, j = 0;
//	int len = strlen(src);
//	char *p = src;
//	if (src==NULL||str1==NULL||str2==NULL)
//	{
//		ret = -1;
//		printf("getStr1Str2 error: %d",ret);
//		return ret;
//	}
//	//ȡ����λ���ϵ��ַ��ŵ�str1ָ����ڴ�ռ���
//	for (i = 0; i < len;i+=2)
//	{
//		*str1 = p[i];
//		str1++;
//		
//	}
//	*str1 = '\0';	
//	//ȡż��λ���ϵ��ַ��ŵ�str2ָ����ڴ�ռ���
//	for (j = 1; j < len;j+=2)
//	{
//		*str2 = p[j];
//		str2++;
//	}
//	*str2 = '\0';
//	return 0;
//}
//
//
//int main()
//{
//	char src[128] = "1w2e3r4t5y6u7i";
//	char str1[128];
//	char str2[128];
//	int ret = 0;
//	ret = getStr1Str2(src, str1, str2);
//	if (ret==-1)
//	{
//		printf("��ȡ�ַ���ʧ��!\n");
//		return ret;
//	}
//	printf("%s\n",str1);
//	printf("%s\n",str2);
//	
//	system("pause");
//}