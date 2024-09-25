#include <iostream>
#include<stdexcept>
#include <functional>
#include <vector>

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

# define MAXSIZE 100   //默认优先队列的最大长度

template <class T,class Container=std::vector<T>,class comp=std::less<T>>  //默认使用vector作为容器，默认使用less作为比较函数(如果使用其他的特定类型，需要重载比较函数)
class Priority_Queue
{
    public:
    using size_type = typename Container::size_type;  // 容器的大小类型
    using value_type = typename Container::value_type;  // 容器的值类型
    using reference = typename Container::reference;  // 容器的引用类型
    using const_reference = typename Container::const_reference;  // 容器的常量引用类型
    private:
    Container c;  //优先队列的容器
    comp comp_;  //比较函数
    size_type max_size=MAXSIZE;  //优先队列的最大长度
    size_type size_=0;  //优先队列的当前长度

    void up(int u)  //上浮操作
    {
        while(u>0&&comp_(c[u],c[u/2]))
        {
            std::swap(c[u],c[u/2]);
            u/=2;
        }
    }

    void down(int i)  //下沉操作
    {
        int u=i;
        if(i*2<size_&&comp_(c[i*2],c[u])) u=i*2;
        if(i*2+1<size_&&comp_(c[i*2+1],c[i*2])) u=i*2+1;
        if (i!=u)
        {
            std::swap(c[i],c[u]);
            down(u);
        }
    }

    public:
    Priority_Queue()=default;
    Priority_Queue(const Priority_Queue&)=delete; //禁止拷贝构造
    Priority_Queue& operator=(const Priority_Queue&)=delete;  //禁止赋值操作
    Priority_Queue(Priority_Queue&&) = default;  //允许移动构造
    Priority_Queue& operator=(Priority_Queue&&) = delete;  //禁止移动赋值
    Priority_Queue(const Container& c, const comp& comp_):c(c),comp_(comp_) {} //构造函数
    void push(T val)  //插入元素
    {
        if(size_==max_size) throw std::runtime_error("Priority_queue is full");
        c.push_back(val);
        up(size_);
        size_++;
    }

    void pop()  //删除元素
    {
        if(size_==0) throw std::runtime_error("Priority_queue is empty");
        std::swap(c[0],c[size_-1]);
        c.pop_back();
        size_--;
        down(0);
    }

    const_reference top() const  //返回堆顶元素
    {
        if(size_==0) throw std::runtime_error("Priority_queue is empty");
        return c[0];
    }

    size_t size() const {return size_;}  //返回堆的大小
    bool empty() const {return size_==0;}  //判断堆是否为空
    bool full() const {return size_==max_size;}  //判断堆是否已满
    void clear() {c.clear();size_=0;}  //清空堆
    template<class ...Args>
    void emplace(Args&&... args)  //插入元素
    {
        auto tuple_args = std::make_tuple(std::forward<Args>(args)...);

        // 获取参数的数量
        auto arg_count = std::tuple_size<decltype(tuple_args)>::value;
        if(size_+arg_count>max_size) throw std::runtime_error("Priority_queue is full");

        // 插入元素
        c.emplace_back(std::forward<Args>(args)...);  // 就地构造对象
        size_+=arg_count;
        up(size_ - 1);
    }
    void push_range(const Container& c)  //插入多个元素
    {
        for(auto& val:c)
        {
            push(val);
        }
    }
};


#endif //PRIORITY_QUEUE_H