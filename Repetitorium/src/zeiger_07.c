#include <stdio.h>
#include <math.h>

void median(double *x,double *y,double *z) {
  double a,b,c;
  a=(*x+*y+*z)/3;
  b=cbrt((*x)*(*y)*(*z));
  c=3/(1/(*x)+1/(*y)+1/(*z));
  *x=a;
  *y=b;
  *z=c;
  return;
}

int main() {
  double x,y,z;
  printf("x = ");
  scanf("%lf",&x);
  printf("y = ");
  scanf("%lf",&y);
  printf("z = ");
  scanf("%lf",&z);

  median(&x,&y,&z);
  printf("\n arithmetisches Mittel: \t %f",x);
  printf("\n geometrisches Mittel:  \t %f",y);
  printf("\n harmonisches Mittel:   \t %f\n",z);

  return 0;
}
