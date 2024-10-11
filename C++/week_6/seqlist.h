#pragma once

const int Max = 100;

template <typename T>
class seqlist
{
    public:
        seqlist();
        seqlist(T a[], int n);
        ~seqlist();
        int getlength();
        void reverse(T a[], int n);
        void px(T a[], int n);

    private:
        T data[Max];
        int length;    
};