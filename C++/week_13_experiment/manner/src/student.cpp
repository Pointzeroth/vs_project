#pragma once
#include "../include/student.h"

// // 构造函数实现  
// template <typename T>  
// Contact<T>::Contact(T n, T p, T s, T b, T c) : name(n), num(p), sex(s), born(b), addr(c), next(nullptr) {}  

// 构造函数实现  
template <typename T>  
Contact<T>::Contact(T n, T p, T s, T b, T c)
{
    name = n;
    num = p;
    sex = s;
    born = b;
    addr = c;
    next = nullptr;
}
