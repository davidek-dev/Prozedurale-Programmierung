#include <stdio.h>
#include <stdlib.h>

void read_matrix(char ch,int m,int n,double **A) {
  int i,j;
  for(i=0; i<m; i++) {
    for(j=0; j<n; j++) {
      printf("%c[%d][%d] = ",ch,i,j);
      scanf("%lf",&(A[i][j]));
    }
  }
  return;
}

void print_matrix(char ch,int m,int n,double **A) {
  int i,j;
  printf("\n%c = \n",ch);
  for(i=0; i<m; i++) {
    for(j=0; j<n; j++) {
      printf("%.2lf \t",A[i][j]);
    }
    printf("\n");
  }
  return;
}

void mat_mult(int m,int n,int k,double **A,double **B, double **C) {
  int a,b,c;
  for(a=0; a<m; a++) {
    for(b=0; b<k; b++) {
      C[a][b]=0;
      for(c=0; c<n; c++)
        C[a][b]+=A[a][c]*B[c][b];
    }
  }
  return;
}

double** mat_alloc(int m,int n) {
  double **A;
  int i;
  A=(double**)malloc(m*sizeof(double*));
  if(A==NULL) {
    printf("Fehler malloc() A!");
    exit(1);
  }
  for(i=0; i<m; i++) {
    A[i]=(double*)malloc(n*sizeof(double));
    if(A[i]==NULL) {
      printf("Fehler malloc() A[%d]!",i);
      exit(1);
    }
  }
  return A;
}

void free_mat(int m, double **A) {
  int i;
  for(i=0; i<m; i++) free(A[i]);
  free(A);
}


int main(void) {
  double **A,**B,**C;
  int m,n,k;

  printf("m,n,k = ");
  scanf("%d,%d,%d",&m,&n,&k);

  A=mat_alloc(m,n);
  B=mat_alloc(n,k);
  C=mat_alloc(m,k);

  read_matrix('A',m,n,A);
  read_matrix('B',n,k,B);
  mat_mult(m,n,k,A,B,C);
  print_matrix('C',n,k,C);

  free_mat(m,A);
  free_mat(n,B);
  free_mat(m,C);
  return 0;
}
