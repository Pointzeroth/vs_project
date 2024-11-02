#ifndef SEQLIST_H
#define SEQLIST_H

#include <string>      
using namespace std;  //���ֿռ�

const int MaxSize=100;  //100ֻ��ʾ���Ե����ݣ����Ը���ʵ��������嶨��

struct Student
{
  string num;      //ѧ��
  string name;     //����
  string sex;      //�Ա�
  string born;     //��������
  string p;        //������ò
  string addr;     //סַ
};



template < class T >
class SeqList
{
public:
   SeqList() {length=0;}       //�޲ι��캯��
   SeqList(T a[ ], int n);       //�вι��캯��
   ~SeqList( ) { }             //��������Ϊ��
   int Length( ) {return length;}  //��˳���ĳ���
   T Get(int i);  //ȡ˳���ĵ�i��Ԫ��
   void Insert(int i, T x);  //��˳����е�i��λ�ò���ֵΪx��Ԫ��
   T Delete(int i);        //ɾ��˳���ĵ�i��Ԫ��
   void PrintList( );       //����˳�����������������Ԫ��
   void PrintStudent(T x);  //�в��������
private:
   T data[MaxSize];     //�������Ԫ�ص�����
   int length;            //˳���ĳ���
};

#endif
