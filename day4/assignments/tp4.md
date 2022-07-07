# STRINGS

## Lecture Practice

Note : all your arrays of characters most be "strings"

1. Declare a literal string containing 'Hello'
2. Declare an empty array of characters then fill it with word 'World'
3. Declare ana empty array of characters then concatenate the previous strings in it with a space between them without using string.h library.
4. repeat last question using strcat.
5. repeat 3 using only strcpy.
6. without doing the compilation what is the return of each of these strcmp calls:  
    char s1[ ] = "Hello";  
    char s2[ ] = "hello";  
    char s3[ ] = {'h', 'e', 'l' , 'l', '\0'}
    * strcmp(s1, s2);
    * strcmp(s2, s1);
    * strcmp(s1, s3);
    * strcmp(s2, s3);
7. rewrite the function gets using getchar function.  
    * Prototype : char *al_gets(char *strPtr) 
8. rewrite the function puts using putchar function.  
    * Prototype : char *al_puts(char *strPtr) 
9. write a program that reads a string from standard input and compare it with a word of your choice if they match write "success" to the standard output else write "failed" to the standard error. (using fgets and fputs).

## Level 01
* Rewrite the following functions append "al_" before the function name (eg : al_strlen):
    * strlen
    * strcpy
    * strcat
    * forbidden functions: malloc

* write a function that takes a string and reverse it.
    * Prototype: void str_reverse(char *)
    * forbidden functions: strlen, malloc

* write a function that takes a string and write to the standard output the same string but with the words reversed in place. (eg: "hello World" >>> "olleh dlroW").
    * Prototype: void str_wreverse(char *)
    * forbidden functions: strlen, strcpy, strcat, malloc

## Level 02
* Rewrite the following functions:
    * strlcpy
    * strlcat
    * forbidden functions: malloc