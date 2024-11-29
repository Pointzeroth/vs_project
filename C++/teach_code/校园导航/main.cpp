#include"mg.cpp"
#include<string>
#include<stdlib.h>
#include <iostream>
using namespace std;

	
void map()
{
	cout << "\t\t\t┃-----------------------------安徽工业大学校园平面图--------------------------   ┃\n";
	cout << "\t\t\t┃                                                                                ┃\n";
	cout << "\t\t\t┃                          10╳0------------------╳8--------------------╳7     ┃\n";
	cout << "\t\t\t┃                            ┃                    ┃                    ┃      ┃\n";
	cout << "\t\t\t┃                            ┃                    ┃                    ┃      ┃\n";
	cout << "\t\t\t┃                      研    ┃                    ┃                    ┃  材  ┃\n";
	cout << "\t\t\t┃        学校体育场    究    ┃                                          ┃  料  ┃\n";
	cout << "\t\t\t┃                      生    ┃                  餐饮场所                ┃  楼  ┃\n";
	cout << "\t\t\t┃                      公    ┃                                          ┃      ┃\n";
	cout << "\t\t\t┃                      寓    ┃                    ┃                    ┃　　　┃\n";
	cout << "\t\t\t┃　　　田径场　            　┃　　　　　　　　　　┃　　　 宿 　　    　┃　　　┃\n";
	cout << "\t\t\t┃　　　　　　　　　　　　　　┃　　　　　　　　　　┃　　　 舍 　　    　┃　　　┃\n";
	cout << "\t\t\t┃　　　　　　　　　　　　　　┃　　                ┃       楼    　　　 ┃      ┃\n";
	cout << "\t\t\t┃　            　　　　　　　┃　    AB篮球场      ┃　　    A 　        ┃      ┃\n";
	cout << "\t\t\t┃    教学D楼                 ┃                    ┃　　　    　        ┃  冶  ┃\n";
	cout << "\t\t\t┃　            　　　　　　11╳------------------╳9 ------------------26╳  金  ┃\n";
	cout << "\t\t\t┃      12╳--------------------                                          ┃  楼  ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                振华图书馆                ┃      ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                                          ┃      ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                                          ┃      ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                                          ┃      ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                                          ┃      ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                                          ┃  鸟  ┃\n";
	cout << "\t\t\t┃    艺  ┃            机  14╳                                         5╳  笼  ┃\n";
	cout << "\t\t\t┃    设  ╳13          械    ┃              宿舍楼B                     ┃  篮  ┃\n";
	cout << "\t\t\t┃    楼  ┃            楼    ┃                                          ┃  球  ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                                          ┃  场  ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                                          ┃      ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                                          ┃      ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                                          ┃      ┃\n";
	cout << "\t\t\t┃        ┃                  ┃                                          ┃      ┃\n";
	cout << "\t\t\t┃中心花园┃             电   ┃                南  北  教                ┃  工  ┃\n";
	cout << "\t\t\t┃        ┃             气   ╳16                                      13╳  创  ┃\n";
	cout << "\t\t\t┃        ┃             楼   ┃------------------12╳----------------------  楼  ┃\n";
	cout << "\t\t\t┃      15╳                                                                      ┃\n";
	cout << "\t\t\t┃                              ---------------- 学校正门 ------------------╳8   ┃\n";
	cout << "\t\t\t┃      逸夫楼                                                                    ┃\n";
	cout << "\t\t\t┃                                                                        阶教    ┃\n";
	cout << "\t\t\t┃-----------------------------------------------------------------------------   ┃\n";
	cout << endl;

}/*map*/

	string a[7]={"学校体育馆","东宛餐厅","振华图书馆","阶教", "电气楼","冶金楼","L2栋"};
    mg<string> a1(a,7,10);
void menu()
{
	int n, x, y, len,z,c,v;
	int a;string b;
	system("cls");
	
	cout << "\n\n\n";
	cout << " ■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
	cout << " ■                                                ■\n";
	cout << " ■欢 迎 使 用 安 徽 工 业 大 学 校 园 导 航 系 统 ■\n";
	cout << " ■                                                ■\n";
	cout << " ■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
	cout << "\n\n\n";
	cout << "   1、查询校园所有地点；      2、查询地点具体平面图；" << endl;
	cout << "   3、查询所有两地点间的距离；4、修改两地点距离；" << endl;
	cout << "   5、查询两地点的最短路径;   6、从输入地点开始遍历" << endl;
	cout << "   7、修改地点名称;           8、退出校园导航系统; " << endl;
	cout << "\n\n\n";
	cout << "请输入需要指令代号：";
	cin >> n;
	switch (n) {
	case 1:
		a1.putoutvertex();
		cout << "\n\n按回车键返回至导航系统界面\n\n";
		getchar(); getchar();
		menu();
		break;
	case 2:
		map();
		cout << "\n\n按回车键返回至导航系统界面\n\n";
		getchar(); getchar();
		menu();
		break;
	case 3:
		a1.putoutarc();
		cout << "\n\n按回车键返回至导航系统界面\n\n";
		getchar(); getchar();
		menu();
		break;
	case 4:
		a1.putoutvertex();
		cout<<endl;
		cout << "请输入两地点的代号及修改值：";
		cin >> x >> y >> len;
		a1.setarc(x, y, len);
		a1.putoutarc();
		cout << "\n\n按回车键返回至导航系统界面\n\n";
		getchar(); getchar();
		menu();
		break;

	case 5:
		a1.putoutvertex();
		cout<<endl;
		cout<<"请输入两地点的代号："; 
		cin>>c>>v;
		a1.Floyd(c,v);
		cout << "\n\n按回车键返回至导航系统界面\n\n";
		getchar(); getchar();
		menu();
		break;
	case 6:
			a1.putoutvertex();
		cout<<endl;
		cout<<"请输入遍历起点的代号："<<endl;
		cin>>z;
	a1.DFSTravese(z-1);
	a1.setzero();
		cout << "\n\n按回车键返回至导航系统界面\n\n";
		getchar(); getchar();
		menu();
		break;
    case 7:
	 		a1.putoutvertex();
	 		cout<<endl;
	 	cout<<"修改第几个顶点："<<endl;
		 cin>>a;
		  cout<<"修改为："<<endl;
		  cin>>b; 
	 a1.setvertex(a,b);
	 cout << "修改成功！" << endl;	
	 	cout << "\n\n按回车键返回至导航系统界面\n\n";
		getchar(); getchar();
		menu();
		break;
	case 8:
	 	cout<<"欢迎下次使用!";
	 	return ;
  	}
	
}

int main()
{

	menu();
	return 0;
}
