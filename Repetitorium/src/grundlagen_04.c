#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isprime(long unsigned int n) {
  long unsigned int i,m;
  if(n<=0) {
    printf("\n Falscher Aufruf! \n");
    exit(1);
  }
  if(n==1) return 0;
  if(n==2) return 1;
  // ineffizienter brut force Primzahltest
  m=round(sqrt(n));
  for(i=2; i<=m; i++) {
    if((n%i)==0) return 0;
  }
  return 1;
}

int main(void) {
  long unsigned int n;
  printf("\n n = ");
  scanf("%lu",&n);
  if(isprime(n)) printf("\n %lu ist eine Primzahl. \n",n);
  else printf("\n %lu ist keine Primzahl. \n",n);
  return 0;
}

