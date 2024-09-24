#include <iostream>  
#include <cmath> // For M_PI  

class Circle {  
private:  
    double radius; // 半径  

public:  
    // 默认构造函数  
    Circle() : radius(1.0) {} // 半径默认为1.0  

    // 带参数的构造函数  
    Circle(double r) : radius(r) {}  

    // 设置圆半径  
    void setRadius(double r) {  
        radius = r;  
    }  

    // 读取圆半径  
    double getRadius() const {  
        return radius;  
    }  

    // 求圆的周长  
    double getCircumference() const {  
        return 2 * M_PI * radius; // 周长 = 2 * π * 半径  
    }  

    // 求圆的面积  
    double getArea() const {  
        return M_PI * radius * radius; // 面积 = π * 半径^2  
    }  
};  

int main() {  
    // 定义两个圆对象  
    Circle circle1; // 使用默认构造函数  
    Circle circle2(5.0); // 使用带参数的构造函数  

    // 输出两个圆的半径  
    std::cout << "Circle 1 Radius: " << circle1.getRadius() << std::endl;  
    std::cout << "Circle 2 Radius: " << circle2.getRadius() << std::endl;  

    // 计算周长和面积  
    double circumference1 = circle1.getCircumference();  
    double area1 = circle1.getArea();  
    double circumference2 = circle2.getCircumference();  
    double area2 = circle2.getArea();  

    // 输出周长和面积  
    std::cout << "Circle 1 Circumference: " << circumference1 << std::endl;  
    std::cout << "Circle 1 Area: " << area1 << std::endl;  
    std::cout << "Circle 2 Circumference: " << circumference2 << std::endl;  
    std::cout << "Circle 2 Area: " << area2 << std::endl;  

    // 比较周长  
    if (circumference1 > circumference2) {  
        std::cout << "Circle 1 has a larger circumference." << std::endl;  
    } else if (circumference1 < circumference2) {  
        std::cout << "Circle 2 has a larger circumference." << std::endl;  
    } else {  
        std::cout << "Circle 1 and Circle 2 have the same circumference." << std::endl;  
    }  

    // 比较面积  
    if (area1 > area2) {  
        std::cout << "Circle 1 has a larger area." << std::endl;  
    } else if (area1 < area2) {  
        std::cout << "Circle 2 has a larger area." << std::endl;  
    } else {  
        std::cout << "Circle 1 and Circle 2 have the same area." << std::endl;  
    }  

    return 0;  
}