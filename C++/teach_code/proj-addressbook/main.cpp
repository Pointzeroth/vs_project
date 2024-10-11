#include <iostream>
#include <string>
#include "addressbook.cpp"
using namespace std;
//#include "addressbook.h"      //引用通讯录类，注意该条语句放置位置  

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main( )
{
  addressbook a;         //创建一个空的通讯录表
  cout<<"执行插入操作:"<<endl;
  nb book1={"Mike","l384444"};
  nb book2={"Jack","1391111"};
  nb book3={"Rose","1512222"};
  
  try
  {
  a.Insert(1,book1);            //给定位置插入 
  a.Insert(2,book2);
  a.Insert(3,book3);
  }
  catch(char* wrong)
  {
   cout << wrong;     //如失败提示失败信息
  }
  
  cout<<endl;
  a.Print();
  
  cout<<endl;
  cout<<"通讯录中第一位置信息为："<<endl; 
  cout<<a.Get(1).name<<'\t'<<a.Get(1).num<<endl<<endl;  //按位查找：找第一位置通信录信息
  
  nb book={"Jack","1391111"};
  int k=a.Locate(book);                  //按值查找 
  cout<<"book在通讯录中的位置是："  <<'\t'<<k<<endl<<endl; 
  
  
  a.Delete(1);                    //删除第一条通信录信息 
  
  cout<<"删除以后："<<endl;
  a.Print();                     //打印当前通讯录信息 
  
  return 0;
}
 

