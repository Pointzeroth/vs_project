/*有6个学生，每个学生的数据包括学号、姓名、三门课的成绩，设计程序实现：
(1) 计算出每个学生的平均成绩，并进行信息显示；
(2) 查找任一位置学生信息；
(3) 按照学生平均成绩从高到低顺序打印所有学生信息。
*/
#include <iostream>
using namespace std;

struct student			//定义结构体类型
{
  int no;
  char name[15];
  int c[3];
  float aver;
};

#define N 6
 //计算每位同学的平均成绩函数 
void average(student s[N])    
{
	int w;
	cout<<"请问是否计算每位学生的平均成绩进？Yes请按1：";
	cin>>w;
	while (w!=1)  
	{
		cout<<"选择错误，请重新输入1：";
		cin>>w; 
	}
	
	for(int i=0;i<N;i++)                               
	  s[i].aver=float(s[i].c[0]+s[i].c[1]+s[i].c[2])/3;
}

//输出打印学生数据函数
void output(student stu[N])	
{
	cout<<"\n               学 生 数 据 表\n\n";
	cout<<"学号          	姓名     成绩1     成绩2     成绩3    平均成绩\n";
	cout.precision(3);	      //设定精度 
	
	for(int i=0;i<N;i++)
	{ 
		cout<<stu[i].no;
		cout.width(16);		//设定输出宽度
		cout<<stu[i].name;
		cout.width(8);
		cout<<stu[i].c[0]<<"        "<<stu[i].c[1]<<"        "<<stu[i].c[2];
		cout<<"        "<<stu[i].aver<<endl;
	}
	cout<<endl;
}

//按位置查找并输出学生数据信息函数
void find(student s[N])                
{
  int t;
	cout<<"请输入要查询的学生位置（1-6）：";
	cin>>t;
	while (t<1||t>6)  
	{
		cout<<"位置不对，请重新输入（1-6）：";
		cin>>t; 
	}
	student *p;
	p=s+t-1;        //这里注意指针变量的赋值以及输出的使用方法
	cout<<"No."<<t<<"学生信息为：" <<p->no<<"  "<<p->name<<"  "<<p->c[0]<<"  "
	<<p->c[1]<<"  "<<p->c[2]<<"  "<<p->aver<<endl<<endl;     	
}

void sort(student s[N])          //按平均成绩排序并重新显示打印函数
{
	int w;
	cout<<"请问是否对学生平均成绩进行排序？Yes请按1：";
	cin>>w;
	while (w!=1)  
	{
		cout<<"选择错误，请重新输入1：";
		cin>>w; 
	}
	
	student css[N];       //为不破坏原始数据，另开设一个结构体数组 
	for(int i=0;i<N;i++)
	   css[i]=s[i];
	  
	cout<<"排序前的学生信息如下： "<<endl;
	output(css); 
	  
	student temp;    //结构体临时变量 
	for(int i=0;i<N-1;i++)     //简单选择排序算法，每趟选择一个最大值，并记录它的下标放入k，k<->i 
	{	
		int k=i;
		for(int j=i+1;j<N;j++)
			if(css[k].aver<css[j].aver) k=j;
			{temp=css[i];css[i]=css[k];css[k]=temp;}  //用结构体变量直接进行交换
	}
	
	cout<<"排序后的学生信息如下："<<endl; 
	output(css); 
}

int main( )
{
	int i,j,k;
	//学生结构体数组初始化,并进行显示 
    student cs[N]={{1001,"Gao na",98,88,76},{1002,"Wang jianjun",95,90,88},
					{1003,"Liou yao",76,78,84},{1004,"Ma ailian",56,60,72},
					{1005,"Li ming",96,93,90},{1006,"Cheng jiantao",86,79,90}};
	
    output(cs) ;
	
	//调用average函数，计算每位同学平均成绩，再显示所有学生完整信息 
	average(cs);
	output(cs) ;
	cout<<endl<<endl;
	
	//查询某位学生信息 
    find(cs);
    cout<<endl<<endl;
	
	//对平均成绩进行从大到小排序 
	sort(cs);
	
    return 0;
}

