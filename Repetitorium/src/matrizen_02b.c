#include <stdio.h>
#define N 2

void read_matrix(char ch,double A[][N]) {
  int i,j;
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      printf("%c[%d][%d] = ",ch,i,j);
      scanf("%lf",&(A[i][j]));
    }
  }
  return;
}

void print_matrix(char ch,double A[][N]) {
  int i,j;
  printf("\n%c = \n",ch);
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      printf("%.2lf \t",A[i][j]);
    }
    printf("\n");
  }
  return;
}

void mat_mult(double A[][N],double B[][N],double C[][N]) {
  int i,j,k;
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      C[i][j]=0;
      for(k=0; k<N; k++)
        C[i][j]+=A[i][k]*B[k][j];
    }
  }
  return;
}


int main(void) {
  double A[N][N],B[N][N],C[N][N];
  read_matrix('A',A);
  read_matrix('B',B);
  mat_mult(A,B,C);
  print_matrix('C',C);
  return 0;
}
