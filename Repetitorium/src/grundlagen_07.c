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
  long unsigned int i,j,N=50;
  char ch_prim='p';
  char ch_comp='-';

  printf("\n");
  for(i=1; i<=N; i++) {
    for(j=1; j<=N; j++) {
      if( isprime((i-1)*N+j) ) printf(" %c",ch_prim);
      else printf(" %c",ch_comp);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}
