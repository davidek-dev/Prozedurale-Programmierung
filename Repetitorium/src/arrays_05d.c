#include <stdio.h>
#include <stdlib.h>
// Lösungsversion 1: Lösungsvektor mit malloc erzeugen und füllen
double* addiere_1(double a[],double b[]) {
  double *c;
  int i;
  c=(double*)malloc(3*sizeof(double));
  if(c==NULL) {
    printf("Error malloc");
    exit(1);
  }
  for(i=0; i<3; i++) c[i]=a[i]+b[i];
  return c;
}

// Lösungsversion 2: Übergabe des zu füllenden Ergebnisvektors c
void addiere_2(double a[],double b[],double c[]) {
  int i;
  for(i=0; i<3; i++) c[i]=a[i]+b[i];
  return;
}

void ausgabe(double *c,char* str) {
  printf("\n %s = ( %.2lf, %.2lf, %.2lf) \n",str,c[0],c[1],c[2]);
  return;
}

int main() {
  double a[3]= {1,2,3};
  double b[3]= {4,4,4};

  double *c1;
  double c2[3];

  c1=addiere_1(a,b);
  addiere_2(a,b,c2);

  ausgabe(c1,"c1");
  ausgabe(c2,"c2");

  free(c1);
  return 0;
}
