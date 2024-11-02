#ifndef CONTACT_H
#define CONTACT_H 

template <typename T>
class Contact
{
    public:
        T name;
        T phonenumber;
        Contact* next;

        Contact(T n, T p);
};

#include "../src/Contact.cpp"

#endif  // CONTACT_H