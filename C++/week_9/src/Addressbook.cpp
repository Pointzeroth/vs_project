#pragma once
#include "../include/Addressbook.h"


template <typename T>
Addressbook<T>::Addressbook() : head(nullptr) {} 

template <typename T>
void Addressbook<T>::addContact(T name, T phone)
{
    // Create a new node
    Contact<T>* newContact = new Contact<T>(name, phone);
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
void Addressbook<T>::printAllContacts()
{
    if(head == nullptr)
    {
        std::cout << "Addressbook is empty" << std::endl;
    }
    else
    {
        Contact<T>* current = head;
        std::cout << "Addressbook:" << std::endl;
        while(current != nullptr)
        {
            std::cout << current->name << " " << current->phonenumber << std::endl;
            current = current->next;
        }
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
        std::cout << "Contact deleted:" << name << std::endl;
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
            std::cout << "Contact deleted:" << name << std::endl;
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