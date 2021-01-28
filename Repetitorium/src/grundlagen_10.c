#include <stdio.h>
// #include <stdlib.h>

void print_array(int n,double *A) {
  int i;
  printf("\n");
  for(i=0; i<n; i++) printf(" %.2lf\n",A[i]);
  printf("\n");
  return;
}

void sort_array(int n,double* A) {
  int i,j;
  double x;
  for(i=0; i<n; i++) {
    for(j=1; j<n-i; j++) {
      if(A[j-1]>A[j]) {
        x=A[j-1];
        A[j-1]=A[j];
        A[j]=x;
      }
    }
  }
  return;
}

int main(void) {
  // double* A;
  int n;
  printf("\n n = ");
  scanf("%d",&n);
  double A[n];
  // A=(double*)malloc(n*sizeof(double));
  // if(A==NULL){printf("error malloc()");exit(1);}
  int i;
  printf("\n");
  for(i=0; i<n; i++) {
    printf(" A[%d] = ",i);
    scanf("%lf",A+i);
  }
  printf("\n unsortiertes Feld: \n");
  print_array(n,A);
  sort_array(n,A);
  printf("\n sortiertes Feld: \n");
  print_array(n,A);
  // free(A);
  return 0;
}
