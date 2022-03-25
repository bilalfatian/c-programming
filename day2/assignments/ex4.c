//EX4
#include<stdio.h>
int main()
{
    int a;
    int b;
    int c;
    a = 16;
    b = 2;
    c = 10;

    c += a > 0 && a <= 15 ? ++a : a/b;
    //if c+a>0 and a<=15 it will return a=a+1=17, if not it return a/b=8
    
    
    a > 30 ? b = 11 : c = 100;
    //if a>30 it will return b=11, if not it return c=100
}
