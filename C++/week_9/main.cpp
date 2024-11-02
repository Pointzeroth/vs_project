// main.cpp  
#include "include/Addressbook.h"  
#include <string>  

int main() {  
    Addressbook<std::string> Addressbook; // 使用std::string类型的通讯录  
    int choice;  
    std::string name, phoneNumber;  

    do {  
        std::cout << "main:" << std::endl;  
        std::cout << "1. 添加联系人" << std::endl;  
        std::cout << "2. 显示所有联系人" << std::endl;  
        std::cout << "3. 删除联系人" << std::endl;  
        std::cout << "4. 退出" << std::endl;  
        std::cout << "请输入您的选择: ";  
        std::cin >> choice;  

        switch (choice) {  
            case 1:  
                std::cout << "请输入姓名: ";  
                std::cin >> name;  
                std::cout << "请输入电话号码: ";  
                std::cin >> phoneNumber;  
                Addressbook.addContact(name, phoneNumber);  
                break;  
            case 2:  
                Addressbook.printAllContacts();  
                break;  
            case 3:  
                std::cout << "请输入要删除的姓名: ";  
                std::cin >> name;  
                Addressbook.deleteContact(name);  
                break;  
            case 4:  
                std::cout << "退出程序。" << std::endl;  
                break;  
            default:  
                std::cout << "无效选择，请重新输入。" << std::endl;  
        }  
    } while (choice != 4);  

    return 0;  
}