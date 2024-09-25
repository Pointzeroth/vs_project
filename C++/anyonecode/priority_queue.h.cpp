#include "priority_queue.h"  // 包含你的优先队列头文件
#include <iostream>
#include <cassert>

int main() {
    // 创建一个优先队列，使用int类型，比较函数为std::greater<int>（从大到小排序）
    Priority_Queue<int, std::vector<int>, std::greater<int>> pq;

    // 测试插入元素
    pq.emplace(5);
    pq.emplace(10);
    pq.emplace(1);
    pq.emplace(3);
    pq.emplace(7);

    // 输出队列顶部元素
    std::cout << "Top element: " << pq.top() << std::endl;  // 应该输出最大的元素 10

    // 测试弹出元素
    pq.pop();
    std::cout << "Top element after pop: " << pq.top() << std::endl;  // 应该输出次大的元素 7

    // 测试插入多个元素
    pq.push_range({2, 6, 4});
    std::cout << "Top element after pushing range: " << pq.top() << std::endl;  // 应该输出 7



    // 测试队列的大小
    std::cout << "Queue size: " << pq.size() << std::endl;  // 应该输出 5

    // 测试队列是否为空
    std::cout << "Queue is empty: " << std::boolalpha << pq.empty() << std::endl;  // 应该输出 false

    // 测试队列是否已满
    std::cout << "Queue is full: " << std::boolalpha << pq.full() << std::endl;  // 应该输出 false

    // 清空队列
    pq.clear();
    std::cout << "Queue size after clear: " << pq.size() << std::endl;  // 应该输出 0
    std::cout << "Queue is empty after clear: " << std::boolalpha << pq.empty() << std::endl;  // 应该输出 true

    // 测试队列已满的情况
    for (int i = 0; i < MAXSIZE; ++i) {
        pq.emplace(i);
    }
    std::cout << "Queue size after filling: " << pq.size() << std::endl;  // 应该输出 100
    std::cout << "Queue is full after filling: " << std::boolalpha << pq.full() << std::endl;  // 应该输出 true

    // 尝试在已满的队列中插入元素，应该抛出异常
    try {
        pq.emplace(101);
        std::cout << "This line should not be printed." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;  // 应该输出 "Priority queue is full"
    }

    return 0;
}