#include <stdio.h>
#include <stdlib.h>

int N;

void swap(int *x,int*y) {
  int z;
  z=*x;
  *x=*y;
  *y=z;
  return;
}

void sort(int a[]) {
  int i,j;
  for(i=1; i<N; i++) {
    for(j=0; j<N-i; j++) {
      if(a[j]>a[j+1]) swap(a+j,a+j+1);
    }
  }
}

int main() {
  int i;
  // int *a; /* c89 - Lösungsvariante mit malloc */
  printf("Anzahl zu sortierender Zahlen, N = ");
  scanf("%d",&N);
  int a[N]; // c99 - Lösungsvariante mit nachgelagerter Array-Definition und variabler Arraylänge N
  // a=(int*)malloc(N*sizeof(int)); // c89 - Lösungsvariante mit malloc
  printf("Geben Sie %d ganze Zahlen ein: \n\n",N);
  for(i=0; i<N; i++) {
    printf("x_%d = ",i+1);
    scanf("%d",a+i);
  }
  sort(a);
  printf("\n");
  for(i=0; i<N; i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
  return 0;
}
