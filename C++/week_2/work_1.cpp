#include <iostream>  
using namespace std;  

// 数组形式的排序函数  
void sortArray(int arr[], int size) {  
    for (int i = 0; i < size - 1; i++) {  
        for (int j = 0; j < size - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {  
                // 交换  
                int temp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = temp;  
            }  
        }  
    }  
}  

// 指针形式的排序函数  
void sortArrayPointer(int* arr, int size) {  
    for (int i = 0; i < size - 1; i++) {  
        for (int j = 0; j < size - i - 1; j++) {  
            if (*(arr + j) > *(arr + j + 1)) {  
                // 交换  
                int temp = *(arr + j);  
                *(arr + j) = *(arr + j + 1);  
                *(arr + j + 1) = temp;  
            }  
        }  
    }  
}  

// 主函数  
int main() {  
    int arr1[] = {5, 3, 8, 1, 2};  
    int size1 = sizeof(arr1) / sizeof(arr1[0]);  
    //sizeof(arr1) / sizeof(arr1[0])：通过将整个数组的字节数除以单个元素的字节数，可以得到数组中元素的个数。这个计算的结果就是数组的大小
    // 使用数组形式的排序  
    sortArray(arr1, size1);  
    cout << "Sorted array using array function: ";  
    for (int i = 0; i < size1; i++) {  
        cout << arr1[i] << " ";  
    }  
    cout << endl;  

    int arr2[] = {9, 7, 6, 4, 5};  
    int size2 = sizeof(arr2) / sizeof(arr2[0]);  

    // 使用指针形式的排序  
    sortArrayPointer(arr2, size2);  
    cout << "Sorted array using pointer function: ";  
    for (int i = 0; i < size2; i++) {  
        cout << arr2[i] << " ";  
    }  
    cout << endl;  

    return 0;  
}

/******************************************************************************************************************
void swap(int a)  
{  
    a = 5;  
}

这个 swap 函数接受一个整型参数 a。在 C++ 中，函数参数是按值传递的，
这意味着在函数内部对 a 的任何修改不会影响到调用该函数时传入的变量。

int main()  
{  
    int a = 10; // 初始化 a 为 10  

    swap(a); // 调用 swap 函数，传入 a 的值（10）  

    while(1); // 无限循环  
}

在 main 函数中，a 被初始化为 10。
当调用 swap(a) 时，a 的值（10）被复制到函数参数 a 中。函数内部将这个参数 a 的值修改为 5，但这并不会影响到 main 函数中的 a。
因此，a 最后的值是 10。

*******************************************************************************************************************/
