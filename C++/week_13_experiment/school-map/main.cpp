#include "./include/map.h"
#include "./include/school.h"
 
int INF = 1000; // Represents no connection  

int adistance[4][4] = 
{  
    {0, 10, 5, INF},  // A (0) -> A, A -> B, A -> C, A -> D  
    {10, 0, 2, 1},    // B (1) -> A, B -> B, B -> C, B -> D  
    {5, 2, 0, 9},     // C (2) -> A, C -> B, C -> C, C -> D  
    {INF, 1, 9, 0}    // D (3) -> A, D -> B, D -> C, D -> D  
};  

int main() 
{
    string locations[] = {"A", "B", "C", "D"};  
    cout << endl;     
    cout<<"	*************************************					"<<endl;
    cout<<"	*      welcome to use the map       *                   "<<endl; 
    cout<<"	*************************************					"<<endl;
    cout<<endl;
    cout<<"        the map is like this:"       <<endl;
    cout<<"                    _C______9______D_"<<endl;
    cout<<"                   // \\           ||"<<endl;
	cout<<"                 5//   \\__2__     ||"<<endl;
    cout<<"                 //          \\    ||1"<<endl;
	cout<<"                //            \\   ||"<<endl;
    cout<<"               A_____10________\\__B"<<endl;
	cout<<endl<<endl;

    // 按键
    int x ,n ,m;

    // 指向距离的指针数组  
    int *dist[4];  
    for (int i = 0; i < 4; i++) {  
        dist[i] = adistance[i];  
    }  

    // 创建 Map 对象，传递地点名称和距离矩阵  
    Map myMap(locations, dist, 4, 4);  

    while(1)
    {
        {
            cout<<"1:watch the map"<<endl;
            cout<<"2:query the distance between two places"<<endl;
            cout<<"3:change the distance between two places"<<endl;
            cout<<"4:find the shortest path between two places"<<endl;
            cout<<"0:exit"<<endl;
            cout<<endl;

            cin>>x;
            switch(x)
            {
                case 1:
                    {
                        //printMap();
                        myMap.watchMap();
                    }
                    break;
                case 2:
                    {
                        cout<<"A:0, B:1, C:2, D:3"<<endl<<endl; 
                        cout<<"input the two places you want to query:";
                        cout<<"exmaple: input 0 1 to query the distance between A and B"<<endl<<endl;
                        cin>>n>>m;
                        myMap.printMap(n,m);
                    }
                    break;
                case 3:
                    {
                        cout<<"A:0, B:1, C:2, D:3"<<endl<<endl; 
                        cout<<"input the two places you want to change the distance:"<<endl;
                        cout<<"example: 0 1 to change the distance between A and B"<<endl;
                        cin>>n>>m;
                        myMap.setMap(n,m);
                    }
                    break;
                case 4:
                    {
                        cout<<"A:0, B:1, C:2, D:3"<<endl<<endl; 
                        // 为结果分配动态内存  
                        int **distMatrix = new int*[4];  
                        string **pathMatrix = new string*[4];  
                        for (int i = 0; i < 4; i++) {  
                            distMatrix[i] = new int[4];  
                            pathMatrix[i] = new string[4];  
                        } 
                        // 使用 Floyd-Warshall 算法计算最短路径  
                        myMap.min(distMatrix, pathMatrix, 4, 4, 4);  

                        // 用户输入起始和目标地点  
                        char start, end;  
                        cout << "input start position(A,B,C,D):";  
                        cin >> start;  
                        cout << "input end position(A,B,C,D):";  
                        cin >> end;  

                        // 将字符转换为数组索引  
                        int startIndex = start - 'A'; // 将字符 A 转换为 0，B 转换为 1，以此类推  
                        int endIndex = end - 'A';  

                        // 检查用户输入的有效性  
                        if (startIndex < 0 || startIndex >= 4 || endIndex < 0 || endIndex >= 4) {  
                            cout << "input error" << endl;  
                        } else {  
                            // 打印最短路径和距离  
                            cout << "from " << start << " to " << end << " the shortest path is: " << pathMatrix[startIndex][endIndex] << endl;  
                            cout << "the shortest distance is: " << distMatrix[startIndex][endIndex] << endl;  
                        }  
                        // 释放动态分配的内存  
                        for (int i = 0; i < 4; i++) {  
                            delete[] distMatrix[i];  
                            delete[] pathMatrix[i];  
                        }  
                        delete[] distMatrix;  
                        delete[] pathMatrix;  

                    }
                    break;	
                case 0:
                    break;
                default :
                    cout<<"input error"<<endl;
                    break;
            }
            if(x == 0)
                break;
        }
    }
    return 0;
}
 