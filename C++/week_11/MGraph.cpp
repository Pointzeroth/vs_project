#include <iostream>
#include  "MGraph.h"

int main( )
{
	int i;
	char ch[ ]={'A','B','C','D','E' ,'F'};       
	/* 测试数据六条边是：(0 1)(0 2)(0 3)(0 4)(1 2)(2 4)  */  
	MGraph<char> MG{ch, 6, 9};              //建立具有5个顶点6条边的无向图
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout << "shendu:\n" << endl;
	MG.DFTraverse(0);                     //从顶点0出发进行深度优先遍历
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
    cout << "guangdu\n" << endl;
	MG.BFTraverse(0);                     //从顶点0出发进行广度优先遍历
	return 0;
}
