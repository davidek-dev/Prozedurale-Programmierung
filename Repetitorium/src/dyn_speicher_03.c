#include <stdio.h>
#include <stdlib.h>
struct person {
  char surname[51];
  unsigned int age;
};

int main(void) {
  struct person *p=NULL;
  p=(struct person *)malloc(sizeof(*p));
  if(p==NULL) {
    printf("Fehler malloc!");
    exit(1);
  }
  printf("\n Nachname :\t");
  scanf("%50s",p->surname);
  printf(" Alter :\t");
  scanf("%u",&(p->age));
  printf("\n Die Person heißt %s und ist %u Jahre alt.\n",p->surname,p->age);
  free(p);
  return 0;
}
