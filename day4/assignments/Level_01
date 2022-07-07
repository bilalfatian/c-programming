#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int al_strlen(char* x){
    int count = 0;
    while(x[count] != '\0') count++;
    return count;
}

void al_strcpy(char* dest, char* source){
    int n = al_strlen(dest);
    for(int i = 0; i < n; i++) dest[i] = source[i];
}

void al_strcat(char* x1, char* x2){
    int n = al_strlen(x1);
    int m = al_strlen(x2);
    int i;
    for(int i = n; i < n+m; i++) x1[i] = x2[i-n];
    x1[i] = x2[m];
}

void str_reverse(char* x){
    int i;
    int count = 0;
    while(x[count] != '\0') count++;
    for(i = 0; i < count/2; i++){
        char z = x[i];
        x[i] = x[count-i-1];
        x[count-i-1] = z;
    }
}

void str_wreverse(char* x){
    int i = 0;
    while(x[i] != '\0'){
        int j = i;
        while(x[j] != ' ' && x[j] != '\0') j++;
        if(j != i){
            for(int e = i; e < (j+i)/2; e++){
                char z = x[e];
                x[e] = x[j+i-e-1];
                x[j+i-e-1] = z;
            }
        }
        if(x[j] != '\0')j++;
        i = j;
    }    
}
