#include "seqlist.h"
#include <iostream>
using namespace std;

// 示例使用  
int main() {  
    int arr[] = {5, 2, 4, 3, 1};  
    seqlist<int> list(arr, 5);  
    
    cout << "Original list: ";  
    for (int i = 0; i < list.getlength(); i++) {  
        cout << arr[i] << " ";  
    }  
    cout << endl;  

    list.px(arr ,5);
    cout << "sort list:";
    for (int i = 0; i < list.getlength(); i++) {  
        cout << arr[i] << " ";  
    }  
    cout << endl;  

    list.reverse(arr, 5); // 逆置顺序表  
    cout << "Reverse list: ";  
    for (int i = 0; i < list.getlength(); i++) {  
        cout << arr[i] << " ";  
    }  
    cout << endl;  

    return 0;  
}  