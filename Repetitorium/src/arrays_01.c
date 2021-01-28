#include <stdio.h>

void scalar_mult(double a, double v[], double w[], int n) {
  int i;
  for(i=0; i<n; i++) w[i]=a*v[i];
  return;
}

void vec_add(double u[],double v[],double w[], int n) {
  int i;
  for(i=0; i<n; i++) w[i]=u[i]+v[i];
  return;
}

void read_vec(char* str, double v[], int n) {
  int i;
  printf("\n");
  for(i=0; i<n; i++) {
    printf("%s_%d = ",str,i+1);
    scanf("%lf",v+i);
  }
  return;
}

void print_vec(char* str, double v[], int n) {
  int i;
  printf("\n");
  for(i=0; i<n; i++) printf("%s_%d = %.2lf\n",str,i,v[i]);
  return;
}


int main() {
  int n;
  double a;
  printf("Dimension n = ");
  scanf("%d",&n);
  double u[n],v[n],w[n];
  read_vec("u",u,n);
  read_vec("v",v,n);
  printf("\nSkalar a = ");
  scanf("%lf",&a);
  scalar_mult(a,v,w,n);
  printf("\nErgebnis der skalaren Multiplikation w=a*v:\n");
  print_vec("w",w,n);
  printf("\nErgebnis der Vektoraddition w=u+v:\n");
  vec_add(u,v,w,n);
  print_vec("w",w,n);
  return 0;
}
