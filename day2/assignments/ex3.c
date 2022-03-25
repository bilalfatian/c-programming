
//EX3

#include<stdio.h>
int main(){
    
    int   i =  8;
    int   j =  5;
    float x =  0.005f;
    float y = -0.01f;
    char  c = 'c';
    char  d = 'd';
    printf("(3i - 2j)%%(2*d - c) = %d\n",(3*i-2*j)%(2*d-c));
    printf("2*((i/5) + (4*(j-3))%%(i + j - 2)) = %d\n",2*((i/5) + (4*(j-3))%(i + j - 2)));
    printf("i <= j : %i\n",i <= j);
    printf("j != 6 : %i\n",j != 6);
    printf("c == 99 : %i\n",c == 99);
    printf("5*(i + j) > 'c' : %i\n",5*(i + j) > 'c');
    printf("(i > 0) && (j < 5) : %i\n",(i > 0) && (j < 5));
    printf("(i > 0) || (j < 5) : %i\n",(i > 0) || (j < 5));
    printf("(x > y) && (i > 0) || (j < 5) : %i\n",(x > y) && (i > 0) || (j < 5));
    printf("(x > y) && (i > 0) && (j < 5) : %i\n",(x > y) && (i > 0) && (j < 5));
    

}
