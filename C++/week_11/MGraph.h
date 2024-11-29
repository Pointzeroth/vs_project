using namespace std;
/****************************** 
   邻接矩阵类MGraph的类定义 
*******************************/
const int MaxSize = 10;                   //图中最多顶点个数
int visited[MaxSize] = {0};              //全局数组变量visited初始化
template <class DataType>
class MGraph
{
public:
   MGraph(DataType a[ ], int n, int e);     //构造函数，建立具有n个顶点e条边的图
   ~MGraph( ){ };                        //析构函数
   void DFTraverse(int v);               //深度优先遍历图
   void BFTraverse(int v);               //广度优先遍历图
private:
    DataType vertex[MaxSize];           //存放图中顶点的数组
    int edge[MaxSize][MaxSize];           //存放图中边的数组
    int vertexNum, edgeNum;              //图的顶点数和边数
 };

 /******************************** 
   邻接矩阵类MGraph的构造函数 
*********************************/
template <class DataType>
MGraph<DataType> :: MGraph(DataType a[ ], int n, int e) 
{
   	int i, j, k;
   	vertexNum = n; edgeNum = e;
   	for (i = 0; i < vertexNum; i++)          //存储顶点
   		vertex[i] = a[i];
   	for (i = 0; i < vertexNum; i++)          //初始化邻接矩阵
 		for (j = 0; j < vertexNum; j++)
   			edge[i][j] = 0;             
   	for (k = 0; k < edgeNum; k++)           //依次输入每一条边
   	{
   		cout << "input:";
		cin >> i >> j;                       //输入边依附的两个顶点的编号
		edge[i][j] = 1; edge[j][i] = 1;           //置有边标志
   	}
}

/*********************************** 
   邻接矩阵类MGraph的深度优先遍历 
************************************/
template <class DataType>
void MGraph<DataType> :: DFTraverse(int v)  
{
	cout << vertex[v]; visited[v] = 1;
	for (int j = 0; j < vertexNum; j++)
		if (edge[v][j] == 1 && visited[j] == 0) DFTraverse( j );
}

/*********************************** 
   邻接矩阵类MGraph的广度优先遍历 
************************************/
template <class DataType>
void MGraph<DataType> :: BFTraverse(int v) 
{
	int w, j, Q[MaxSize];                   //采用顺序队列
	int front = -1, rear = -1;                 //初始化队列
 	cout << vertex[v]; visited[v] = 1; Q[++rear] = v;   //被访问顶点入队
 	while (front != rear)                    //当队列非空时
 	{
	   	w = Q[++front];                    //将队头元素出队并送到v中
   	 	for (j = 0; j < vertexNum; j++)
       	if (edge[w][j] == 1 && visited[j] == 0 ) {
        	cout << vertex[j]; visited[j] = 1; Q[++rear] = j;
       	}
    }
}