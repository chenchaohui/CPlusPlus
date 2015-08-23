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

//被调用函数分配内存
//创建结构体数组
//这个部分是最难的
struct AdvTeacher * creatTArray(int count)
{
	int i = 0;
	struct AdvTeacher *p = (struct AdvTeacher *)malloc(count*sizeof(struct  AdvTeacher));
	if (p==NULL)
	{
		printf("struct AdvTeacher * creatTArray Err:分配内存失败\n");
		return NULL;
	}
	//
	for (i = 0; i < count;i++)
	{
		//分配完内存以后，将内存中的内容全部置为0
		memset(p+i,0,sizeof(struct AdvTeacher));
		//memset(&p[i],0,sizeof(struct AdvTeacher))
		p[i].a_name = (char *)malloc(128*sizeof(char));

		if (p[i].a_name==NULL)
		{
			printf("err:分配内存空间失败！\n");
			return NULL;
		}
		//分配完内存以后，将内存中的内容全部置为0
		memset(p[i].a_name, 0, 128 * sizeof(char));
		{
			int  j = 0;
			char **p2 = (char**)malloc(3 * sizeof(char *));
			for (j = 0; j < 3;j++)
			{
				p2[j] = (char*)malloc(128 * sizeof(char));
				//分配完内存以后设置为0
				memset(p2[j],0,128*sizeof(char));
			}	
			p[i].stuname = p2;
		}
	}
	return p;
}

//打印数据
void printTArray(struct AdvTeacher *tArray, int num)
{
	int i = 0, j = 0;
	if (tArray == NULL || num <= 0)
	{
		printf("参数类型错误\n");
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
			printf("stuname%d:%s\n", j, p[j]);                       //上面一行的优化版，主在美观
		}
		printf("\n\n");
	}
}

//将结构体类型变量按照成员（年龄）来排序
void sorttArray(struct AdvTeacher* tArray, int num)
{
	//按照选择排序算法对结构体类型变量进行排序:小-》大
	int i = 0, j = 0;
	struct AdvTeacher tmp;                          //定义一个临时结构体类型变量
	if (tArray==NULL||num<=0)
	{
		printf("参数类型错误\n");
		return;
	}
	for (i = 0; i < num;i++)
	{                                               //注意<,>运算符只能对基本数据类型进行运算，在C++中可以通过运算符重载来对用于自定义类型进行比较运算
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
		printf("参数类型错误\n");
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
		printf("创建结构体失败!\n");
		return;
	}
		for (i = 0; i < 2;i++)
		{
			printf("\n请输入姓名:");
			scanf("%s",p[i].name);
			printf("\n请输入别名:");
			scanf("%s", p[i].a_name);
			printf("\n请输入年龄:");
			scanf("%d",&p[i].age);              //注意这个地方的取地址符号&不能丢呀！！！
			printf("\n请输入学生姓名:");
				for (j = 0; j < 3;j++)
				{
					scanf("%s",p[i].stuname[j]);
				}
		}

     //排序前
		printf("排序前:\n");
		printTArray(p, 2);
     //排序后
		printf("排序后:\n");
		sorttArray(p, 2);
		printTArray(p, 2);
	     if (p!=NULL)
	     {
			 freetArray(p, 2);
	     }
		 p = NULL;
	system("pause");
} 