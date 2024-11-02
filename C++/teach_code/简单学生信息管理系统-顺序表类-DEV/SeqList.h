#ifndef SEQLIST_H
#define SEQLIST_H

#include <string>      
using namespace std;  //名字空间

const int MaxSize=100;  //100只是示例性的数据，可以根据实际问题具体定义

struct Student
{
  string num;      //学号
  string name;     //姓名
  string sex;      //性别
  string born;     //出生日期
  string p;        //政治面貌
  string addr;     //住址
};



template < class T >
class SeqList
{
public:
   SeqList() {length=0;}       //无参构造函数
   SeqList(T a[ ], int n);       //有参构造函数
   ~SeqList( ) { }             //析构函数为空
   int Length( ) {return length;}  //求顺序表的长度
   T Get(int i);  //取顺序表的第i个元素
   void Insert(int i, T x);  //在顺序表中第i个位置插入值为x的元素
   T Delete(int i);        //删除顺序表的第i个元素
   void PrintList( );       //遍历顺序表，按序号依次输出各元素
   void PrintStudent(T x);  //有参输出函数
private:
   T data[MaxSize];     //存放数据元素的数组
   int length;            //顺序表的长度
};

#endif
