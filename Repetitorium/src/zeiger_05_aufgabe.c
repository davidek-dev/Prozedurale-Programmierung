#include <stdio.h>
int main() {
  short int x = 333;
  char *p_chr;
  int i;
  p_chr = (char*) &x;
  printf("x = %d\n", x);
  printf("x = ");
  for(i = 32768; i > 0; i >>= 1) {
    printf("%d", (x & i) > 0);
  }
  printf("\n\n");
  printf("x_chr = %c \n",*p_chr);
  printf("x_chr = %d \n",*p_chr);
  printf("x_chr = ");
  for(i = 128; i > 0; i >>= 1) {
    printf("%d", ((*p_chr) &i) > 0);
  }
  return 0;
}
