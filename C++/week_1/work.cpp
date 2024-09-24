#include <iostream>  
using namespace std;  

// 函数计算最大公约数  
int gcd(int a, int b) {  
    return b == 0 ? a : gcd(b, a % b);  
}  

// 函数计算最小公倍数  
int lcm(int a, int b) {  
    return (a * b) / gcd(a, b);  
}  

int main() {  
    int num1, num2;  
    cout << "input: ";  
    cin >> num1 >> num2;  

    int result = lcm(num1, num2);  
    cout << "is: " << result << endl;  

    return 0;  
}
