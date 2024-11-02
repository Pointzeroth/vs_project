#include "seqlist.h"
#include <iostream>
using namespace std;

template <typename T> class seqlist;

template <typename T>
seqlist<T>::seqlist()
{
    length = 0;
}

template <typename T>
seqlist<T>::seqlist(T a[], int n)
{
    if(n > Max)
        throw "Error";
    for(int i = 0; i < n; i++)
    {
        data[i] = a[i];
    }
    length = n;
}

template <typename T>
seqlist<T>::~seqlist()
{

}

template <typename T>
int seqlist<T>::getlength()
{
    return length;
}

template <typename T>
void seqlist<T>::px(T a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

template <typename T>  
void seqlist<T>::reverse(T a[], int n) {  
    int left = 0;                    // 左指针  
    int right = n - 1;         // 右指针  
    while (left < right) {  
        // 交换 data[left] 和 data[right]  
        T temp = a[left];  
        a[left] = a[right];  
        a[right] = temp;  
        left++;                     // 左指针向右移动  
        right--;                    // 右指针向左移动  
    }  
}