#include "SeqList.h"

#pragma hdrstop

// #pragma hdrstop ��ʾԤ����ͷ�ļ�����Ϊֹ,�����ͷ�ļ�������Ԥ���롣
// ����Ԥ����ͷ�ļ��Լӿ����ӵ��ٶȣ����������ͷ�ļ�������Ԥ������
// ����ռ̫����̿ռ䣬����ʹ�����ѡ���ų�һЩͷ�ļ��� 
// ��ʱ��Ԫ֮����������ϵ�����絥ԪA������ԪB�����Ե�ԪBҪ����
// ��ԪA���롣�������#pragma startupָ���������ȼ���
// ���ʹ����#pragma package(smart_init) ���ͻ�������ȼ��Ĵ�С�Ⱥ���롣

#include "SeqList.h"   //����˳������
#include <iostream>
using namespace std;


//---------------------------------------------------------------------------
/*
 *  �вι��캯��SeqList
 */
template <class T > 
SeqList<T>:: SeqList(T a[ ], int n)
{
  int i;
  if (n>MaxSize) throw "�����Ƿ�";
  for (i=0; i<n; i++)
    data[i]=a[i];
  length=n;
}

/*
 *  ���뺯��Insert����x���뵽˳����i��λ��
 */
template <class T > 
void SeqList<T>::Insert(int i, T x)
{
  int j;
  if (length>=MaxSize) throw "����";
  if (i<1 || i>length+1) throw "λ�ô���";
  for (j=length; j>=i; j--)
  data[j]=data[j-1];   //ע���j��Ԫ�ش��������±�Ϊj-1��
  data[i-1]=x;
  length++;
}


/*
 *  ɾ������Delete��ɾ��˳����е�i��Ԫ��
 */
template <class T >
T SeqList<T>::Delete(int i)
{
  int j;
  if (length==0 ) throw "����";
  if (i<1 || i>length) throw "λ�ô���";
  T x=data[i-1];
  for (j=i; j<length; j++)
    data[j-1]=data[j];   //ע��˴�j�Ѿ���Ԫ�����ڵ������±�
  length--;
  return x;

}


/*
 *  �����������PrintList���������˳�����Ԫ��
 */

template <class T >
void SeqList<T>::PrintList( )
{
 int i;
 for (i=0; i<length; i++)
  {
    cout << "ѧ�ţ�" << data[i].num << "\n";
    cout << "������" << data[i].name << "\n";
    cout << "�Ա�" << data[i].sex << "\n";
    cout << "�������ڣ�" << data[i].born << "\n";
    cout << "������ò��" << data[i].p << "\n";
    cout << "סַ��" << data[i].addr << "\n";
	cout<<endl;
  }
}


/*
 *  �������PrintStudent�����˳�����Ԫ��x
 */
template <class T >
void SeqList<T>::PrintStudent(T x)
{
  cout << "ѧ�ţ�" << x.num << "\n";
  cout << "������" << x.name << "\n";
  cout << "�Ա�" << x.sex << "\n";
  cout << "�������ڣ�" << x.born << "\n";
  cout << "������ò��" << x.p << "\n";
  cout << "סַ��" << x.addr << "\n";
}



//ȡ����Get����˳����з��ص�i��Ԫ�أ�����Ϊ����ֵ����
template <class T>
T SeqList<T>::Get(int i)
{
  if (i>=0 && i<=length-1)
  return data[i];
  else
   {
	  T stu;
	  return stu;
   }
}







