#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

struct AdvAdvTeacher
{

	char name[30];
	char *a_name;
	int age;
};

struct AdvAdvTeacher *CreatTArray(int count)
{
	int i = 0;
	struct AdvAdvTeacher *p1 = (struct AdvAdvTeacher *) malloc(count*sizeof(struct AdvAdvTeacher));
	if (p1==NULL)
	{
		return NULL;
	}
	for (i = 0; i < count;i++)
	{
		memset(&p1[i], 0, sizeof(struct AdvAdvTeacher));
		p1[i].a_name = (char *)malloc(128 * sizeof(char));
		memset(p1[i].a_name, 0, 128 * sizeof(char));
	}
	return p1;
}

void  freeTArray(struct AdvAdvTeacher *tArray,int num)
{
	int i = 0;
	if (tArray==NULL)
	{
		return;
	}
	for (i = 0; i < num;i++)
	{
		char *p = tArray[i].a_name;
		if (p!=NULL)
		{
			free(p);
		}
	}
	if (tArray!=NULL)
	{
		free(tArray);
	}
}

//深拷贝
void copyObj(struct AdvAdvTeacher *from, struct AdvAdvTeacher *to)
{
	if (from == NULL || to==NULL)
	{
		printf("copyObj err %s\n","from == NULL || to==NULL");
		return;
	}
	memcpy(to, from, sizeof(struct AdvAdvTeacher));         //本质是浅拷贝
	to->a_name = (char *)malloc(128);
	strcpy(to->a_name, from->a_name);
}




void main()
{
	struct AdvAdvTeacher t1, t2;
	t1.age = 11;
	t1.a_name = (char *)malloc(128*sizeof(char));
	if (t1.a_name == NULL)
	{
		printf("main err ：t1.a_name内存分配失败 ");
		return;
	}
	strcpy(t1.a_name,"111a");
	copyObj(&t1, &t2);
	if (t1.a_name!=NULL)
	{
		free(t1.a_name);
	}

	if (t2.a_name!=NULL)
	{
		free(t2.a_name);
	}
	system("pause");
}