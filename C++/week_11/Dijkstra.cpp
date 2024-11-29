#include <iostream>  
#include <vector>  
#include <queue>  
#include <limits>  

using namespace std;  

const int MAX_VERTICES = 7; // 图的最大顶点数  
const int INF = numeric_limits<int>::max(); // 表示无穷大  

class Graph {  
private:  
    vector<pair<int, int>> adj[MAX_VERTICES]; // 邻接表，pair<目标顶点, 权值>  

public:  
    void addEdge(int src, int dest, int weight) {  
        adj[src].emplace_back(dest, weight); // 添加边到邻接表  
    }  

    void dijkstra(int start) {  
        vector<int> dist(MAX_VERTICES, INF); // 最短路径数组  
        vector<bool> visited(MAX_VERTICES, false); // 判断顶点是否已访问  
        dist[start] = 0; // 起始点到自身的距离为0  

        // 优先队列，存储 {最短路径, 顶点}  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  
        pq.push(make_pair(0, start)); // 将起始点加入队列  

        while (!pq.empty()) {  
            int u = pq.top().second; // 获取队列中最小距离的顶点  
            pq.pop();  

            if (visited[u]) continue; // 如果已经访问，跳过  
            visited[u] = true; // 标记为已访问  

            // 遍历当前顶点的邻接顶点  
            for (auto& edge : adj[u]) {  
                int v = edge.first; // 目标顶点  
                int weight = edge.second; // 边的权值  

                // 放松操作  
                if (dist[u] + weight < dist[v]) {  
                    dist[v] = dist[u] + weight; // 更新最短路径  
                    pq.push(make_pair(dist[v], v)); // 重新加入队列  
                }  
            }  
        }  

        // 打印结果  
        cout << "从顶点v" << start + 1 << "到各顶点的最短路径：\n";  
        for (int i = 0; i < MAX_VERTICES; ++i) {  
            if (dist[i] == INF) {  
                cout << "v" << i + 1 << ": 没有可达路径\n";  
            } else {  
                cout << "v" << i + 1 << ": " << dist[i] << "\n";  
            }  
        }  
    }  
};  

int main() {  
    Graph g;  

    // 添加边和权值  
    g.addEdge(0, 4, 11); // v1 -> v5, 权重 11  
    g.addEdge(0, 6, 7);  // v1 -> v7, 权重 7  
    g.addEdge(1, 2, 8);  // v2 -> v3, 权重 8  
    g.addEdge(3, 1, 10); // v4 -> v2, 权重 10  
    g.addEdge(3, 5, 7);  // v4 -> v5, 权重 7  
    g.addEdge(3, 4, 3);  // v4 -> v6, 权重 3  
    g.addEdge(5, 3, 10); // v6 -> v5, 权重 10  
    g.addEdge(6, 3, 9);  // v6 -> v3, 权重 9  
    g.addEdge(6, 4, 6);  // v7 -> v4, 权重 6  
    g.addEdge(6, 1, 15); // v7 -> v2, 权重 15  

    // 从顶点 v1 计算最短路径 (索引0)  
    g.dijkstra(0);   
    
    return 0;  
}