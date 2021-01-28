#include <stdio.h>
#include <string.h>

void printarray(char a[], int n) {
  int i;
  for (i = 0; i < n; ++i)
    printf("a[%d] = %c  \t  &a[%d] = %p\n",i,a[i],i,a+i);
  return;
}

int main(void) {
  char str[101];
  printf("Geben Sie eine Zeichenkette ein : ");
  scanf("%s",str);
  printarray(str,strlen(str));
  return 0;
}
