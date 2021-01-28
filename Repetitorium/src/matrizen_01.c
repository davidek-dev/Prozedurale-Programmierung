#include <stdio.h>

void read_matrix(int A[][3]) {
  int i,j;
  for(i=0; i<2; i++) {
    for(j=0; j<3; j++) {
      printf("A[%d][%d] = ",i,j);
      scanf("%d",&(A[i][j]));
    }
  }
  return;
}

void print_matrix(int A[][3]) {
  int i,j;
  for(i=0; i<2; i++) {
    for(j=0; j<3; j++) {
      printf("A[%d][%d] = %d \n",i,j,A[i][j]);
    }
  }
  return;
}

int main(void) {
  int A[2][3];
  read_matrix(A);
  print_matrix(A);
  return 0;
}
