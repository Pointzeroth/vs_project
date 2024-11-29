#ifndef MANNER_H
#define MANNER_H

#include <iostream>
#include "student.h"

template <typename T>
class Addressbook
{
    private:
        Contact<T> *head;
    public:
        Addressbook();
        void addContact(T name, T phone, T sex, T born, T address);
        void printAllContacts();
        void deleteContact(T name);
        void searchContact(T name);
        ~Addressbook();

};

#include "../src/manner.cpp"

#endif // ADDRESSBOOK_H