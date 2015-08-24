
//看到题目后，自己实现的部分代码，感觉能力还是不行啊

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
//		printf("请输入第%d个老师的姓名:\n", i + 1);
//		pt[i].name = (char *)malloc(128 * sizeof(char));
//		scanf("%s", pt[i].name);
//		printf("请输入入第%d个老师的职称:\n", i + 1);
//		pt[i].tile = (char *)malloc(128 * sizeof(char));
//		scanf("%s", pt[i].tile);
//		printf("请输入入第%d个老师的年龄:\n", i + 1);
//		scanf("%d", &pt[i].age);
//		printf("请输入入第%d个老师的地址:\n", i + 1);
//		pt[i].addr = (char *)malloc(128 * sizeof(char));
//		scanf("%s", pt[i].addr);
//
//		//开辟了内存必须记得释放
//		pt[i].p2 = (char **)malloc(3 * sizeof(char *));
//		memset(pt[i].p2, 0, 3 * sizeof(char *));
//		for (j = 0; j < 3;j++)
//		{
//			printf("请输入第%d为老师的第%d为学生的姓名:\n",i+1,j+1);
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
//	//定义一个指针数组
//	struct _itAdvTeacher advT[6];
//	init(advT, 6);
//	system("pause");
//	return EXIT_SUCCESS;
//}

//参照人家的标准代码写的程序，个人感觉非常好

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

//接口的封装与设计，函数在声明的时候可以省略形参的名称
int createStructArray(AdvTeacher **,int , int);
int printStructArray(AdvTeacher*,int ,int); 
int sortStructArray(AdvTeacher*, int);
int freeStructArray(AdvTeacher **,int ,int );


//测试用例
void main()
{
	int ret = 0;
	int i = 0,j = 0;
	AdvTeacher *pta = NULL;
	//被调函数开辟内存给主调函数用
	ret = createStructArray(&pta, structArray_Size, student_Num);
	if (ret == -1)
	{
		printf("createStructArray failed.\n");
		return;
	}
	for (i = 0; i < structArray_Size;i++)
	{
		printf("\n请输入第%d位老师的姓名:",i+1);
		scanf("%s",pta[i].name);
		printf("\n请输入第%d位老师的头衔:", i + 1);
		scanf("%s", pta[i].tile);
		printf("\n请输入第%d位老师年龄:", i + 1);
		scanf("%d", &pta[i].age);
		for (j = 0; j < student_Num; j++)
		{
			printf("\n请输入第%d位老师的第%d位学生的姓名:",i+1,j+1);
			scanf("%s",pta[i].stuname[j]);
		}
		printf("\n\n");
	}
	printf("排序前:\n");
	ret = printStructArray(pta, structArray_Size, student_Num);
	if (ret == -1)
	{
		printf("打印结构体数组失败\n");
		return;
	}

	printf("\n\n排序后:\n");

	ret = sortStructArray(pta, structArray_Size);
	if (ret == -1)
	{
		printf("结构体数组排序失败\n");
		return;
	}

	ret = printStructArray(pta, structArray_Size, student_Num);
	if (ret == -1)
	{
		printf("打印结构体数组失败\n");
		return;
	}
	ret = freeStructArray(&pta, structArray_Size, student_Num);
	if (ret == -1)
	{
		printf("释放内存失败\n");
		return;
	}
	system("pause");
}

 //被调用函数分配内存，甩出内存给主调函数使用
int createStructArray(AdvTeacher **pt, int num1, int num2)
{
	int i = 0, j = 0;
	int ret = 0;
	AdvTeacher *tmp = NULL;

	//每次分配完内存都必须判断内存是否分配成功
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
		 printf("\n\n第%d位老师的姓名是:%s",i+1,pta[i].name);
		 printf("\n\n第%d位老师的头衔是:%s", i + 1, pta[i].tile);
		 printf("\n\n第%d位老师的年龄是:%d", i + 1, pta[i].age);
		 for (j = 0; j < num2; j++)
		 {
			 printf("\n\n第%d位老师的第%d位学生的姓名是:%s", i + 1,j+1,pta[i].stuname[j]);
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
	//采用比较排序法
	for (i = 0; i < num1;i++)
	{
		for (j = 0; j < num1;j++)
		{
			if (strcmp(pta[i].name,pta[j].name) > 0)
			{
				//采用编译器默认的赋值方法
				tmp = pta[i];
				pta[i] = pta[j];
				pta[j] = tmp;
			}
		}
		
	}
	return 0;
}

//程序员必须记得在用mmalloc动态分配内存以后要记得释放；
int freeStructArray(AdvTeacher **pt,int num1,int num2)
{
	//记得在释放内存的时候要从内到外进行释放
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