#include <iostream>
#include "SeqList.cpp"      //����˳�����SeqList
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
	cout<<"��ǰͨѶ¼�ĳ���Ϊ��"<<n<<endl;
	for (int i=1;i<=n;i++)
	{
		cout<<book1.Get(i).name<<'\t'<<book1.Get(i).num<<endl;
	}
}

int main(int argc, char** argv)
{
//���޲ι��캯����ʼ������ 	
  SeqList<int> a;         //����һ���յ�˳���
  
  cout<<"ִ�в������:"<<endl;
  a.Insert(1,1);
  a.Insert(2,3);
  a.Insert(3,4);
  
  cout<<"˳���a�ĳ���Ϊ:";
  cout<<a.Length()<<endl;         //���ص�������
  cout<<endl;
  
  cout<<"��ӡ˳���a�и�Ԫ��Ϊ��"; 
  a.Print(); 
  cout<<endl;
 
  cout<<"��λ��ѯ�ڶ���Ԫ��:"<<endl;
  cout<<"�ڶ���Ԫ��Ϊ:";
  cout <<a.Get(2)<<endl;          //����˳����еڶ���Ԫ��
  cout<<endl;
  
  cout<<"��ֵ��ѯ3:"<<endl;
  cout<<"ֵΪ3��Ԫ��λ��Ϊ:";
  cout<<a.Locate(3)<<endl;        //����Ԫ��3���������ڵ�������λ��
  cout<<endl;
  
  cout<<"ִ��ɾ����һ��Ԫ�ز���:"<<endl;
  cout<<endl;
  a.Delete(1);                //ɾ��Ԫ��1
  cout<<"��ɾ���ɹ���˳���a�ĳ���Ϊ:";    
  cout<<a.Length()<<endl<<endl;
  
  cout<<"��ӡ˳���a�и�Ԫ�أ�";
  a.Print();
  cout<<endl<<endl;

  //�ô��ι��캯����ʼ������ 
  int r[]={1,2,3,4,5};
  SeqList <int> b(r,5);     //�������鴴��˳���

  cout<<"����ǰ˳���b�ĳ���Ϊ:";    
  cout<<b.Length()<<endl;
  try
  {
   b.Insert(3,8);
  }
  catch(char* wrong)
  {
   cout << wrong;     //��ʧ����ʾʧ����Ϣ
  }

  cout<<"�����˳���b�ĳ���Ϊ:";    
  cout<<b.Length()<<endl;
   
  cout<<"��ӡ˳���b�и�Ԫ�أ�";
  b.Print();
  cout<<endl<<endl;
  
 //˳���ΪͨѶ¼ 
  book mybook[2]={{"Mary",1001}, {"Tom",1002}};
  SeqList<book> c(mybook,2);
  cout<<"��ǰͨѶ¼��c�ĳ���Ϊ��";
  cout<<c.Length()<<endl<<endl;
  
  book x={"Jack",1003};
  c.Insert(3,x);
  cout<<"�����ͨѶ¼��c�ĳ���Ϊ��";
  cout<<c.Length()<<endl<<endl;
  
  cout<<"����ͨѶ¼�е�������ϢΪ��" ;
  cout<<c.Get(3).name<<'\t'<<c.Get(3).num<<endl<<endl;
  
  cout<<"��ӡͨѶ¼����������Ϣ��" ;   //ע�⣺��ӡ��������ֱ����Print(); Locate()Ҳ�ǡ� 
  display(c);
  cout<<endl;
  
  cout<<"��ǰͨѶ¼�Ƿ�Ϊ�գ� "<<c.Empty()<<endl;
  cout<<endl;
  
  cout<<"ɾ��ͨѶ¼�е�������Ϣ��"<<endl;
  c.Delete(3);
  display(c);
  
  return 0;
}
