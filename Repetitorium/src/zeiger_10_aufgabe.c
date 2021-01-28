#include <stdio.h>
int main() {
  char ch = 'W';
  int x = 7;
  float y = 3.141;
  void *p;

  p = &ch;
  printf("ch = %c\n",________p);
  p = &x;
  printf("x  = %d\n",________p);
  p = &y;
  printf("y  = %f\n",________p);
  return 0;
}
