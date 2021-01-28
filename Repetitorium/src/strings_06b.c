#include <stdio.h>
#include <string.h>
int main(void) {
  // string str1[5] = "hallo"; // syntaktisch falsch
  // char*  str2    = 'hallo'; // syntaktisch falsch
  // char*  str3[6] = "hallo\0";  // syntaktisch falsch
  char   str4[]  = {'h','a','l','l','o','\0'};
  printf("\n str = %s \n str4[5] = %d",str4,str4[5]);
  printf("\n strlen(str4) = %d\n",(int)strlen(str4));

  char   str5[5] = {'h','a','l','l','o'};
  printf("\n str = %s \n str5[5] = %d",str5,str5[5]);
  printf("\n strlen(str5) = %d\n",(int)strlen(str5));


  return 0;
}
