#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  short *d;
  short a[5]= {4,7,-5};
  printf(" sizeof(a) = %d",(int)sizeof(a)/(int)sizeof(*a));
  printf("\n a[4] = %hd",a[4]);
  printf("\n a[5] = %hd",a[5]);
  short b[n];
  printf("\n sizeof(b) = %d",(int)sizeof(b)/(int)sizeof(*b));
  printf("\n n = ");
  scanf("%d",&n);
  short c[n];
  printf(" sizeof(c) = %d \n",(int)sizeof(c)/(int)sizeof(*c));
  d=(short*)malloc(n*sizeof(short));
  printf(" sizeof(d) = %d \n",(int)sizeof(d)/(int)sizeof(*d));
  return 0;
}
