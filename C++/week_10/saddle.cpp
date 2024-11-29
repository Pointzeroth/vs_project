#include <iostream>  
#include <vector>  

using namespace std;  

void findSaddlePoints(const vector<vector<int>>& matrix) {  
    int n = matrix.size();       // 行数  
    if (n == 0) return;          // 如果矩阵为空，直接返回  
    int m = matrix[0].size();    // 列数  

    // 遍历每一行  
    for (int i = 0; i < n; ++i) {  
        int minElement = matrix[i][0];  
        int minIndex = 0;  

        // 找到第 i 行的最小元素  
        for (int j = 1; j < m; ++j) {  
            if (matrix[i][j] < minElement) {  
                minElement = matrix[i][j];  
                minIndex = j;  
            }  
        }  

        // 检查这个最小元素是否是第 minIndex 列的最大元素  
        bool isSaddlePoint = true;  
        for (int k = 0; k < n; ++k) {  
            if (matrix[k][minIndex] > minElement) {  
                isSaddlePoint = false;  
                break;  
            }  
        }  

        // 如果是鞍点，输出  
        if (isSaddlePoint) {  
            cout << "Saddle Point found at (" << i + 1 << ", " << minIndex + 1 << ") with value " << minElement << endl;  
        }  
    }  
}  

int main() {  
    // 示例矩阵  
    vector<vector<int>> matrix = {  
        {1, 2, 3},  
        {4, 5, 6},  
        {7, 8, 9}  
    };  

    findSaddlePoints(matrix);  

    return 0;  
}