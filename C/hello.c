#include <stdio.h>

int fun(int n)
{
    int i,s=0;
    for(i=2;i<(n/2);i++)
    {
        if(n%i==0)
        {
            s=s+i;
        }
    }
    return s;
}

int func(int a)
{
    int n = 1;
    int s = 0;
    while(n<=10)
    {
        if((a%13==0)||(a%17==0))
        {
            s = s + a;
            n++;
        }
        a--;
    }
    return s;
}

void main()
{
    printf("s=%d\n",func(855));
}
