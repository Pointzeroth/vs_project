#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <string>
using namespace std;

const int MaxSize=100;
struct nb
{
	string  name;
	string  num;
	 
};

class addressbook
{
	public:
	   addressbook( );       //�޲ι��캯��
       addressbook(nb a[], int n);       //�вι��캯��
       ~addressbook();             //��������Ϊ��
       int Length();           //����±����Ա�ĳ���
       nb Get(int i);         //��λ���ң�ȡ���±����Ա�ĵ�i��Ԫ��
       int Locate(nb x);       //��ֵ���ң�����±����Ա���ֵΪx��Ԫ�����
       void Insert(int i, nb x);  //�ڼ��±����Ա��е�i��λ�ò���ֵΪx��Ԫ��
       nb Delete(int i);        //ɾ�����±����Ա�ĵ�i��Ԫ��
	   void Print();           //��ӡ���±����Ա���ÿ��Ԫ�� 
	private:
	  nb data[MaxSize];
	  int length;	
};

#endif
