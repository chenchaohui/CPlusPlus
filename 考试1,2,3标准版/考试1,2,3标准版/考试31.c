//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct _itTeacher
//{
//	char	name[32];
//	char	tile[32];
//	int		age;
//	char	addr[128];
//	char     stuname[3][128];  //本质数组指针
//};
//
//int init(struct _itTeacher *pt,int num)
//{
//	int  i = 0;
//	int ret = -1;
//	if (pt == NULL)
//	{
//		printf("print Error:ret=%d,%s","pt == NULL");
//		return ret;
//	}
//	for (i = 0; i < num;i++)
//	  {
//		  printf("请输入第%d个老师的姓名:\n", i+1);
//		  scanf("%s",pt[i].name);
//		  printf("请输入入第%d个老师的职称:\n", i+1);
//		  scanf("%s", pt[i].tile);
//		  printf("请输入入第%d个老师的年龄:\n", i + 1);
//		  scanf("%d",&pt[i].age);
//		  printf("请输入入第%d个老师的地址:\n", i + 1);
//		  scanf("%s",pt[i].addr);
//		  printf("\n");
//	  }
//	return 0;
//}
//
//void print(struct _itTeacher *pt, int num)
//{
//	int i = 0;
//	int ret = -1;
//	if (pt == NULL)
//	{
//		printf("print Error:ret=%d,%s","pt == NULL");
//		return ret;
//	}

//	for (i = 0; i < num;i++)
//	{
//		printf("name=%s\n",pt[i].name);
//		printf("tile=%s\n", pt[i].tile);
//		printf("age=%d\n", pt[i].age);
//		printf("addr=%s\n", pt[i].addr);
//		printf("\n\n");
//	}
     //return 0;
//}
//
//int sortTeacher(struct _itTeacher *pt, int num)
//{
//	int  i = 0, j = 0;
//	int ret = -1;
//	struct _itTeacher tmp;
//	if (pt == NULL)
//	{
//		printf("print Error:ret=%d,%s", "pt == NULL");
//		return ret;
//	}
//	//对年龄按照比较排序法对老师进行排序
//	for (i = 0; i < num;i++)
//	{
//		for (j = 0; j < num;j++)
//		{
//			if (pt[i].age<pt[j].age)
//			{
//				//采用默认的赋值方法
//				tmp= pt[i];
//				pt[i] = pt[j];
//				pt[j] = tmp;
//			}
//		}
//	}
//	return 0;
//}
//
//void main()
//{
//	//用buf的方法定义一个结构体类型的数组
//	struct _itTeacher teacher[6];
//	init(teacher, 6);
//	printf("排序前:\n");
//	print(teacher,6);
//	printf("排序后:\n");
//	sortTeacher(teacher,6);
//	print(teacher, 6);
//	system("pause");
//}