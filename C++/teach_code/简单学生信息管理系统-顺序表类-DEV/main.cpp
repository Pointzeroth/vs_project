
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//---------------------------------------------------------------------------

#include <iostream>      //引用输入输出流
#include "SeqList.cpp"     //引入顺序表的类  
#include <string>
using namespace std;

// 当使用<iostream>的时候，该头文件没有定义全局命名空间，
// 必须使用namespace std；这样才能正确使用cout。
//---------------------------------------------------------------------------


int main()
{

 int which;        //功能选择变量
 int i;
 int choose=1;    //控制
 string num;    //学号
 string name;   //姓名
 string sex;    //性别
 string born;   //生日
 string p;      //政治面貌
 string addr;   //住址
 int where;       //插入位置
 int length;      //顺序表长度
 SeqList< Student > s; //创建模版类的实例s
 Student temp;
 
 cout<<"***************************************"<<endl;
 cout<<"**********欢迎使用学籍管理系统*********"<<endl;
 cout<<"*************1:插入学生信息************"<<endl;
 cout<<"*************2:删除学生信息************"<<endl;
 cout<<"*************3:查找学生信息************"<<endl;
 cout<<"*************4:打印学生信息************"<<endl;
 cout<<"*************5:退出系统****************"<<endl;
 cout<<"***************************************"<<endl;
 cout<<endl;
 cout<<endl;
  
 while ( choose==1 )
 {
   cout << "\n";
   cout << "需要插入学生信息请按1" << "\n";
   cout << "需要删除学生信息请按2" << "\n";
   cout << "需要查询学生信息请按3" << "\n";
   cout << "需要输出全部学生信息请按4" << "\n";
   cout << "需要退出请按5" << "\n";
   cout<<endl;
   
   cout<<"请选择："<<endl<<endl; 
   cin >> which;

   
   switch( which )
     {
      case 1:
             cout << "\n";
             cout << "需要插入学生学号:" << "\n";
             cin >> num;
             cout << "需要插入学生姓名:" << "\n";
             cin >> name;
             cout << "需要插入学生性别:" << "\n";
             cin >> sex;
             cout << "需要插入学生出生日期:" << "\n";
             cin >> born;
             cout << "需要插入学生政治面貌:" << "\n";
             cin >> p;
             cout << "需要插入学生地址:" << "\n";
             cin >> addr;
             cout << "需要插入学生位置:" << "\n";
             cin >> where;
             
             //for (i=0; i<2; i++)   //将输入附给student类型的temp
               //{
                temp.num = num;
                temp.name = name;
                temp.sex = sex;
                temp.born = born;
                temp.p = p;
                temp.addr = addr;
               //}
              try
               {
                s.Insert( where, temp );  //插入temp插入到顺序表中where位置
               }
              catch(char* wrong)
               {
                cout << wrong;     //如失败提示失败信息
               }
      break;

     case 2:
             cout << "需要删除的学生位置" << "\n";
             cin >> where;
             try
              {
               s.Delete(where);
			   cout << "已经删除"<<endl;//删除顺序表中where位置的元素
              }
             catch(char* wrong)
              {
               cout << wrong;      //如失败提示失败信息
              }
             
     break;
     case 3:
             cout << "需要查询学生学号：" << "\n";
             cin >> num;
             length =s.Length();    //取顺序表长度附给length

             for (i=0; i<length; i++) //查询信息
             {
              temp=s.Get(i);
              if ( temp.num == num )
              {
               try
               {
                s.PrintStudent(temp);       //输出所查信息
               }
               catch(char* wrong)
               {
                cout << wrong;  //如失败提示失败信息
               }
              }
              else
               cout << "fail to search\n";  //如失败提示失败信息
             }
     break;

    case 4:
             try
             {
              s.PrintList( );         //输出所有信息
             }
             catch(char* wrong)
             {
              cout << wrong;   //如失败提示失败信息
             }
    break;
    case 5:
             choose=0;
    break;
    default:  break;
  }
 }
  return 0; 
}
//---------------------------------------------------------------------------
 
