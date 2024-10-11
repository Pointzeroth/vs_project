#include <iostream>
using namespace std; 
#include "addressbook.h"   //ע�����������λ�� 

/*
*ǰ��������˳�������
*��    �룺��
*��    �ܣ�����һ��˳���
*��    ������
*��������������һ��˳���
*/

addressbook:: addressbook( )
{
  length=0;
}
/*
*ǰ��������˳�������
*��    �룺˳�����Ϣ��������ʽa[],˳�����n
*��    �ܣ�������a[]��Ԫ�ؽ�Ϊ����Ϊn��˳���
*��    ������
*��������������һ��˳���
*/
 
addressbook:: addressbook(nb a[], int n)
{
  if (n>MaxSize) throw "�����Ƿ�";
  for (int i=0; i<n; i++)  
    data[i]=a[i];
  length=n;
}
/*
*ǰ����������
*��    �룺��
*��    �ܣ���
*��    ������
*������������
*/

addressbook:: ~addressbook( )
{
}

/*
*ǰ��������˳������
*��    �룺��
*��    �ܣ����˳�����
*��    ����˳�����
*����������˳�����
*/

int addressbook::Length()
{
	 return length;
}
/*
*ǰ��������˳������
*��    �룺��ѯԪ��λ��i
*��    �ܣ���λ����λ��Ϊi��Ԫ�ز����ֵ
*��    ������ѯԪ�ص�ֵ
*����������˳�����
*/

nb addressbook::Get(int i)
{
  if (i<1 && i>length) throw "����λ�÷Ƿ�";
    else return data[i-1];
}
/*
*ǰ��������˳������
*��    �룺��ѯԪ��ֵx
*��    �ܣ���ֵ����ֵ��Ԫ�ز����λ��
*��    ������ѯԪ�ص�λ��
*����������˳�����
*/

int addressbook::Locate(nb x)
{     
	  for (int i=0; i<length; i++)
	   if ((data[i].name==x.name) && (data[i].num==x.num)) 
	     return i+1 ;  //�±�Ϊi��Ԫ�ص���x�����������i+1
	  return 0;  //�˳�ѭ����˵������ʧ��
}
/*
*ǰ��������˳������
*��    �룺����Ԫ��x,����λ��i
*��    �ܣ���Ԫ��x���뵽˳�����λ��i��
*��    ������
*����������˳��������Ԫ��
*/

void addressbook::Insert(int i, nb x)
{ 
  int j;
  if (length>=MaxSize) throw "����";
    if (i<1 || i>length+1) throw "λ��";
  for (j=length; j>=i; j--)
  data[j]=data[j-1];   //ע���j��Ԫ�ش��������±�Ϊj-1��
  data[i-1]=x;
  length++;
}

/*
*ǰ��������˳������
*��    �룺Ҫɾ��Ԫ��λ��i
*��    �ܣ�ɾ��˳�����λ��Ϊi��Ԫ��
*��    ������
*����������˳���ɾ��Ԫ��
*/

nb addressbook::Delete(int i)
{ 
  nb x;  int j;
  if (length==0) throw "����";
  if (i<1 || i>length) throw "λ��";
  x=data[i-1];
  for (j=i; j<length; j++)
    data[j-1]=data[j];   //ע��˴�j�Ѿ���Ԫ�����ڵ������±�
  length--;
  return x;
}

//��ӡͨѶ¼�е�ÿ��Ԫ��

void addressbook::Print()
{ 
  int j;
  if (length==0) throw "����";
  for (j=0; j<length; j++)
     {
     	
		cout<<data[j].name<<"    ";
		cout<<data[j].num<<endl;
   	 }  
}



 

