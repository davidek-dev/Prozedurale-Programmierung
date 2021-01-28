#include <stdio.h>
#include <stdlib.h>

double** tmat_alloc(int n) {
  int i;
  double **A;
  A=(double**)malloc((n*(n+1))/2*sizeof(double));
  if(A==NULL) {
    printf("Fehler malloc!");
    exit(1);
  }
  for(i=0; i<n; i++)
    A[i]=(double*)malloc((n-i)*sizeof(double));
  if(A==NULL) {
    printf("Fehler malloc!");
    exit(1);
  }
  return A;
}

void tmat_read(char ch,int n,double **A) {
  int i,j;
  printf("\n Eingabe der oberen Dreiecksmatrix %c \n\n",ch);
  for(i=0; i<n; i++)
    for(j=i; j<n; j++) {
      printf(" %c[%d][%d] = ",ch,i,j);
      scanf("%lf",&A[i][j]);
    }
  return;
}

double** tmat_mult(int n,double **A,double **B) {
  int i,j,k;
  double **C;
  C=tmat_alloc(n);
  for(i=0; i<n; i++) {
    for(j=i; j<n; j++) {
      C[i][j]=0;
      for(k=i; k<=j; k++) {
        C[i][j]+=A[i][k]*B[k][j];
      }
    }
  }
  return C;
}

void tmat_print(char ch,int n,double**M) {
  int i,j;
  printf("\n %c = \n",ch);
  for(i=0; i<n; i++) {
    for(j=0; j<i; j++) printf("\t ");
    for(j=i; j<n; j++) printf("\t %.2lf",M[i][j]);
    printf("\n");
  }
  return;
}

void tmat_free(int n,double** M) {
  int i;
  for(i=0; i<n; i++) free(M[i]);
  free(M);
  return;
}

int main(void) {
  int n;
  double **A,**B,**C;
  printf("\n n = ");
  scanf("%d",&n);
  A=tmat_alloc(n);
  B=tmat_alloc(n);
  tmat_read('A',n,A);
  tmat_read('B',n,B);
  C=tmat_mult(n,A,B);
  tmat_print('C',n,C);
  tmat_free(n,A);
  tmat_free(n,B);
  tmat_free(n,C);
  return 0;
}
