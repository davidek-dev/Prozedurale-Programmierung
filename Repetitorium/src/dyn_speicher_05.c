#include <stdio.h>
#include <stdlib.h>
#define GB (1024*1024*1024)

long unsigned  int memory(void) {
  long unsigned int n=1;
  char *p=NULL;
  while((p=malloc(n*GB))) {
    n++;
    free(p);
  }
  return n-1;
}
int main(void) {
  printf("\n Es können %ld Gigabyte zusammenhängender Speicher dynamisch reserviert werden. \n",
         memory());
  return 0;
}
