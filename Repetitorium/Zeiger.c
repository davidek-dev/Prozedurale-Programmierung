#include  <stdio.h>
#include <stdlib.h>
#define Aufgabe2

int  main() {

    #ifdef Aufgabe1
    char x = 'G'; //char
    char *p, **q; //char* //char** 
    p=&x;
    q=&p;
    printf("Der  Wert  von x ist:\t %c \n", *p);
    printf("Die  Adresse  von x ist:\t %p \n\n", (void*)p);
    printf("Der  Wert  von p ist: \t %p \n", *q);
    printf("Die  Adresse  von p ist: \t %p \n", (void*)q);
    #endif
    
    #ifdef Aufgabe2
int a;
int* zeige1, zeiger2;
int *zeiger3, *zeiger4;
int* zeiger5, *zeiger6;
int *zeiger7; int *zeiger8;
int* zeiger9; int *zeiger10;
    zeige1 = &a;
    zeiger2 = &a;
    zeiger3 = &a;
    zeiger4 = &a;
    zeiger5 = &a;
    zeiger6 = &a;
    zeiger7 = &a;
    zeiger8 = &a;
    zeiger9 = &a;
    zeiger10 = &a;
    
    #endif

    return  0;
}