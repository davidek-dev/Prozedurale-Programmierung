#include <stdio.h>

int main() {
  char ch0,*ch1,**ch2,***ch3,****ch4;
  ch1=&ch0;
  ch2=&ch1;
  ch3=&ch2;
  ch4=&ch3;
  printf("\n Geben Sie ein Zeichen ein ch = ");
  scanf("%c",**ch3);
  printf(" Ihre Eingabe war ch = %c \n",****ch4);
  /* Alternativen */
  /*1) ch1,ch3 */
  printf("\n Geben Sie ein Zeichen ein ch = ");
  scanf(" %c",ch1);
  printf(" Ihre Eingabe war ch = %c \n",***ch3);
  /*2) ch0,ch2 */
  printf("\n Geben Sie ein Zeichen ein ch = ");
  scanf(" %c",&ch0);
  printf(" Ihre Eingabe war ch = %c \n",**ch2);
  /*3) ch4,ch1 */
  printf("\n Geben Sie ein Zeichen ein ch = ");
  scanf(" %c",***ch4);
  printf(" Ihre Eingabe war ch = %c \n",*ch1);

  return 0;
}
