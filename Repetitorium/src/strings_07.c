#include <stdio.h>
#include <string.h>
int main(void) {
  char str_1[51], str_2[51], str_3[101];
  printf("Eingabe String 1: ");
  scanf("%50s",str_1);
  printf("Eingabe String 2: ");
  scanf("%50s",str_2);
  if(strcmp(str_1,str_2)!=0)
    printf("\n\n Die Strings %s und %s sind verschieden.",str_1,str_2);
  else
    printf("\n\n Die Strings %s und %s sind gleich.",str_1,str_2);
  // Konkatenation per Hand,  siehe auch Funktion strcat()
  strcpy(str_3,str_1);
  strcpy(str_3+strlen(str_1),str_2);
  printf("\n\n Konkatenation: %s \n",str_3);
  return 0;
}
