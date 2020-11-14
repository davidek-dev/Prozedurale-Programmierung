//
//  main.c
//  blatt02_2
//
//  Created by Marvin Heydorn on 12.11.20.
//

#include <stdio.h>

int main() {
   
    uint16_t a = 10000;  // (uint16_t) -6, weil 2^16 - 6 = 65530
    uint16_t index[16];
    int i;
  
    
        

    printf("ihre Zahl in Binär: ");
   
    for (i=0; a > 0; i++)
    {
    index[i]= a % 2;
    a = a / 2;
    }

    for (; i > 0; i--)
    {
    printf("%d",index[i-1]);
        printf(" ");
    }
    printf("\n");
    printf("\n");
    return 0;
    }

   

