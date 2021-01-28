#include <stdio.h>

float *maximum(float *a,float *b,float *c) {
  float *p;
  if(*a>*b) p=a;
  else p=b;
  if(*c>*p) p=c;
  // alternativ mit ternärem Operator
  // p = ( *a > *b ? a:b );
  // p = ( *p > *c ? p:c );
  return p;
}

int main() {
  float a,b,c;
  printf("a = ");
  scanf("%f",&a);
  printf("b = ");
  scanf("%f",&b);
  printf("c = ");
  scanf("%f",&c);
  printf("max(%f,%f,%f) = %f",a,b,c,*maximum(&a,&b,&c));
  return 0;
}
