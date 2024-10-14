### 何为指针？
指针是一个整数，一种储存地址的数。与指针的类型无关。所有的指针都是保存内存地址的数字。
想象内存是一条线性的街道，在这个街道上每栋房子都有自己的门牌号。

```cpp
#include <iostream>
#define LOG(x) std::cout << x << std::endl

int main()
{
    int var = 8;
    void* ptr = nullptr;       //定义了一个无类型的指针，它的内存地址是0    NULL/nullptr，不能直接赋值0，0地址是无意义的。
    std::cin.get();
}
```
#### 下一步
```cpp
int main()
{
    int var = 8;
    void* ptr = &var;      此时ptr的内容是变量var的地址。当使用dubug查找该地址的内存时，会发现此时内存的值是8，并且是4个字节的数据，因为32位系统下一个整数是4个字节
    std::cin.get();        此时若是将指针类型从void改为int，进入debug后会发现跟void下没什么区别。可知类型无关紧要。
}
```
#### 类型对内存的操作很有用处。
1. 若想对指针指向的内存进行操作的时候，就需要靠逆向引用了（指针的*运算通常被认为dereference运算符）
2 .当需要对指针指向的内存进行操作时,就需要用到类型了，因为若是void类型，即无类型指针，编译器无法知道你要写入的数字是什么类型的，它可能是short类型，long类型，longlong类型？
```cpp
int main()
{
    int var = 8;
    int* ptr = &var;
    *ptr = 10;              逆引用，此时对内存写入一个int型的数字10。
    LOG(var);                结果是，成功将var从8改成了10
    std::cin.get();
}
```

#### char是一个字节
```cpp
int main()
{
    char* buffer = newchar[8];          newchar[8]真正要求的是8字节的内存,这里我们分配了8个字节的内存，并返回一个指向那块内存开始的指针。
    memset(buffer, 0, 8);               memset可以用指定的数据来填充内存块。
                                        顺带一提，指针也是变量，变量就存在内存里，那么就有了双指针，三指针的出现。
    char** ptr = &buffer;               指针的指针。debug里看 ptr是地址，*ptr地址下内存的值，该值是一个另一个变量的地址，再用逆引用*即可查看地址下的内容，
                                        即buffer被设置后的00 00 00 00 00 00 00 00。
    delete[] buffer;
}
```
