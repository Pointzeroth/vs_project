#include "SeqList.h"

#pragma hdrstop

// #pragma hdrstop 表示预编译头文件到此为止,后面的头文件不进行预编译。
// 可以预编译头文件以加快链接的速度，但如果所有头文件都进行预编译又
// 可能占太多磁盘空间，所以使用这个选项排除一些头文件。 
// 有时单元之间有依赖关系，比如单元A依赖单元B，所以单元B要先于
// 单元A编译。你可以用#pragma startup指定编译优先级，
// 如果使用了#pragma package(smart_init) ，就会根据优先级的大小先后编译。

#include "SeqList.h"   //引入顺序表的类
#include <iostream>
using namespace std;


//---------------------------------------------------------------------------
/*
 *  有参构造函数SeqList
 */
template <class T > 
SeqList<T>:: SeqList(T a[ ], int n)
{
  int i;
  if (n>MaxSize) throw "参数非法";
  for (i=0; i<n; i++)
    data[i]=a[i];
  length=n;
}

/*
 *  插入函数Insert，将x插入到顺序表第i个位置
 */
template <class T > 
void SeqList<T>::Insert(int i, T x)
{
  int j;
  if (length>=MaxSize) throw "上溢";
  if (i<1 || i>length+1) throw "位置错误";
  for (j=length; j>=i; j--)
  data[j]=data[j-1];   //注意第j个元素存在数组下标为j-1处
  data[i-1]=x;
  length++;
}


/*
 *  删除函数Delete，删除顺序表中第i个元素
 */
template <class T >
T SeqList<T>::Delete(int i)
{
  int j;
  if (length==0 ) throw "下溢";
  if (i<1 || i>length) throw "位置错误";
  T x=data[i-1];
  for (j=i; j<length; j++)
    data[j-1]=data[j];   //注意此处j已经是元素所在的数组下标
  length--;
  return x;

}


/*
 *  遍历输出函数PrintList，输出所有顺序表中元素
 */

template <class T >
void SeqList<T>::PrintList( )
{
 int i;
 for (i=0; i<length; i++)
  {
    cout << "学号：" << data[i].num << "\n";
    cout << "姓名：" << data[i].name << "\n";
    cout << "性别：" << data[i].sex << "\n";
    cout << "出生日期：" << data[i].born << "\n";
    cout << "政治面貌：" << data[i].p << "\n";
    cout << "住址：" << data[i].addr << "\n";
	cout<<endl;
  }
}


/*
 *  输出函数PrintStudent，输出顺序表中元素x
 */
template <class T >
void SeqList<T>::PrintStudent(T x)
{
  cout << "学号：" << x.num << "\n";
  cout << "姓名：" << x.name << "\n";
  cout << "性别：" << x.sex << "\n";
  cout << "出生日期：" << x.born << "\n";
  cout << "政治面貌：" << x.p << "\n";
  cout << "住址：" << x.addr << "\n";
}



//取函数Get，从顺序表中返回第i个元素，并作为返回值返回
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







