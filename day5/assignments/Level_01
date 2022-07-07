#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct charcell{
    char* X;
    struct charcell* following;
};

typedef struct charcell charcell;
typedef struct charcell* charlist;



void* al_memchr(char* source, char x, unsigned n){
    char* p = source;
    for(int i = 0; i < n; i++){
        if(*(p+i) == x) return p+i;
    }
    return NULL;
}

void* al_memset(void* source, int x, unsigned n){
    char* p = source;
    for(int i = 0; i < n; i++){
        *(p+i) = x;
    }
    return p;
}

void* al_memcpy(void* dest , const void* source , unsigned num)
{
    char* value_source = dest;
    const char* s= source;
    for (int  i = 0 ; i < num ; i++){
        *(value_source+i) = *(s+i);
    }
    return dest;
}

void* al_memmove(void* dest, const void* source, unsigned num){
    char* value_source = dest;
    const char* s= source;
    for (int  i = 0; i < num; i++){
        *(value_source+num-i) = *(s+num-i);
    }
    return dest ;
}

char* al_strdup(const char* s){
    char* p = (char*)malloc(sizeof(*s)*strlen(s));
    for(int i = 0; i < sizeof(*s)*strlen(s); i++){
        *(p+i) = *(s+i);
    }
    return p;
}

void sort(int* x, unsigned n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i; j++){
            if(*(x+i) > *(x+i+1)){
                int z = *(x+i+1);
                *(x+i+1) = *(x+i);
                *(x+i) = z;
            }
        }
    }
}


char** strsplit(char* str, char delim){
    charlist L = NULL;
    charlist temp = L;
    int f = 0;
    int i = 0;
    int count = 0;
    while(str[i] != '\0'){
        int j = i;
        while(str[j] != delim && str[j] != '\0') j++;
        if(j != i){
            charcell* C;
            C = (charcell*)malloc(sizeof(charcell));
            C->following = NULL;
            C->X = (char*)malloc(sizeof(char)*(j-i+1));
            int e = 0;
            for(e = 0; e < j-i; e++) C->X[e] = str[e+i];          
            C->X[e+1] == '\0';
            if( f == 0){
                L = C;
                temp = C;
                f = 2;
            }
            temp->following = C;
            temp = temp->following;
            count ++;
        }
        if(str[j] != '\0') j++;
        i = j;
    }
    char** final = (char**)malloc(sizeof(char*)*count);
    temp = L;
    for(int e = 0; e < count; e++){
        final[e] = malloc(sizeof(char)*strlen(temp->X));
        final[e] = temp->X;
        temp = temp->following;
        free(L);
    }
    return final;
}
