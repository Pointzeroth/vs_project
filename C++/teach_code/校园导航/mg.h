#include<iostream>
#include <string>
using namespace std;

const int MaxSize = 100;
template<class T>
class mg
{
public:
	mg(T a[], int n, int e);
	~mg();
	void setzero();//将visited数组置零 
    void DFSTravese(int v);
  	void Floyd(int v1,int v2);//**
	void setarc(int v1, int v2, int arclen);
	void putoutarc();
	void putoutvertex();
    void setvertex(int x,string y);//修改地点名称 
private:
	T vertex[MaxSize];
	int visited[MaxSize];
	int dist[MaxSize][MaxSize];
	string path[MaxSize][MaxSize];
	int arc[MaxSize][MaxSize];
	int vertexNum, arcNum;
};
