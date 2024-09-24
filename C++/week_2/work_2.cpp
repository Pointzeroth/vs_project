#include <iostream>  
using namespace std;  

// 使用整型变量作为参数  
void findMaxAndSecondMax(int arr[], int n) {  
    int maxVal, secondMaxVal;
    maxVal = secondMaxVal = INT_MIN; // 初始化为最小值  
    for (int i = 0; i < n; i++) {  
        if (arr[i] > maxVal) {  
            secondMaxVal = maxVal; // 更新次大值  
            maxVal = arr[i];       // 更新最大值  
        } else if (arr[i] > secondMaxVal && arr[i] < maxVal) {  
            secondMaxVal = arr[i]; // 更新次大值  
        }  
    }
    cout << "max: " << maxVal << ", second: " << secondMaxVal << endl; 
}  

// 使用指针变量作为参数  
void findMaxAndSecondMaxPtr(int *arr, int n, int *maxVal, int *secondMaxVal) {  
    *maxVal = *secondMaxVal = INT_MIN; // 初始化为最小值  
    for (int i = 0; i < n; i++) {  
        if (arr[i] > *maxVal) {  
            *secondMaxVal = *maxVal; // 更新次大值  
            *maxVal = arr[i];        // 更新最大值  
        } else if (arr[i] > *secondMaxVal && arr[i] < *maxVal) {  
            *secondMaxVal = arr[i];  // 更新次大值  
        }  
    }  
}  

// 使用引用作为参数  
void findMaxAndSecondMaxRef(int (&arr)[10], int &maxVal, int &secondMaxVal) {  
    maxVal = secondMaxVal = INT_MIN; // 初始化为最小值  
    for (int i = 0; i < 10; i++) {  
        if (arr[i] > maxVal) {  
            secondMaxVal = maxVal; // 更新次大值  
            maxVal = arr[i];       // 更新最大值  
        } else if (arr[i] > secondMaxVal && arr[i] < maxVal) {  
            secondMaxVal = arr[i]; // 更新次大值  
        }  
    }  
}  

int main() {  
    int arr[10];  
    int maxVal, secondMaxVal;  

    // 输入数组元素  
    cout << "input:";  
    for (int i = 0; i < 10; i++) {  
        cin >> arr[i];  
    }  

    // 使用整型变量  
    findMaxAndSecondMax(arr, 10);  
     
    // 使用指针变量  
    findMaxAndSecondMaxPtr(arr, 10, &maxVal, &secondMaxVal);  
    cout << "max: " << maxVal << ", second: " << secondMaxVal << endl;  

    // 使用引用  
    findMaxAndSecondMaxRef(arr, maxVal, secondMaxVal);  
    cout << "max: " << maxVal << ", second: " << secondMaxVal << endl;  

    return 0;  
}