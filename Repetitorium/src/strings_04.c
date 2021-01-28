#include <stdio.h>
int main(void) {
  char str[21], // string
       *s=str;
  int sum=0;
  printf("String eingeben: ");
  scanf("%20s",str);
  while(*s!=0) {
    if( (*s>='0') && (*s<='9') ) { // *s ist eine Ziffer.
      printf("%c",*s); // Ziffer ausgeben
      sum+= (*s)-'0'; // Umwandlung char->int
    }
    s++;
  }
  printf("\nZiffernsumme : %i \n",sum);
  return 0;
}
