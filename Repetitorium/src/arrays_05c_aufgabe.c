#include <stdio.h>
typedef struct {
  int c[2];
} arr;
void increment(arr b) {
  b.c[0]++;
  b.c[1]++;
  return;
}
int main() {
  arr a= {{4,7}};
  printf("a[0] = %d , a[1] = %d \n",a.c[0],a.c[1]);
  increment(a);
  printf("a[0] = %d , a[1] = %d \n",a.c[0],a.c[1]);
  return 0;
}
