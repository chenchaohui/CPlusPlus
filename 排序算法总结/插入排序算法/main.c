#define _CRT_SECURE_NO_WARNINGS    //去除安全警告
#include"sort.h"

//测试用例
void main()
{
 int list[20];           //存储输入的数据
 int index;              //保存输入的数据的长度
 int node;               //临时存储输入的数据
 printf("\n please input the values you want to sort[exit for 0]\n");
 index = 0;
 scanf("%d",&node);      //给node赋值

 while (node != 0)
 {
   list[index] = node;    //通过node给数据赋值
   index++;
   scanf("%d",&node);
 }
 printf("排序前:\n");

 printArray(list,index);  //打印排序前的状态
 insertSort(list,index);  //进行排序
 printf("\n排序后:\n");  
 printArray(list,index);   //打印排序后的状态
 system("pause");
}
