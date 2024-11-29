#include <iostream>
#include "ALGraph.h"

int main( )
{
	//测试数据是图6-20(a)，边是(0 1)(0 3)(0 4)(1 2)(2 4)(3 2)(3 4)
	char ch[ ] = {'A','B','C','D','E' ,'F'};
	int i;
	ALGraph<char> ALG(ch, 6, 9);               //建立具有5个顶点6条边的有向图
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout << "shendu:";
	ALG.DFTraverse(0);                       //从顶点0出发进行深度优先遍历
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout << "guangdu:"; 
	ALG.BFTraverse(0);                      //从顶点0出发进行广度优先遍历
	return 0;
}
