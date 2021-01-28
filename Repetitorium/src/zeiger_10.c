#include <stdio.h>

int main() {
  char ch='W';
  int x=7;
  float y=3.141;
  void *p;

  p=&ch;
  printf("ch = %c\n",*(char*)p);
  p=&x;
  printf("x  = %d\n",*(int*)p);
  p=&y;
  printf("y  = %f\n",*(float*)p);
  return 0;
}
