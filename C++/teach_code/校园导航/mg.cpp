#include "mg.h"
#include<string>
#include <iostream>
using namespace std;
#define INF 9999


template<class T>
mg<T>::mg(T a[], int n, int e)
{
	vertexNum = n;  arcNum = e;
	int i, j;
	for (i = 0; i < vertexNum; i++)
		vertex[i] = a[i];
	for (i = 0; i < vertexNum; i++)
		for (j = 0; j < vertexNum; j++)
			arc[i][j] = INF;
	arc[0][1] = arc[1][0] = 880;	arc[0][2]=arc[2][0]=580;	arc[0][5]=arc[5][0]=1100;
	arc[1][3]=arc[3][1]=230;        arc[1][2]=arc[2][1]=310;    arc[1][5]=arc[5][1]=200;
    arc[2][6]=arc[6][2]=470;        arc[2][4]=arc[4][2]=230;
    arc[3][4]=arc[4][3]=460;        arc[3][5]=arc[5][3]=360;

}



template<class T>
mg<T>::~mg()
{

}

template<class T>
void mg<T>::setzero()
{
	for(int i=0;i<vertexNum;i++)
	visited[i]=0;
}


template<class T>
void mg<T>::DFSTravese(int v)
{
	cout << vertex[v]; visited[v] = 1;
	
	
		for (int j = 0; j < vertexNum; j++)
		{
			if (arc[v][j] != INF && visited[j] == 0)
			{
			cout<<"->";DFSTravese(j);}
		
		}
		
}

template<class T>
void mg<T>::putoutvertex()
{
	for (int i = 0; i < vertexNum; i++)
		cout <<i+1<< vertex[i]<<" ";
}



template<class T>
void mg<T>::putoutarc()
{
	int i, j;

	for (i = 0; i < vertexNum; i++)
		for (j = 0; j < vertexNum; j++)
		{
			if(arc[i][j]==INF) cout<<"";
			else
			cout << vertex[i] << "->" << vertex[j] << "距离为：" << arc[i][j] << endl;
		}


}
template <class T>
void mg<T>::setvertex(int x,string y)
{
	vertex[x-1]=y;
}


template<class T>
void mg<T>::setarc(int v1, int v2, int arclen)
{
	if(arc[v1-1][v2-1]==INF) cout<<"在无直接路径的两点间添加路径。";
	arc[v1 - 1][v2 - 1] = arc[v2 - 1][v1 - 1] = arclen;
	cout << "修改成功！" << endl;


}

template<class T>
void mg<T>::Floyd(int v1,int v2)
{
	int i ,j ,k;
	for ( i = 0; i < vertexNum; i++)
		for ( j = 0; j < vertexNum; j++)
		{
			dist[i][j] = arc[i][j];
			if(dist[i][j]!=INF && dist[i][j]!=0)  path[i][j]= vertex[i]+"->"+vertex[j];
			else path[i][j]="";
		}
	for ( k = 0; k < vertexNum; k++)
		for ( i = 0; i < vertexNum; i++)
			for ( j = 0; j < vertexNum; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j]=path[i][k]+"->"+path[k][j];
				}
				cout<<"最短路径长度为："<< dist[v1-1][v2-1]<<endl;
				cout<<"最短路径为："<< path[v1-1][v2-1]<<endl; 
	
							
}

