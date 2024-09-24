#include <iostream>  
#include <cmath>   

// 定义点的结构体  
struct Point {  
    double x; // 横坐标  
    double y; // 纵坐标  

    // 设置点的坐标  
    void setCoordinates(double xCoord, double yCoord) {  
        x = xCoord;  
        y = yCoord;  
    }  

    // 显示点的坐标  
    void displayCoordinates() {  
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;  
    }  

    // 计算与另一点的距离  
    double distanceTo(Point& other) {  
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));  
    }  
};  

int main() {  
    Point point1, point2; // 定义两个点  

    // 设置第一个点的坐标  
    point1.setCoordinates(3.0, 4.0);  
    // 设置第二个点的坐标  
    point2.setCoordinates(0.0, 0.0);  

    // 显示两个点的坐标  
    std::cout << "Coordinates of point1: ";  
    point1.displayCoordinates();  
    
    std::cout << "Coordinates of point2: ";  
    point2.displayCoordinates();  

    // 计算并显示两点间的距离  
    double distance = point1.distanceTo(point2);  
    std::cout << "Distance between point1 and point2: " << distance << std::endl;  

    return 0;  
}

//使用引用避免不必要的拷贝,且允许函数修改传入的对象
//若是不用&引用，也可，但是在使用值传递时，other 是 Point 对象的一个独立副本，对其修改不会影响原始对象。如果需要在函数中修改 other 的属性，这种方法就无法实现。