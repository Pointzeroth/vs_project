#include <iostream>  
using namespace std;  

void move(int b[], int n)
{
    int i, k, t;
    k = 0;
    for(i = 1;i < n;i ++)
    {
        if(b[k] > b[i])
            k = i;
    }
    t = b[k];
    b[k] = b[0];
    b[0] = t;
}

int main()
{
    int a[10];
    int i;
    
    for(i = 0; i < 10; i ++)
        cin >> a[i];
    move(a , 10);
    cout << a[0] << endl;

    return 0 ;
}

void bubbleSort(int arr[], int n) {  
    for (int i = 0; i < n - 1; i++) {  
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {  
                // 交换 arr[j] 和 arr[j + 1]  
                int temp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = temp;  
            }  
        }  
    }  
}  

// int main() {  
//     int arr[] = {64, 34, 25, 12, 22, 11, 90};  
//     int n = sizeof(arr) / sizeof(arr[0]);  
    
//     bubbleSort(arr, n);  
    
//     cout << "排序后的数组: ";  
//     for (int i = 0; i < n; i++)  
//         cout << arr[i] << " ";  
//     cout << endl;  

//     return 0;  
// }