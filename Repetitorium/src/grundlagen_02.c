// korrigiertes Programm
#include <stdio.h>
int main(void) {
  //float a=0, int c,i; // <-- Komma ist falsch
  float a=0;
  int c,i;
  //for { i=0 ; i<5 ; i++ } // <-- geschweifte Klammern sind falsch
  for ( i=0 ; i<5 ; i++ )
    a = a+i;

  c=7;
  printf("\n a = %.2f \n c = %d",a,c);
  return 0;
}
