#include <stdio.h>
void increment(int b[]) {
  b[0]++;
  b[1]++;
  return;
}
int main() {
  int a[2]= {4,7};
  printf("a[0] = %d , a[1] = %d \n",a[0],a[1]);
  increment(a);
  printf("a[0] = %d , a[1] = %d \n",a[0],a[1]);
  return 0;
}
