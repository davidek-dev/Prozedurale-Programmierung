#include <stdio.h>
#include <stdlib.h>

int main(void) {
//a)
  char S[3][20]= {"Repetitorium","Prozedurale","Programmierung"};
  printf(" %s %s %s ",S[0],S[1],S[2]);
//b)
  short **s=malloc(3*sizeof(long*));
  s[2]=malloc(4*sizeof(short));
  s[2][3]=-7;
  printf("\n %hi ",s[2][3]);
//c)
  //double B[3]={1,2,3},C[3]={4,5,6};
  //double A[2][3]={B,C};
//d)
  int A[1][3]= {{1,2,4}};
  printf("\n %d, %d, %d",*A[0],*A[0]+1,*A[0]+2);
//e)
  float B[2][3];
  printf("\n Größe der Matrix B in Byte : %ld \n",sizeof(B));

  return 0;
}
