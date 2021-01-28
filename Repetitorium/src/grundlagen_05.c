#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isprime(long unsigned int n) {
  long unsigned int i,m;
  if(n==1) return 0;
  if(n==2) return 1;
  // ineffizienter brut force Primzahltest
  m=round(sqrt(n));
  for(i=2; i<=m; i++) {
    if((n%i)==0) return 0;
  }
  return 1;
}

long unsigned int squaresum(long unsigned int n) {
  long unsigned int i,sum=0;
  for(i=1; i<=n; i++) {
//    if(i/2==1)
    sum+=i*i;
//    else
//      sum+=i;
  }
  return sum;
// alternativ:
// return (n*(n+1)*(2*n+1))/6
}


int main(void) {
  long unsigned int n,
       N=1000, // n <= N
       cnt=0;  // Anzahl der Primzahlen in squaresum(1),...,squaresum(N)
  //long unsigned int s; int prim;
  for(n=1; n<=N; n++) {
    //s=squaresum(n); prim=isprime(s); printf("%lu. Quadratsumme %lu, prim = %d\n",n,s,prim); cnt+=prim;
    cnt+=isprime(squaresum(n));
  }
  printf("Die ersten %lu Quadratsummen enthalten genau %lu Primzahlen. \n",N,cnt);

  // Es gilt s=sum_{i=1}^n i^2 = n*(n+1)*(2*n+1)/6. Für n>=3  hat n*n*(2n+1)/(2*3) mindestens zwei Faktoren >1.
  // Folglich ist s dann keine Primzahl. Ferner ist s(n=1)=1 keine Primzahl während s(n=2)=1+4=5 eine Primzahl ist.


  return 0;
}
