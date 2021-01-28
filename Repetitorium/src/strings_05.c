#include <stdio.h>
int main(int argc, char* argv[]) {
  double max,x;
  int i;
  if(argc==1) {
    printf("\n Das Programm wurde ohne Programmparameter aufgerufen.\n");
    return 0;
  }
  sscanf(argv[1],"%lf",&max);
  for(i=2; i<argc; i++) {
    sscanf(argv[i],"%lf",&x);
    max=((x>max)?x:max);
  }
  printf("\n Maximum : %lf \n",max);
  return 0;
}

