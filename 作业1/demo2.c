#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getstr1str2(char *src,char *buf1,char *buf2)
{
	//Ϊ�˲��ı䴫�ݹ����Ĳ�����ֵ������Ϊ������������һ������
	//buf1���ڴ洢����Ϊ�ϵ��ַ���Ϣ��buf2���ڴ洢ż��Ϊ�ϵ���Ϣ��
	char *srcbak = src;
	char *buf1bak = buf1;
	char * buf2bak = buf2;
	size_t i;
	int ret = 0;
	if (src==NULL||buf1==NULL||buf2==NULL)
	{
		ret = -1;
		printf("getstr1str2:err %d",ret);
		return ret;
	}
	//����forѭ��ʵ����ĿҪ��
	//��Դ�ַ�������Ϊ���в���
	for (i = 0; i< strlen(srcbak);i+=2)
	{
		*buf1bak = srcbak[i];
		buf1bak++;
	}

	//���ַ�������ż��λ�ϵĲ���
	for (i = 1; i<strlen(srcbak);i+=2)
	{
		*buf2bak = srcbak[i];
		buf2bak++;
	}
	return 0;
}

int main32()
{
	char *src = "1a2b3d4z";
	char buf1[20] = { 0 };
	char buf2[20] = { 0 };
	int ret = 0;
	ret = getstr1str2(src, buf1, buf2);
	if (ret == -1)
	{
		printf("err:%d", ret);
	}
	else
		printf("��ϲ��,ִ�гɹ�!");
	printf("Դ�ַ���%s\n",src);
	printf("Դ�ַ�������λ�ϵ��ַ���ɵĴ�%s\n",buf1);
	printf("Դ�ַ���ż��λ�ϵ��ַ���ɵĴ�%s\n", buf2);
	system("pause");

}