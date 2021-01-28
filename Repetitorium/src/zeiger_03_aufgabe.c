#include <stdio.h>

int main() {
  char   c, *p_chr;
  int    x, *p_int;
  float  y, *p_flt;
  double z, *p_dbl;

  p_chr = __c;
  p_int = __x;
  p_flt = __y;
  p_dbl = __z;

  printf("Geben Sie ein Zeichen ein:          c = ");
  scanf("%__", p_chr);
  printf("Geben Sie eine ganze Zahl ein:      x = ");
  scanf("%d", ______);
  printf("Geben Sie eine Fließkommazahl ein:  y = ");
  scanf("%f", ______);
  printf("                ... und noch eine:  z = ");
  scanf("%__",______);

  printf("\n");
  printf(" Objekt | Bytes | Wert     \n");
  printf("--------+-------+----------\n");
  printf(" *p_chr |   %d  | %c \n", (int) sizeof(*p_chr), ______);
  printf(" *p_int |   %d  | %d \n", (int) sizeof(______), ______);
  printf(" *p_flt |   %d  | %f \n", (int) sizeof(______), ______);
  printf(" *p_dbl |   %d  | %f \n", (int) sizeof(______), ______);
  printf("  p_chr |   %d  | %p \n", (int) sizeof(______), (void*)______);
  printf("  p_int |   %d  | %p \n", (int) sizeof(______), (void*)______);
  printf("  p_flt |   %d  | %p \n", (int) sizeof(______), (void*)______);
  printf("  p_dbl |   %d  | %p \n", (int) sizeof(______), (void*)______);

  return 0;
}
