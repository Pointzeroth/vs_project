#include <iostream>
#include <string>
#include "addressbook.cpp"
using namespace std;
//#include "addressbook.h"      //����ͨѶ¼�࣬ע�����������λ��  

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main( )
{
  addressbook a;         //����һ���յ�ͨѶ¼��
  cout<<"ִ�в������:"<<endl;
  nb book1={"Mike","l384444"};
  nb book2={"Jack","1391111"};
  nb book3={"Rose","1512222"};
  
  try
  {
  a.Insert(1,book1);            //����λ�ò��� 
  a.Insert(2,book2);
  a.Insert(3,book3);
  }
  catch(char* wrong)
  {
   cout << wrong;     //��ʧ����ʾʧ����Ϣ
  }
  
  cout<<endl;
  a.Print();
  
  cout<<endl;
  cout<<"ͨѶ¼�е�һλ����ϢΪ��"<<endl; 
  cout<<a.Get(1).name<<'\t'<<a.Get(1).num<<endl<<endl;  //��λ���ң��ҵ�һλ��ͨ��¼��Ϣ
  
  nb book={"Jack","1391111"};
  int k=a.Locate(book);                  //��ֵ���� 
  cout<<"book��ͨѶ¼�е�λ���ǣ�"  <<'\t'<<k<<endl<<endl; 
  
  
  a.Delete(1);                    //ɾ����һ��ͨ��¼��Ϣ 
  
  cout<<"ɾ���Ժ�"<<endl;
  a.Print();                     //��ӡ��ǰͨѶ¼��Ϣ 
  
  return 0;
}
 

