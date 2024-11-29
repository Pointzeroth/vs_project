// main.cpp  
#include "include/manner.h"  
#include <string>  

int main() {  
    Addressbook<std::string> Addressbook; // 使用std::string类型的通讯录  
    int choice;  
    std::string name, phoneNumber, Sex, bornDate, address;  
    std::cout<<"	*************************************					"<<std::endl;
    std::cout<<"	*                                   *					"<<std::endl;
    std::cout<<"	*                                   *					"<<std::endl;
    std::cout<<"	*      welcome to use the manner    *                   "<<std::endl; 
    std::cout<<"	*                                   *					"<<std::endl;
    std::cout<<"	*                                   *					"<<std::endl;
    std::cout<<"	*************************************					"<<std::endl;
    std::cout<<std::endl;

    do {
        // std::cout << "-------------------------------"<< std::endl;  
        std::cout << "main:" << std::endl;  
        std::cout << "1. addStudnt" << std::endl;  
        std::cout << "2. printStudnts" << std::endl;  
        std::cout << "3. deleteStudnt" << std::endl;
        std::cout << "4. searchStudnt" << std::endl;
        std::cout << "5. exit" << std::endl;  
        std::cout << "input your choice: ";  
        std::cin >> choice;  

        switch (choice) {  
            case 1:  
                std::cout << "input name: ";  
                std::cin >> name;  
                std::cout << "input number: ";  
                std::cin >> phoneNumber;
                std::cout << "input sex: ";
                std::cin >> Sex;
                std::cout << "input bornDate: ";
                std::cin >> bornDate;
                std::cout << "input address: ";
                std::cin >> address;
                Addressbook.addContact(name, phoneNumber, Sex, bornDate, address);
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
                std::cout << "search stdunt" << std::endl;
                std::cout << "input name to search: ";
                std::cin >> name;
                Addressbook.searchContact(name);
                break;
            case 5:  
                std::cout << "exit" << std::endl;  
                break;  
            default:  
                std::cout << "error choice" << std::endl;  
        }  
    } while (choice != 5);  

    return 0;  
}