#include <stdio.h>
int main(void) {
  int i=5;
  for ( i=0; i<3; i-- ) { // Endlosschleife
    i -= i;
    printf("\n i = %3d",i); // Ausgabe i = 0
  }
  return 0;
}
