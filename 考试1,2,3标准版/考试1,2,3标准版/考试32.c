
//������Ŀ���Լ�ʵ�ֵĲ��ִ��룬�о��������ǲ��а�

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<memory.h>
//
//struct _itAdvTeacher
//{
//	char	*name;
//	char	*tile;
//	int		age;
//	char	*addr;
//	//char	*p1; 
//	char	**p2;
//};
//
//int init(struct _itAdvTeacher *pt,int num)
//{
//	int ret = 0;
//	int i = 0;
//	int j = 0;
//	if (pt == NULL)
//	{
//		ret = -1;
//		printf("init Error:%d,%s",ret,"pt == NULL");
//		return ret;
//	}
//	for (i = 0; i < num;i++)
//	{
//		printf("�������%d����ʦ������:\n", i + 1);
//		pt[i].name = (char *)malloc(128 * sizeof(char));
//		scanf("%s", pt[i].name);
//		printf("���������%d����ʦ��ְ��:\n", i + 1);
//		pt[i].tile = (char *)malloc(128 * sizeof(char));
//		scanf("%s", pt[i].tile);
//		printf("���������%d����ʦ������:\n", i + 1);
//		scanf("%d", &pt[i].age);
//		printf("���������%d����ʦ�ĵ�ַ:\n", i + 1);
//		pt[i].addr = (char *)malloc(128 * sizeof(char));
//		scanf("%s", pt[i].addr);
//
//		//�������ڴ����ǵ��ͷ�
//		pt[i].p2 = (char **)malloc(3 * sizeof(char *));
//		memset(pt[i].p2, 0, 3 * sizeof(char *));
//		for (j = 0; j < 3;j++)
//		{
//			printf("�������%dΪ��ʦ�ĵ�%dΪѧ��������:\n",i+1,j+1);
//			pt[i].p2[j] = (char *)malloc(128*sizeof(char));		
//			scanf("%s",pt[i].p2[j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//
////int print()
////{
////
////
////}
//
////int sortTArray()
////{
////
////
////}
//
//int freeMemory( struct _itAdvTeacher **ppt,int num)
//{
//	int ret = 0;
//	if (ppt == NULL)
//	{
//		ret = -1;
//		printf("freeMemory Error %d %s",ret,"ppt == NULL");
//		return ret;
//	}
//	return 0;
//}
//
//int main()
//{
//	//����һ��ָ������
//	struct _itAdvTeacher advT[6];
//	init(advT, 6);
//	system("pause");
//	return EXIT_SUCCESS;
//}

//�����˼ҵı�׼����д�ĳ��򣬸��˸о��ǳ���

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define structArray_Size 3
#define student_Num 2

typedef struct _itAdvTeacher
{
	char	*name;
	char	*tile;
	int		age;
	char	*addr;
	char	**stuname;
}AdvTeacher;

//�ӿڵķ�װ����ƣ�������������ʱ�����ʡ���βε�����
int createStructArray(AdvTeacher **,int , int);
int printStructArray(AdvTeacher*,int ,int); 
int sortStructArray(AdvTeacher*, int);
int freeStructArray(AdvTeacher **,int ,int );


//��������
void main()
{
	int ret = 0;
	int i = 0,j = 0;
	AdvTeacher *pta = NULL;
	//�������������ڴ������������
	ret = createStructArray(&pta, structArray_Size, student_Num);
	if (ret == -1)
	{
		printf("createStructArray failed.\n");
		return;
	}
	for (i = 0; i < structArray_Size;i++)
	{
		printf("\n�������%dλ��ʦ������:",i+1);
		scanf("%s",pta[i].name);
		printf("\n�������%dλ��ʦ��ͷ��:", i + 1);
		scanf("%s", pta[i].tile);
		printf("\n�������%dλ��ʦ����:", i + 1);
		scanf("%d", &pta[i].age);
		for (j = 0; j < student_Num; j++)
		{
			printf("\n�������%dλ��ʦ�ĵ�%dλѧ��������:",i+1,j+1);
			scanf("%s",pta[i].stuname[j]);
		}
		printf("\n\n");
	}
	printf("����ǰ:\n");
	ret = printStructArray(pta, structArray_Size, student_Num);
	if (ret == -1)
	{
		printf("��ӡ�ṹ������ʧ��\n");
		return;
	}

	printf("\n\n�����:\n");

	ret = sortStructArray(pta, structArray_Size);
	if (ret == -1)
	{
		printf("�ṹ����������ʧ��\n");
		return;
	}

	ret = printStructArray(pta, structArray_Size, student_Num);
	if (ret == -1)
	{
		printf("��ӡ�ṹ������ʧ��\n");
		return;
	}
	ret = freeStructArray(&pta, structArray_Size, student_Num);
	if (ret == -1)
	{
		printf("�ͷ��ڴ�ʧ��\n");
		return;
	}
	system("pause");
}

 //�����ú��������ڴ棬˦���ڴ����������ʹ��
int createStructArray(AdvTeacher **pt, int num1, int num2)
{
	int i = 0, j = 0;
	int ret = 0;
	AdvTeacher *tmp = NULL;

	//ÿ�η������ڴ涼�����ж��ڴ��Ƿ����ɹ�
	tmp = (AdvTeacher *)malloc(num1*sizeof(AdvTeacher));
	if (pt == NULL)
	{
		ret = -1;
		printf("createStructArray Error:%d",ret);
		return ret;
	}
	if (tmp == NULL)
	{
		ret = -1;
		printf("createStructArray Error:%d", ret);
		return ret;
	}
	for (i = 0; i < num1;i++)
	{
		tmp[i].name = (char *)malloc(256 * sizeof(char));
		tmp[i].tile = (char *)malloc(256 * sizeof(char));
		tmp[i].addr = (char *)malloc(256 * sizeof(char));
		tmp[i].stuname = (char **)malloc(num2*sizeof(char *));
		if (tmp[i].name == NULL || tmp[i].tile == NULL || tmp[i].addr == NULL || tmp[i].stuname == NULL)
		{
			ret = -1;
			printf("createStructArray Error:%d", ret);
			return ret;
		}
		for (j = 0; j < num2; j++)
		{
			tmp[i].stuname[j] = (char *)malloc(256 * sizeof(char));
			if (tmp[i].stuname[j] == NULL)
			{
				ret = -1;
				printf("createStructArray Error:%d", ret);
				return ret;
			}
		}
	}
	*pt = tmp;
	return 0;
}

int printStructArray(AdvTeacher*pta, int num1, int num2)
{
	int ret = 0;
	int i = 0, j = 0;
	if (pta == NULL)
	{
		ret = -1;
		printf("printStructArray Error %d",ret);
		return ret;
	}
	for (i = 0; i < num1;i++)
	 {
		 printf("\n\n��%dλ��ʦ��������:%s",i+1,pta[i].name);
		 printf("\n\n��%dλ��ʦ��ͷ����:%s", i + 1, pta[i].tile);
		 printf("\n\n��%dλ��ʦ��������:%d", i + 1, pta[i].age);
		 for (j = 0; j < num2; j++)
		 {
			 printf("\n\n��%dλ��ʦ�ĵ�%dλѧ����������:%s", i + 1,j+1,pta[i].stuname[j]);
		 }
		
	 }

	return 0;
}

int sortStructArray(AdvTeacher*pta, int num1)
{
	int ret = 0;
	int i = 0;
	int j = 0;
	AdvTeacher tmp;
	if (pta == NULL)
	{
		ret = -1;
		printf("sortStructArray Error %d", ret);
		return ret;
	}
	//���ñȽ�����
	for (i = 0; i < num1;i++)
	{
		for (j = 0; j < num1;j++)
		{
			if (strcmp(pta[i].name,pta[j].name) > 0)
			{
				//���ñ�����Ĭ�ϵĸ�ֵ����
				tmp = pta[i];
				pta[i] = pta[j];
				pta[j] = tmp;
			}
		}
		
	}
	return 0;
}

//����Ա����ǵ�����mmalloc��̬�����ڴ��Ժ�Ҫ�ǵ��ͷţ�
int freeStructArray(AdvTeacher **pt,int num1,int num2)
{
	//�ǵ����ͷ��ڴ��ʱ��Ҫ���ڵ�������ͷ�
	int i = 0, j = 0;
	int ret = 0;
	AdvTeacher *p1 = *pt;
	if (pt == NULL)
	{
		ret = -1;
		printf("createStructArray Error:%d", ret);
		return ret;
	}
	for (i = 0; i < num1;i++)
	{
		if (p1[i].name != NULL)
		{
			free(p1[i].name);
		}
		if (p1[i].tile != NULL)
		{
			free(p1[i].tile);
		}
		if (p1[i].addr != NULL)
		{
			free(p1[i].addr);
		}
		if (p1[i].stuname != NULL)
		{
			for (j = 0; j < num2; j++)
			{
				if (p1[i].stuname[j] != NULL)
				{
					free(p1[i].stuname[j]);
				}
			}
		}
		if (p1[i].stuname != NULL)
		{
			free(p1[i].stuname);
		}
	}
	return 0;
}