/*��6��ѧ����ÿ��ѧ�������ݰ���ѧ�š����������ſεĳɼ�����Ƴ���ʵ�֣�
(1) �����ÿ��ѧ����ƽ���ɼ�����������Ϣ��ʾ��
(2) ������һλ��ѧ����Ϣ��
(3) ����ѧ��ƽ���ɼ��Ӹߵ���˳���ӡ����ѧ����Ϣ��
*/
#include <iostream>
using namespace std;

struct student			//����ṹ������
{
  int no;
  char name[15];
  int c[3];
  float aver;
};

#define N 6
 //����ÿλͬѧ��ƽ���ɼ����� 
void average(student s[N])    
{
	int w;
	cout<<"�����Ƿ����ÿλѧ����ƽ���ɼ�����Yes�밴1��";
	cin>>w;
	while (w!=1)  
	{
		cout<<"ѡ���������������1��";
		cin>>w; 
	}
	
	for(int i=0;i<N;i++)                               
	  s[i].aver=float(s[i].c[0]+s[i].c[1]+s[i].c[2])/3;
}

//�����ӡѧ�����ݺ���
void output(student stu[N])	
{
	cout<<"\n               ѧ �� �� �� ��\n\n";
	cout<<"ѧ��          	����     �ɼ�1     �ɼ�2     �ɼ�3    ƽ���ɼ�\n";
	cout.precision(3);	      //�趨���� 
	
	for(int i=0;i<N;i++)
	{ 
		cout<<stu[i].no;
		cout.width(16);		//�趨������
		cout<<stu[i].name;
		cout.width(8);
		cout<<stu[i].c[0]<<"        "<<stu[i].c[1]<<"        "<<stu[i].c[2];
		cout<<"        "<<stu[i].aver<<endl;
	}
	cout<<endl;
}

//��λ�ò��Ҳ����ѧ��������Ϣ����
void find(student s[N])                
{
  int t;
	cout<<"������Ҫ��ѯ��ѧ��λ�ã�1-6����";
	cin>>t;
	while (t<1||t>6)  
	{
		cout<<"λ�ò��ԣ����������루1-6����";
		cin>>t; 
	}
	student *p;
	p=s+t-1;        //����ע��ָ������ĸ�ֵ�Լ������ʹ�÷���
	cout<<"No."<<t<<"ѧ����ϢΪ��" <<p->no<<"  "<<p->name<<"  "<<p->c[0]<<"  "
	<<p->c[1]<<"  "<<p->c[2]<<"  "<<p->aver<<endl<<endl;     	
}

void sort(student s[N])          //��ƽ���ɼ�����������ʾ��ӡ����
{
	int w;
	cout<<"�����Ƿ��ѧ��ƽ���ɼ���������Yes�밴1��";
	cin>>w;
	while (w!=1)  
	{
		cout<<"ѡ���������������1��";
		cin>>w; 
	}
	
	student css[N];       //Ϊ���ƻ�ԭʼ���ݣ�����һ���ṹ������ 
	for(int i=0;i<N;i++)
	   css[i]=s[i];
	  
	cout<<"����ǰ��ѧ����Ϣ���£� "<<endl;
	output(css); 
	  
	student temp;    //�ṹ����ʱ���� 
	for(int i=0;i<N-1;i++)     //��ѡ�������㷨��ÿ��ѡ��һ�����ֵ������¼�����±����k��k<->i 
	{	
		int k=i;
		for(int j=i+1;j<N;j++)
			if(css[k].aver<css[j].aver) k=j;
			{temp=css[i];css[i]=css[k];css[k]=temp;}  //�ýṹ�����ֱ�ӽ��н���
	}
	
	cout<<"������ѧ����Ϣ���£�"<<endl; 
	output(css); 
}

int main( )
{
	int i,j,k;
	//ѧ���ṹ�������ʼ��,��������ʾ 
    student cs[N]={{1001,"Gao na",98,88,76},{1002,"Wang jianjun",95,90,88},
					{1003,"Liou yao",76,78,84},{1004,"Ma ailian",56,60,72},
					{1005,"Li ming",96,93,90},{1006,"Cheng jiantao",86,79,90}};
	
    output(cs) ;
	
	//����average����������ÿλͬѧƽ���ɼ�������ʾ����ѧ��������Ϣ 
	average(cs);
	output(cs) ;
	cout<<endl<<endl;
	
	//��ѯĳλѧ����Ϣ 
    find(cs);
    cout<<endl<<endl;
	
	//��ƽ���ɼ����дӴ�С���� 
	sort(cs);
	
    return 0;
}

