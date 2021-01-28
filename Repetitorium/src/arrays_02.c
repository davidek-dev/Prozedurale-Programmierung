#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238462643383

double scalar_prod(double u[], double v[], int n) {
  int i;
  double a=0;
  for(i=0; i<n; i++) a+=u[i]*v[i];
  return a;
}

double two_norm(double v[], int n) {
  return sqrt(scalar_prod(v,v,n));
}

void read_vec(char *ch, double v[], int n) {
  int i;
  printf("\n");
  for(i=0; i<n; i++) {
    printf("%s_%d = ",ch,i+1);
    scanf("%lf",v+i);
  }
  return;
}

int main() {
  int n;
  printf("Dimension n = ");
  scanf("%d",&n);
  double u[n],v[n];
  read_vec("u",u,n);
  read_vec("v",v,n);
  printf("\nu^Tv = %.2f",scalar_prod(u,v,n));
  printf("\n||v||_2 = %.2f",two_norm(v,n));
  printf("\nalpha = %.2f Grad\n",acos(scalar_prod(u,v,n)/(two_norm(u,
                                      n)*two_norm(v,n)))*180/PI);
  return 0;
}
