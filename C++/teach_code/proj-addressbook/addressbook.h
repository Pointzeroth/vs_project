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
	   addressbook( );       //无参构造函数
       addressbook(nb a[], int n);       //有参构造函数
       ~addressbook();             //析构函数为空
       int Length();           //求记事本线性表的长度
       nb Get(int i);         //按位查找，取记事本线性表的第i个元素
       int Locate(nb x);       //按值查找，求记事本线性表中值为x的元素序号
       void Insert(int i, nb x);  //在记事本线性表中第i个位置插入值为x的元素
       nb Delete(int i);        //删除记事本线性表的第i个元素
	   void Print();           //打印记事本线性表中每个元素 
	private:
	  nb data[MaxSize];
	  int length;	
};

#endif
