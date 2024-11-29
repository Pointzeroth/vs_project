#include<iostream>
#include<string>
//#include<string.h>
using namespace std;
const int MaxSize=100;

string a[6]={"AB��","��ͼ���","ʳ��","�´��","����һ","�׽�"};
int b[6][6]={{0,8,6,4,10,1000},{8,0,10,3,6,1000},{6,10,0,1000,5,1000},{4,3,1000,0,1000,1000},{10,6,5,1000,0,1},{1000,1000,1000,1000,1,0}};
int dist[6][6];
string path[6][6];

class Graph
{
public:
	Graph();
	~Graph(){}
	void parc(int n,int m);//��ӡ��������֮��ľ��� 
    void changearc(int n,int m);//�޸���������֮��ľ��� 
	void min();//����������֮������·�� 
private:
	string ver[MaxSize];
	int arc[MaxSize][MaxSize]; 
};

Graph::Graph()
{
for(int i=0;i<6;i++)
 ver[i]=a[i];
for(int i=0;i<6;i++)
 for(int j=0;j<6;j++)
   arc[i][j]=b[i][j];
cout<<endl<<endl;	
}


void Graph::parc(int n,int m)
{
	cout<<arc[n][m]<<endl;
	cout<<endl<<endl;
}


void Graph::changearc(int n,int m)
{
	int x;
	cout<<"������Ķ��������ľ���:"<<endl;
	cin>>x;
	arc[n][m]=x;
	arc[m][n]=x; 
	cout<<endl<<endl;
}
void Graph::min()
{
	int i,j;
	//int dist[6][6];
	//string path[6][6]; 
	for(i=0;i<6;i++)
	 for(j=0;j<6;j++)
	 {dist[i][j]=arc[i][j];
	  if(dist[i][j]!=1000 && dist[i][j]!=0)  path[i][j]=ver[i]+"->"+ver[j];
	  else path[i][j]="";
	 }
	
    for(int k=0;k<6;k++)
     for(i=0;i<6;i++)
	  for(j=0;j<6;j++)
	     if(dist[i][k]+dist[k][j]<dist[i][j])
	   {
		dist[i][j]=dist[i][k]+dist[k][j];
		path[i][j]=path[i][k]+"->"+path[k][j];
	   } 
	/* for(i=0;i<6;i++)
	   for(j=0;j<i;j++)
	     cout<<path[i][j]<<':'<<dist[i][j]<<endl; 
	cout<<endl<<endl;
	*/
}

void map()
{
	cout<<"�׽�___1___����һ____6_______��ͼ���"<<endl;
	cout<<"           |  |                  |  | |"<<endl;
	cout<<"           |  5  _____10_________|  8 |__3__"<<endl;
	cout<<"           |  | |                   |       |"<<endl;
	cout<<"           | ʳ��_______6__________AB��_4__�´��"<<endl;
	cout<<"           |                         |"<<endl;
	cout<<"           |___________10____________|"<<endl;
	cout<<endl<<endl;
	
	cout<<"0: AB��"<<'\t'<<"1: ��ͼ���"<<'\t'<<"2: ʳ��"<<'\t'<<"3: �´��"<<'\t'<<"4: ����һ"<<'\t'<<"5: �׽�"<<endl;
    cout<<endl<<endl;
    
	int i,j;
    for (i=0;i<6;i++) 
    {
    for(j=0;j<6;j++)
      cout<<b[i][j]<<'\t';
    cout<<endl;
    }
    cout<<endl<<endl;
}


int main()
{

cout<<"	*************************************					"<<endl;
cout<<"	*                                   *					"<<endl;
cout<<"	*                                   *					"<<endl;
cout<<"	*      ��ӭ����У԰����ϵͳ         *                   "<<endl; 
cout<<"	*                                   *					"<<endl;
cout<<"	*                                   *					"<<endl;
cout<<"	*************************************					"<<endl;
cout<<endl;

int m,n,x;
Graph A; 
while(1)
{
cout<<"��ʾ��ͼ�밴1"<<endl;
cout<<"��ѯ���ؼ�ľ����밴2"<<endl;
cout<<"�޸����ؼ�ľ����밴3"<<endl;
cout<<"�����ؼ����·���밴4"<<endl;
cout<<"�˳�ϵͳ�밴0"<<endl;
cout<<endl;

cin>>x;
switch(x)
{
	case 1:map();break;
	case 2:{cout<<"AB������Ϊ0,ͼ��ݴ���Ϊ1,ʳ�ô���Ϊ2,�´�����Ϊ3,����һ����Ϊ4,�׽̴���Ϊ5"<<endl<<endl; 
		cout<<"����������Ҫ��ѯ�����صĴ���:";cin>>n>>m;A.parc(n,m);}break;
	case 3:{cout<<"AB������Ϊ0,ͼ��ݴ���Ϊ1,ʳ�ô���Ϊ2,�´�����Ϊ3,����һ����Ϊ4,�׽̴���Ϊ5"<<endl<<endl; 
		cout<<"����������Ҫ�޸ĵ����ش���:";cin>>n>>m;A.changearc(n,m);}break;
	case 4:{cout<<"AB������Ϊ0,ͼ��ݴ���Ϊ1,ʳ�ô���Ϊ2,�´�����Ϊ3,����һ����Ϊ4,�׽̴���Ϊ5"<<endl<<endl; 
		cout<<"��������������̾�������ش���:"; cin>>n>>m; A.min();cout<<endl; cout<<path[n][m]<<'\t'<<dist[n][m]<<endl<<endl;}break;	
	case 0:break;
	default :cout<<"���������Ų���"<<endl;break;
}
if(x==0)break;
}
return 0;
}
