#define _CRT_SECURE_NO_WARNINGS    //ȥ����ȫ����
#include"sort.h"

//��������
void main()
{
 int list[20];           //�洢���������
 int index;              //������������ݵĳ���
 int node;               //��ʱ�洢���������
 printf("\n please input the values you want to sort[exit for 0]\n");
 index = 0;
 scanf("%d",&node);      //��node��ֵ

 while (node != 0)
 {
   list[index] = node;    //ͨ��node�����ݸ�ֵ
   index++;
   scanf("%d",&node);
 }
 printf("����ǰ:\n");

 printArray(list,index);  //��ӡ����ǰ��״̬
 insertSort(list,index);  //��������
 printf("\n�����:\n");  
 printArray(list,index);   //��ӡ������״̬
 system("pause");
}
