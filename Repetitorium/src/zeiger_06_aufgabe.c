#include <stdio.h>
int main() {
  int x=7, y=17, z=27;
  int *p1 = &x, *p2 = &y, *p3 = &z;

  printf("%p  %p  %p\n\n",(void*)p1,(void*)p2,(void*)p3);

  printf("%p  %d  %d\n",  (void*)(p1+1), *(p1+1), *p1+1);
  printf("%p  %d  %d\n\n",(void*)(p1+2), *(p1+2), *p1+2);

  printf("%p  %d  %d\n",  (void*)(p1-1), *(p1-1), *p1-1);
  printf("%p  %d  %d\n\n",(void*)(p1-2), *(p1-2), *p1-2);

  return 0;
}
