#include <iostream>
#include "SeqList.cpp"      //引用顺序表类SeqList
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct book
{
	char name[15];
	int num;
};

void display(SeqList<book> & book1)
{
	int n=book1.Length();
	cout<<"当前通讯录的长度为："<<n<<endl;
	for (int i=1;i<=n;i++)
	{
		cout<<book1.Get(i).name<<'\t'<<book1.Get(i).num<<endl;
	}
}

int main(int argc, char** argv)
{
//用无参构造函数初始化对象 	
  SeqList<int> a;         //创建一个空的顺序表
  
  cout<<"执行插入操作:"<<endl;
  a.Insert(1,1);
  a.Insert(2,3);
  a.Insert(3,4);
  
  cout<<"顺序表a的长度为:";
  cout<<a.Length()<<endl;         //返回单链表长度
  cout<<endl;
  
  cout<<"打印顺序表a中各元素为："; 
  a.Print(); 
  cout<<endl;
 
  cout<<"按位查询第二个元素:"<<endl;
  cout<<"第二个元素为:";
  cout <<a.Get(2)<<endl;          //查找顺序表中第二个元素
  cout<<endl;
  
  cout<<"按值查询3:"<<endl;
  cout<<"值为3的元素位置为:";
  cout<<a.Locate(3)<<endl;        //查找元素3，并返回在单链表中位置
  cout<<endl;
  
  cout<<"执行删除第一个元素操作:"<<endl;
  cout<<endl;
  a.Delete(1);                //删除元素1
  cout<<"已删除成功，顺序表a的长度为:";    
  cout<<a.Length()<<endl<<endl;
  
  cout<<"打印顺序表a中各元素：";
  a.Print();
  cout<<endl<<endl;

  //用带参构造函数初始化对象 
  int r[]={1,2,3,4,5};
  SeqList <int> b(r,5);     //根据数组创建顺序表

  cout<<"插入前顺序表b的长度为:";    
  cout<<b.Length()<<endl;
  try
  {
   b.Insert(3,8);
  }
  catch(char* wrong)
  {
   cout << wrong;     //如失败提示失败信息
  }

  cout<<"插入后顺序表b的长度为:";    
  cout<<b.Length()<<endl;
   
  cout<<"打印顺序表b中各元素：";
  b.Print();
  cout<<endl<<endl;
  
 //顺序表为通讯录 
  book mybook[2]={{"Mary",1001}, {"Tom",1002}};
  SeqList<book> c(mybook,2);
  cout<<"当前通讯录表c的长度为：";
  cout<<c.Length()<<endl<<endl;
  
  book x={"Jack",1003};
  c.Insert(3,x);
  cout<<"插入后通讯录表c的长度为：";
  cout<<c.Length()<<endl<<endl;
  
  cout<<"查找通讯录中第三条信息为：" ;
  cout<<c.Get(3).name<<'\t'<<c.Get(3).num<<endl<<endl;
  
  cout<<"打印通讯录中所有条信息：" ;   //注意：打印函数不能直接用Print(); Locate()也是。 
  display(c);
  cout<<endl;
  
  cout<<"当前通讯录是否为空？ "<<c.Empty()<<endl;
  cout<<endl;
  
  cout<<"删除通讯录中第三条信息："<<endl;
  c.Delete(3);
  display(c);
  
  return 0;
}
