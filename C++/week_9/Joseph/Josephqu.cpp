#include <iostream>  
#include <vector>  

class CircularQueue {  
private:  
    std::vector<int> queue;  
    int front, rear, size, count;  

public:  
    CircularQueue(int size) : size(size), front(0), rear(0), count(0) {  
        queue.resize(size);  
    }  

    void enqueue(int person) {  
        if (count == size) {  
            throw std::overflow_error("Queue is full");  
        }  
        queue[rear] = person;  
        rear = (rear + 1) % size;  
        count++;  
    }  

    int dequeue() {  
        if (count == 0) {  
            throw std::underflow_error("Queue is empty");  
        }  
        int person = queue[front];  
        front = (front + 1) % size;  
        count--;  
        return person;  
    }  

    bool isEmpty() {  
        return count == 0;  
    }  

    int getCount() {  
        return count;  
    }  
};  

void josephus(int n, int m) {  
    CircularQueue queue(n);  
    
    // 初始化队列  
    for (int i = 1; i <= n; i++) {  
        queue.enqueue(i);  
    }  

    int index = 0;  
    while (queue.getCount() > 1) {  
        index++;  
        int person = queue.dequeue();  
        
        if (index == m) {  
            std::cout << "出列: " << person << std::endl;  
            index = 0;  // 重置计数器  
        } else {  
            queue.enqueue(person);  // 重新入队  
        }  
    }  

    // 返回最后剩下的那个人  
    int last_person = queue.dequeue();  
    std::cout << "最后剩下的人是: " << last_person << std::endl;  
}  

// 示例用法  
int main() {  
    int n = 7;  // 人数  
    int m = 3;  // 每次报数到3的人出列  
    josephus(n, m);  
    return 0;  
}