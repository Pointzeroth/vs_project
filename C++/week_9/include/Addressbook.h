#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Contact.h"
#include <iostream>

template <typename T>
class Addressbook
{
    private:
        Contact<T> *head;
    public:
        Addressbook();
        void addContact(T name, T phone);
        void printAllContacts();
        void deleteContact(T name);
        ~Addressbook();

};

#include "../src/Addressbook.cpp"

#endif // ADDRESSBOOK_H