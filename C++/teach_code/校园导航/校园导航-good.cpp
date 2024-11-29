#include<iostream>
#include<string>
//#include<string.h>
using namespace std;
const int MaxSize=100;

string a[6]={"AB栋","振华图书馆","食堂","新大活","东教一","阶教"};
int b[6][6]={{0,8,6,4,10,1000},{8,0,10,3,6,1000},{6,10,0,1000,5,1000},{4,3,1000,0,1000,1000},{10,6,5,1000,0,1},{1000,1000,1000,1000,1,0}};
int dist[6][6];
string path[6][6];

class Graph
{
public:
	Graph();
	~Graph(){}
	void parc(int n,int m);//打印任意两点之间的距离 
    void changearc(int n,int m);//修改任意两点之间的距离 
	void min();//求任意两点之间的最短路径 
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
	cout<<"请输入改动后的两点的距离:"<<endl;
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
	cout<<"阶教___1___东教一____6_______振华图书馆"<<endl;
	cout<<"           |  |                  |  | |"<<endl;
	cout<<"           |  5  _____10_________|  8 |__3__"<<endl;
	cout<<"           |  | |                   |       |"<<endl;
	cout<<"           | 食堂_______6__________AB栋_4__新大活"<<endl;
	cout<<"           |                         |"<<endl;
	cout<<"           |___________10____________|"<<endl;
	cout<<endl<<endl;
	
	cout<<"0: AB栋"<<'\t'<<"1: 振华图书馆"<<'\t'<<"2: 食堂"<<'\t'<<"3: 新大活"<<'\t'<<"4: 东教一"<<'\t'<<"5: 阶教"<<endl;
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
cout<<"	*      欢迎来到校园导航系统         *                   "<<endl; 
cout<<"	*                                   *					"<<endl;
cout<<"	*                                   *					"<<endl;
cout<<"	*************************************					"<<endl;
cout<<endl;

int m,n,x;
Graph A; 
while(1)
{
cout<<"显示地图请按1"<<endl;
cout<<"查询两地间的距离请按2"<<endl;
cout<<"修改两地间的距离请按3"<<endl;
cout<<"求两地间最短路径请按4"<<endl;
cout<<"退出系统请按0"<<endl;
cout<<endl;

cin>>x;
switch(x)
{
	case 1:map();break;
	case 2:{cout<<"AB栋代号为0,图书馆代号为1,食堂代号为2,新大活代号为3,东教一代号为4,阶教代号为5"<<endl<<endl; 
		cout<<"请输入你想要查询的两地的代号:";cin>>n>>m;A.parc(n,m);}break;
	case 3:{cout<<"AB栋代号为0,图书馆代号为1,食堂代号为2,新大活代号为3,东教一代号为4,阶教代号为5"<<endl<<endl; 
		cout<<"请输入你想要修改的两地代号:";cin>>n>>m;A.changearc(n,m);}break;
	case 4:{cout<<"AB栋代号为0,图书馆代号为1,食堂代号为2,新大活代号为3,东教一代号为4,阶教代号为5"<<endl<<endl; 
		cout<<"请输入你想求最短距离的两地代号:"; cin>>n>>m; A.min();cout<<endl; cout<<path[n][m]<<'\t'<<dist[n][m]<<endl<<endl;}break;	
	case 0:break;
	default :cout<<"你输入的序号不对"<<endl;break;
}
if(x==0)break;
}
return 0;
}
