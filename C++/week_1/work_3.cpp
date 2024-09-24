#include <iostream>  
using namespace std;  

int main() {  
    double num1, num2; // 使用 double 以支持小数  
    char operation;  

    // 输入两个数字  
    cout << "input num1: ";  
    cin >> num1;  
    cout << "input num2: ";  
    cin >> num2;  

    // 输入运算符  
    cout << "input (+, -, *, /): ";  
    cin >> operation;  

    // 根据运算符执行相应的运算  
    switch (operation) {  
        case '+':  
            cout << "result: " << num1 + num2 << endl;  
            break;  
        case '-':  
            cout << "result: " << num1 - num2 << endl;  
            break;  
        case '*':  
            cout << "result: " << num1 * num2 << endl;  
            break;  
        case '/':  
            // 检查除数是否为零  
            if (num2 != 0) {  
                cout << "result: " << num1 / num2 << endl;  
            } else {  
                cout << "err" << endl;  
            }  
            break;  
        default:  
            cout << "err" << endl;  
            break;  
    }  

    return 0;  
}