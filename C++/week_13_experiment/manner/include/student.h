#ifndef STUDENT_H
#define STUDENT_H

template <typename T>
class Contact
{
    public:
        T name;
        T num;
        T sex;
        T born;
        T addr;
        Contact* next;

        Contact(T n, T p, T s, T b, T c);
};

#include "../src/student.cpp"

#endif  // CONTACT_H