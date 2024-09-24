#include <iostream>  
using namespace std;  

int main() {  
    const int MIN = 1; // 最小值  
    const int MAX = 4; // 最大值  

    // 创建一个数组来存储每个整数的出现次数  
    int count[MAX + 1] = {0}; // 初始化为0

    int number;  

    cout << "input num(1~4):" << endl;  

    // 循环输入整数  
    while (true) {  
        cin >> number;  
        // 检查输入的数字是否在有效范围内  
        if (number >= MIN && number <= MAX) {  
            count[number]++; // 增加对应数字的计数  
        } 
        //输出1~4之外的数结束统计
        else {  
            cout << "end" << endl;  
            break;
        }  
    }  
    // 输出每个整数的出现次数  
    cout << "TIME:" << endl;  
    for (int i = MIN; i <= MAX; ++i) {  
        cout << i << ": " << count[i] << " time" << endl;  
    }  

    return 0;  
}