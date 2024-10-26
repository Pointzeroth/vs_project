#include <iostream>
#include <cmath>
using namespace std;

struct point
{
	int x;
	int y;
	
	void setdata(int a, int b)
	{
		x=a;
		y=b;
	}
	
	void display()
	{
		cout<<"点的横坐标为："<<x<<"  "<<"点的纵坐标为："<<y<<endl; 
	}
};

int main(int argc,char* argv[])
{
	point d1,d2;
	d1.setdata(1,1);
	d2.setdata(2,2);
	d1.display();
	d2.display();

	cout<<"两点之间的距离为："<<endl; 
	float dis=sqrt((d1.x-d2.x)*(d1.x-d2.x)+(d1.y-d2.y)*(d1.y-d2.y));
	
	cout<<dis;
	
	return 0;
}
