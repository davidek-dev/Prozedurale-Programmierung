#include <stdio.h>
int main(void) {
  char str[101], // string
       *s=str,   // search-pointer
        ch_1, // search-character
        ch_2; // replace-character
  printf("\n Enter a string : ");
  scanf("%100s",str); // read str
  printf("\n Enter search-character : ");
  scanf(" %c",&ch_1); // read ch_1
  printf("\n Enter replace-character : ");
  scanf(" %c",&ch_2); // read ch_2
  while(*s!=0) {
    if(*s==ch_1) *s=ch_2; // search for ch_1 and replace it by ch_2
    s++;
  }
  printf("\n new string : %s \n",str);
  return 0;
}
