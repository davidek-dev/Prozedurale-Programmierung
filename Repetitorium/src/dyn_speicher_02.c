#include <stdio.h>
#include <stdlib.h>
void reflect(int n, double* A) {
  int i;
  double x;
  for(i=0; i<n/2; i++) {
    x=A[i];
    A[i]=A[n-i-1];
    A[n-i-1]=x;
  }
  return;
}

int main(void) {
  int i,n;
  double *A;
  printf("\n n = ");
  scanf("%d",&n);
  A=(double *)malloc(n*sizeof(double));
  if(A==NULL) {
    printf("Fehler malloc!");
    exit(1);
  }
  for(i=0; i<n; i++) {
    printf(" A[%d] = ",i);
    scanf("%lf",A+i);
  }
  reflect(n,A);
  for(i=0; i<n; i++)
    printf("\n A[%d] = %.2lf",i,A[i]);
  free(A);
  return 0;
}
