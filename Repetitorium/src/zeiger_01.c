#include <stdio.h>

int main() {
  char x='G';
  char *p, **q;
  p=&x;
  q=&p;

  printf("Der Wert von x ist:\t %c \n",*p);
  printf("Die Adresse von x ist:\t %p \n\n",(void*)p);

  printf("Der Wert von p ist: \t %p \n",*q);
  printf("Die Adresse von p ist: \t %p \n",(void*)q);

  return 0;
}
