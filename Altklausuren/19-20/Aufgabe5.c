#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//a
struct Person
{
    int ID;
    char name[51];
    struct Person *next;
};
typedef struct Person s_person;

//b
s_person* insert_n(s_person* start, unsigned int n, int ID, char* name){
s_person* new = (s_person*) malloc(sizeof(s_person));
new->ID = ID;
strcpy(new->name, name);
if ((n == 0) || (start == NULL)) {
    new->next = start;
    return new;
}
 s_person* iter = start;
 for (; (iter->next != NULL) && --n; iter = iter->next);
 new->next = iter->next;
 iter->next = new;
 return start;
}

//c

s_person A = {2, "A", NULL}; //muss nur angenommen werden, dass dies existiert
s_person B = {1, "B", &A};

s_person* merge(s_person* A, s_person* B){
    if (A==NULL)
    {
        return B;
    }
    if (B==NULL)
    {
        return A;
    }
    if(A->ID > B->ID){
        s_person* tmp = A;
        A=B;
        B=tmp;
    }
    A->next = merge (A->next, B);
    return A;
}


int main(){
 
    merge(&A, &B);
    return 0;
}