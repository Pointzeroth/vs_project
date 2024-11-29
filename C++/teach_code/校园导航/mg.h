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
	void setzero();//��visited�������� 
    void DFSTravese(int v);
  	void Floyd(int v1,int v2);//**
	void setarc(int v1, int v2, int arclen);
	void putoutarc();
	void putoutvertex();
    void setvertex(int x,string y);//�޸ĵص����� 
private:
	T vertex[MaxSize];
	int visited[MaxSize];
	int dist[MaxSize][MaxSize];
	string path[MaxSize][MaxSize];
	int arc[MaxSize][MaxSize];
	int vertexNum, arcNum;
};
