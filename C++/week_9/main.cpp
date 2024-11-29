// main.cpp  
#include "include/Addressbook.h"  
#include <string>  

int main() {  
    Addressbook<std::string> Addressbook; // 使用std::string类型的通讯录  
    int choice;  
    std::string name, phoneNumber;  

    do {  
        std::cout << "main:" << std::endl;  
        std::cout << "1. addContact" << std::endl;  
        std::cout << "2. printAllContacts" << std::endl;  
        std::cout << "3. deleteContact" << std::endl;  
        std::cout << "4. exit" << std::endl;  
        std::cout << "input your choice: ";  
        std::cin >> choice;  

        switch (choice) {  
            case 1:  
                std::cout << "input name: ";  
                std::cin >> name;  
                std::cout << "input phone number: ";  
                std::cin >> phoneNumber;  
                Addressbook.addContact(name, phoneNumber);  
                break;  
            case 2:  
                Addressbook.printAllContacts();  
                break;  
            case 3:  
                std::cout << "input name to delete: ";  
                std::cin >> name;  
                Addressbook.deleteContact(name);  
                break;  
            case 4:  
                std::cout << "exit" << std::endl;  
                break;  
            default:  
                std::cout << "error choice" << std::endl;  
        }  
    } while (choice != 4);  

    return 0;  
}