#pragma once
#include "../include/manner.h"
#include <iomanip> // Include this for std::setw and std::left

template <typename T>
Addressbook<T>::Addressbook() : head(nullptr) {} 

template <typename T>
void Addressbook<T>::addContact(T name, T phone, T sex, T born, T address)
{
    // Create a new node
    Contact<T>* newContact = new Contact<T>(name, phone, sex, born, address);
    // If the list is empty, set the head to the new node
    if (head == nullptr)
    {
        head = newContact;
    }
    else
    {
        Contact<T>* current = head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newContact;
    }
}

template <typename T>  
void Addressbook<T>::printAllContacts() {  
    if (head == nullptr) {  
        std::cout << "Addressbook is empty" << std::endl;  
    } else {  
        Contact<T>* current = head;  
 
        std::cout << std::left << std::setw(20) << "Name"   
                  << std::setw(15) << "Num"   
                  << std::setw(25) << "Address"   
                  << std::setw(15) << "Born"   
                  << std::setw(10) << "Sex" << std::endl;  
        std::cout << std::string(95, '-') << std::endl; // Print a line for separation  

        while (current != nullptr) {  
            std::cout << std::left << std::setw(20) << current->name   
                      << std::setw(15) << current->num   
                      << std::setw(25) << current->addr   
                      << std::setw(15) << current->born   
                      << std::setw(10) << current->sex << std::endl;  
            current = current->next;  
        }
        std::cout << std::string(95, '-') << std::endl; // Print a line for separation  
    }  
}

template <typename T>
void Addressbook<T>::searchContact(T name)
{
    if(head == nullptr)
    {
        std::cout << "Addressbook is empty" << std::endl;
        return;
    }
    if(head->name == name)
    {
        std::cout << "--------------------------" << std::endl;
        std::cout << "Name: " << head->name << std::endl;
        std::cout << "num: " << head->num << std::endl;
        std::cout << "Address: " << head->addr << std::endl;
        std::cout << "Born: " << head->born << std::endl;
        std::cout << "Sex: " << head->sex << std::endl;
        std::cout << "--------------------------" << std::endl;
        return;
    }
    Contact<T>* current = head;
    while(current->next != nullptr)
    {
        if(current->next->name == name)
        {
            std::cout << "--------------------------" << std::endl;
            std::cout << "Name: " << current->next->name << std::endl;
            std::cout << "num: " << current->next->num << std::endl;
            std::cout << "Address: " << current->next->addr << std::endl;
            std::cout << "Born: " << current->next->born << std::endl;
            std::cout << "Sex: " << current->next->sex << std::endl;
            std::cout << "--------------------------" << std::endl;
            return;
        }
        current = current->next;

    }
    if(current == nullptr)
    {
        std::cout << "Contact not found" << std::endl;
    }
}

template <typename T>
void Addressbook<T>::deleteContact(T name)
{
    if(head == nullptr)
    {
        std::cout << "Addressbook is empty" << std::endl;
        return;
    }

    if(head->name == name)
    {
        Contact<T>* temp = head;
        head = head->next;
        delete temp;
        std::cout << "----------------------------" << std::endl;
        std::cout << "Contact deleted:" << name << std::endl;
        std::cout << "--------------------------" << std::endl;
        return;
    }

    Contact<T>* current = head;
    while(current->next != nullptr)
    {
        if(current->next->name == name)
        {
            Contact<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
            std::cout << "----------------------------"<< std::endl;
            std::cout << "Contact deleted:" << name << std::endl;
            std::cout << "--------------------------" << std::endl;
            return;
        }
        current = current->next;
    }
    std::cout << "Contact not found" << std::endl;
}

template <typename T>
Addressbook<T>::~Addressbook()
{
    while(head != nullptr)
    {
        Contact<T>* temp = head;
        head = head->next;
        delete temp;
    }
}