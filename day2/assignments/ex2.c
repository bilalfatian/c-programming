//EX2

#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d",&a,&b);
    printf("Befor the permutaion\na = %d\nb = %d\n",a,b);
    c=a;
    a=b;
    b=c;
    printf("After the permutation\na = %d\nb = %d\n",a,b);
}
