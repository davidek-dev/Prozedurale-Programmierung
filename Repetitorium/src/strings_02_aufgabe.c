#include <stdio.h>
int main(void) {
  char str[50] = "hello\0 worl\bd";
  printf("\n %s ",str);
  printf("%s \n",str+str[4]-*str);
  return 0;
}