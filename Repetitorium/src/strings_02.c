#include <stdio.h>
int main(void) {
  char str[50] = "hello\0 worl\bd";
  printf("\n %s ",str); /* output of str up to the escape sequence \0 which is the
                           nul-character an signalizes a string-end. */
  printf("%s \n",str+str[4]
         -*str); /* str[4] is the character 'o' and *str, which is
                                      the same as str[0], equals 'h'. In ASCII arithmetic
                                      'o'-'h'=7 since h,i,j,k,l,m,n,o have consecutive
                                      ASCII values and therfore distance 7.
                                      Thus str+str[4]-*str equals str+7 which yields that
                                      printf prints the trailing string starting from str[7]
                                      which is 'w'. The escape sequence \b, backspace,
              delets the preceeding letter l so that the output is
              word and not world. */
  return 0;
}

/* output: hello word




 */
