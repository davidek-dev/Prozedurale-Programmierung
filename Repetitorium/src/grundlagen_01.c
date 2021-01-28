#include <stdio.h>
int main(void) {
  int a=5, b=-3;
  a = b = a;
  printf("\n a = %d \n b = %d \n",a,b);
  return 0;
}
