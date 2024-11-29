#pragma once

#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 100;
extern int INF;

class Map
{
    private:
        int map[MAX_SIZE][MAX_SIZE];
        string ver[MAX_SIZE];
    public:
        Map()
        {
            for (int i = 0; i < MAX_SIZE; i++)
            {
                for (int j = 0; j < MAX_SIZE; j++)
                {
                    map[i][j] = 0;
                }
            }
        }

        Map(string a[], int **b, int n, int m)
        {
            for(int i =0; i < n; i++)
            {
                ver[i] = a[i];
                for(int j = 0; j < m; j++)
                {
                    map[i][j] = b[i][j];
                }
            }
            cout << endl << endl;
        }

        void setMap(int m, int n)
        {
            int x;
            cout << "Enter the x coordinate: " << endl;
            cin >> x;
            map[m][n] = x;
            map[n][m] = x;
            cout << "the distance is "<<x<<" now." << endl;
            cout << endl << endl;
        }

        void printMap(int n, int m)
        {
            cout << map[n][m] << endl;
            cout << "the distance is "<<map[n][m]<<" now." << endl;
            cout << endl << endl;
        }

        void watchMap()
        {
            cout<<"                    _C______"<<map[2][3]<<"______D_"<<endl;
            cout<<"                   // \\           ||"<<endl;
            cout<<"                " <<map[0][2]<<" //   \\_"<<map[1][2]<<"__      ||"<<endl;
            cout<<"                 //          \\    ||"<<map[1][3]<<endl;
            cout<<"                //            \\   ||"<<endl;
            cout<<"               A______"<<map[0][1]<<"_______\\__B"<<endl;
            cout<<endl<<endl;
            cout << endl;

            cout << "Points:" << endl;  
            cout << "0: A" << '\t' << "1: B" << '\t' << "2: C" << '\t' << "3: D" << endl;  

            // Print distances  
            cout << "Distances:" << endl;  
            if (map[0][1] != INF) cout << "A-B: " << map[0][1] << endl;  
            else cout << "A-B: No edge" << endl;  
            if (map[0][2] != INF) cout << "A-C: " << map[0][2] << endl;  
            else cout << "A-C: No edge" << endl;  
            if (map[1][3] != INF) cout << "B-D: " << map[1][3] << endl;  
            else cout << "B-D: No edge" << endl;  
            if (map[1][2] != INF) cout << "B-C: " << map[1][2] << endl;  
            else cout << "B-C: No edge" << endl;  
            if (map[2][3] != INF) cout << "C-D: " << map[2][3] << endl;  
            else cout << "C-D: No edge" << endl;     
        }

        void min(int** dist, string** path, int m, int n, int a)
        {
            // 初始化距离矩阵和路径矩阵
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dist[i][j] = map[i][j];
                    if(dist[i][j] != 1000 && dist[i][j] != 0)
                    {
                        path[i][j] = ver[i] + "->" + ver[j];
                    }
                    else
                    {
                        path[i][j] = "";
                    }
                }
            }

            // Floyd-Warshall算法核心部分
            for(int k = 0; k < a; k++)
            {
                for(int l = 0; l < m; l++)
                {
                    for(int s = 0; s < n; s++)
                    {
                        if(dist[l][s] > dist[l][k] + dist[k][s])
                        {
                            dist[l][s] = dist[l][k] + dist[k][s];
                            path[l][s] = path[l][k] + "->" + path[k][s];
                        }
                    }
                }
            }
        }
};