#include <iostream>  
using namespace std;  

int main() {  
    int rows;  

    // 输入行数  
    cout << "input: ";  
    cin >> rows;  

    int number = 1; // 从 1 开始递增  
    for (int i = 1; i <= rows; ++i) {  
        // 打印每一行的数字  
        for (int j = 1; j <= i; ++j) {  
            cout << number << " ";  
            number++; // 每打印一个数字，递增  
        }  
        cout << endl; // 换行  
    }  

    return 0;  
}