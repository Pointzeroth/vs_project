#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <climits>  
#include <set>  

using namespace std;  

// 边的结构  
struct Edge {  
    char u;  
    char v;  
    int weight;  
};  

// 比较函数，用于排序  
bool compareEdges(const Edge &a, const Edge &b) {  
    return a.weight < b.weight;  
}  

// Prim算法  
vector<Edge> prim(vector<Edge>& edges, int numVertices, char start) {  
    vector<Edge> mstEdges;  
    vector<bool> inMST(numVertices, false);  
    vector<int> minEdge(numVertices, INT_MAX);  
    minEdge[start - 'a'] = 0;  

    for (int i = 0; i < numVertices; ++i) {  
        // 找到权重最小的边  
        int u = -1;  
        for (int j = 0; j < numVertices; ++j) {  
            if (!inMST[j] && (u == -1 || minEdge[j] < minEdge[u])) {  
                u = j;  
            }  
        }  

        // 将选择的边加入MST  
        inMST[u] = true;  
        for (const auto& edge : edges) {  
            if (edge.u - 'a' == u && !inMST[edge.v - 'a'] && edge.weight < minEdge[edge.v - 'a']) {  
                minEdge[edge.v - 'a'] = edge.weight;  
                mstEdges.push_back(edge);  
            }  
            if (edge.v - 'a' == u && !inMST[edge.u - 'a'] && edge.weight < minEdge[edge.u - 'a']) {  
                minEdge[edge.u - 'a'] = edge.weight;  
                mstEdges.push_back(edge);  
            }  
        }  
    }  

    return mstEdges;  
}  

// 并查集，用于Kruskal算法  
class DisjointSet {  
public:  
    DisjointSet(int n) {  
        parent.resize(n);  
        for (int i = 0; i < n; ++i) {  
            parent[i] = i;  
        }  
    }  

    int find(int u) {  
        if (parent[u] != u)  
            parent[u] = find(parent[u]); // 路径压缩  
        return parent[u];  
    }  

    void unionSet(int u, int v) {  
        parent[find(u)] = find(v);  
    }  

private:  
    vector<int> parent;  
};  

// Kruskal算法  
vector<Edge> kruskal(vector<Edge>& edges, int numVertices) {  
    vector<Edge> mstEdges;  
    DisjointSet ds(numVertices);  

    sort(edges.begin(), edges.end(), compareEdges);  

    for (const auto& edge : edges) {  
        int u = edge.u - 'a';  
        int v = edge.v - 'a';  
        if (ds.find(u) != ds.find(v)) {  
            ds.unionSet(u, v);  
            mstEdges.push_back(edge);  
        }  
    }  

    return mstEdges;  
}  

int main() {  
    // 构建图  
    vector<Edge> edges = {  
        {'a', 'b', 6},  
        {'a', 'c', 3},  
        {'b', 'f', 5},  
        {'c', 'e', 6},  
        {'e', 'f', 2},  
        {'c', 'd', 6},  
        {'b', 'd', 1},  
        {'d', 'f', 5}  
    };  

    int numVertices = 6; // a, b, c, d, e, f: 6个顶点  

    // Prim算法  
    vector<Edge> primResult = prim(edges, numVertices, 'a');  
    cout << "Prim's MST result:\n";  
    for (const auto& edge : primResult) {  
        cout << edge.u << " - " << edge.v << ": " << edge.weight << endl;  
    }  

    // Kruskal算法  
    vector<Edge> kruskalResult = kruskal(edges, numVertices);  
    cout << "\nKruskal's MST result:\n";  
    for (const auto& edge : kruskalResult) {  
        cout << edge.u << " - " << edge.v << ": " << edge.weight << endl;  
    }  

    return 0;  
}