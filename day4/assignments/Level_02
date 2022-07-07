#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strlcpy(char* dest, char* source, size_t size){
    int m = strlen(source);
    if(size > m) size = m;
    int i = 0;
    for(i = 0; i < size; i++) dest[i] = source[i];
    dest[i] = '\0';
    return;
}

void strlcat(char* dest, char* source, size_t size){
    int m = strlen(source);
    int n = strlen(dest);
    if(size > m) size = m;
    int i = n;
    for(i = n; i < n+m; i++) dest[i] = source[i-n];
    dest[i] = '\0';
    return;
}
