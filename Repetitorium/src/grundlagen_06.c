// korrigiertes Programm

#include <stdio.h>
int main(void) {
  int i;
  // double x, *y; // <-- Code aus Aufgabe
  double x, y;
  // scanf("%d%f",i,&x,y); // <-- Code aus Aufgabe
  scanf("%d,%lf,%lf",&i,&x,&y);
  // printf(’i = %d%d%lf’,i,x,y); // <-- Code aus Aufgabe
  // C99
  //printf("i = %d, x= %lf, y = %lf",i,x,y);
  // C89
  printf("i = %d, x= %f, y = %f",i,x,y);

  return 0;
}
