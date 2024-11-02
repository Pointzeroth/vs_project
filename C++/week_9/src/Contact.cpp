#pragma once
#include "../include/Contact.h"

// 构造函数实现  
template <typename T>  
Contact<T>::Contact(T n, T p) : name(n), phonenumber(p), next(nullptr) {}  

