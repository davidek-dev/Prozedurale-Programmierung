#include <stdio.h>

int main() {
  char c, *p_chr;
  int x, *p_int;
  float y=1.23, *p_flt;
  double z=4.56, *p_dbl;

  p_chr=&c;
  p_int=&x;
  p_flt=&y;
  p_dbl=&z;

  printf("Geben Sie ein Zeichen ein: \t\t c = ");
  scanf("%c",p_chr);
  printf("Geben Sie eine ganze Zahl ein: \t\t x = ");
  scanf("%d",p_int);
  printf("Geben Sie eine Fließkommazahl ein: \t y = ");
  scanf("%f",p_flt);
  printf("                ... und noch eine: \t z = ");
  scanf("%lf",p_dbl);

  printf("\n Objekt \t | \t Bytes \t | \t Wert \n");
  printf("-----------------------------------------------------------------\n");
  printf(" *p_chr \t | \t %d \t | \t %c \n",(int)sizeof(*p_chr),*p_chr);
  printf(" *p_int \t | \t %d \t | \t %d \n",(int)sizeof(*p_int),*p_int);
  printf(" *p_flt \t | \t %d \t | \t %f \n",(int)sizeof(*p_flt),*p_flt);
  printf(" *p_dbl \t | \t %d \t | \t %f \n",(int)sizeof(*p_dbl),*p_dbl);
  printf("  p_chr \t | \t %d \t | \t %p \n",(int)sizeof(p_chr),(void*)p_chr);
  printf("  p_int \t | \t %d \t | \t %p \n",(int)sizeof(p_int),(void*)p_int);
  printf("  p_flt \t | \t %d \t | \t %p \n",(int)sizeof(p_flt),(void*)p_dbl);
  printf("  p_dbl \t | \t %d \t | \t %p \n",(int)sizeof(p_dbl),(void*)p_dbl);

  return 0;
}
