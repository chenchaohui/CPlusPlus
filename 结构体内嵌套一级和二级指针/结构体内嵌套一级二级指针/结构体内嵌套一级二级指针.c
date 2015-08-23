#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

struct AdvTeacher
{
	char name[128];
	char *a_name;               
	int age;
	char **stuname;
};

//�����ú��������ڴ�
//�����ṹ������
//������������ѵ�
struct AdvTeacher * creatTArray(int count)
{
	int i = 0;
	struct AdvTeacher *p = (struct AdvTeacher *)malloc(count*sizeof(struct  AdvTeacher));
	if (p==NULL)
	{
		printf("struct AdvTeacher * creatTArray Err:�����ڴ�ʧ��\n");
		return NULL;
	}
	//
	for (i = 0; i < count;i++)
	{
		//�������ڴ��Ժ󣬽��ڴ��е�����ȫ����Ϊ0
		memset(p+i,0,sizeof(struct AdvTeacher));
		//memset(&p[i],0,sizeof(struct AdvTeacher))
		p[i].a_name = (char *)malloc(128*sizeof(char));

		if (p[i].a_name==NULL)
		{
			printf("err:�����ڴ�ռ�ʧ�ܣ�\n");
			return NULL;
		}
		//�������ڴ��Ժ󣬽��ڴ��е�����ȫ����Ϊ0
		memset(p[i].a_name, 0, 128 * sizeof(char));
		{
			int  j = 0;
			char **p2 = (char**)malloc(3 * sizeof(char *));
			for (j = 0; j < 3;j++)
			{
				p2[j] = (char*)malloc(128 * sizeof(char));
				//�������ڴ��Ժ�����Ϊ0
				memset(p2[j],0,128*sizeof(char));
			}	
			p[i].stuname = p2;
		}
	}
	return p;
}

//��ӡ����
void printTArray(struct AdvTeacher *tArray, int num)
{
	int i = 0, j = 0;
	if (tArray == NULL || num <= 0)
	{
		printf("�������ʹ���\n");
		return;
	}
	for (i = 0; i < num;i++)
	{
		printf("name:%s\n",tArray[i].name);
		printf("a_name:%s\n",tArray[i].a_name);
		printf("age:%d\n",tArray[i].age);
		for (j = 0; j < 3;j++)
		{
			char **p = tArray[i].stuname;  
			//printf("stuname%d:%s\n",j,tArray[i].stuname[j]);
			printf("stuname%d:%s\n", j, p[j]);                       //����һ�е��Ż��棬��������
		}
		printf("\n\n");
	}
}

//���ṹ�����ͱ������ճ�Ա�����䣩������
void sorttArray(struct AdvTeacher* tArray, int num)
{
	//����ѡ�������㷨�Խṹ�����ͱ�����������:С-����
	int i = 0, j = 0;
	struct AdvTeacher tmp;                          //����һ����ʱ�ṹ�����ͱ���
	if (tArray==NULL||num<=0)
	{
		printf("�������ʹ���\n");
		return;
	}
	for (i = 0; i < num;i++)
	{                                               //ע��<,>�����ֻ�ܶԻ����������ͽ������㣬��C++�п���ͨ��������������������Զ������ͽ��бȽ�����
		for (j = i + 1; j < num; j++)
		{
			if (tArray[i].age>tArray[j].age)
			{
				tmp = tArray[i];
				tArray[i] = tArray[j];
				tArray[j] = tmp;
			}
		}
	}
}


void free2p(char **p, int num)
{
	int i = 0;
	if (p==NULL)
	{
		return;
	}

	for (i = 0; i < num;i++)
	{
		if (p[i]!=NULL)
		{
			free(p[i]);
		}
	}

	if (p!=NULL)
	{
		free(p);
	}


}

void freetArray(struct AdvTeacher* tArray, int num)
{
	int i = 0;
	if (tArray == NULL || num <= 0)
	{
		printf("�������ʹ���\n");
		return;
	}
	for (i = 0; i < num;i++)
	{
		char *p = tArray[i].a_name;
		if (p!=NULL)
		{
			free(p);
		}

		char**p1 = tArray[i].stuname;
		if (p1!=NULL)
		{
			free2p(p1,3);
		}	
	}
	if (tArray!=NULL)
	{
		free(tArray);
	}
}

void main()
{
	int i = 0, j = 0;
	struct AdvTeacher *p = creatTArray(2);
	if (p==NULL)
	{
		printf("�����ṹ��ʧ��!\n");
		return;
	}
		for (i = 0; i < 2;i++)
		{
			printf("\n����������:");
			scanf("%s",p[i].name);
			printf("\n���������:");
			scanf("%s", p[i].a_name);
			printf("\n����������:");
			scanf("%d",&p[i].age);              //ע������ط���ȡ��ַ����&���ܶ�ѽ������
			printf("\n������ѧ������:");
				for (j = 0; j < 3;j++)
				{
					scanf("%s",p[i].stuname[j]);
				}
		}

     //����ǰ
		printf("����ǰ:\n");
		printTArray(p, 2);
     //�����
		printf("�����:\n");
		sorttArray(p, 2);
		printTArray(p, 2);
	     if (p!=NULL)
	     {
			 freetArray(p, 2);
	     }
		 p = NULL;
	system("pause");
} 