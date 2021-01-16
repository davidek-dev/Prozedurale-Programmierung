#include <stdio.h>
#include <stdint.h>

int main()
{
  int16_t y = 1024, z = 65; // auch "short" als Datentyp verwendbar
  //short hat den datenbereich {-32768,..,32767}

  y = y * z; //1024 * 65 = 66560 = wraparound bei 32767, es wird danach von -32768 hoch gezählt
  //66560 - 32767 = 33793
  //-32767 + 33793 = 1024
  printf("1. Ausgabe: %d\n", y);                     //ausgabe von y, y ist jetzt 1025
  printf("2. Ausgabe: %d\n", y / 3 * 3 - 3 * y / 3); // 1025 / 3=341
  // 341*3 =1023
  //1023 - (3*y/3) = 1023 - 3072 /3
  // 1023 - 3072 /3= 1023 - 1024 = -1
  //Ausgabe ist wegen des verlustes der nachkommastellen -1
  printf("\n");

  return 0;
}
