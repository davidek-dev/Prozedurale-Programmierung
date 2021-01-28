#include <stdio.h>
void swap(int *x, int*y) {
  int z;
  z=*x;
  *x=*y;
  *y=z;
  return;
}

int main() {
  int x,y;
  printf(" x = ");
  scanf("%d",&x);
  printf(" y = ");
  scanf("%d",&y);
  swap(&x,&y);
  printf("\n x = %d \n y = %d \n",x,y);
  return 0;
}
