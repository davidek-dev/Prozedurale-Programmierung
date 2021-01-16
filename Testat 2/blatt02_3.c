//
//  main.c
//  blatt02_3
//
//  Created by Marvin Heydorn on 12.11.20.
//

#include <stdio.h>

int main()
{

    int N;
    printf("\nBitte geben Sie eine Zahl von 0 bis 10 ein: \n");
    scanf("%d", &N);
    if (N > 10)
    {
        printf("Ihre Eingabe ist zu hoch\n");
    }
    else
    {

        //obere hälfte
        for (short i = 1; i <= N; i++)
        {
            for (short leer = 1; leer <= N - i; leer++)
            {
                printf("  "); // leeres feld
            }
            for (short nummer = 1; nummer <= i; nummer++)
            {
                printf("%hi ", nummer); // aufsteigend
            }
            for (short nummer = i - 1; nummer >= 1; nummer--)
            {
                printf("%hi ", nummer); //absteigend
            }
            printf("\n");
        }

        //untere hälfte
        for (short i = N - 1; i >= 0; i--)
        {
            for (short leer = 1; leer <= N - i; leer++)
            {
                printf("  "); // leeres feld
            }
            for (short nummer = 1; nummer <= i; nummer++)
            {
                printf("%hi ", nummer); // aufsteigend
            }
            for (short nummer = i - 1; nummer >= 1; nummer--)
            {
                printf("%hi ", nummer); //absteigend
            }
            printf("\n");
        }
    }

    system("pause");
    return 0;
}
