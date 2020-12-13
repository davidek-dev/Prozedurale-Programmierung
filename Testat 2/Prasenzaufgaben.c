#include <stdio.h>
#include <stdint.h>
#define Aufgabe7

int main()
{

#ifdef Aufgabe1
    int Kelvin = 0;
    printf("Grad | Kelvin");

    while (Kelvin < 550)
    {
        printf("%d | %d \n", Kelvin - 273, Kelvin);
        Kelvin += 5;
    }
#endif

#ifdef Aufgabe2

    float x = -5;
    float y = x * x;
    printf("x|y\n");
    while (x <= 5)
    {
        printf("%f|%f\n", x, y);
        x += 0.125;
        y = x * x;
    }

#endif

#ifdef Aufgabe3

    int a = 1;
    int b = 3;
    int c = 5;

    if (a < b && b < c)
    {
        printf("a %d,b %d,c %d", a, b, c);
    }
    if (a < c && c < b)
    {
        printf("a %d,c %d,b %d", a, c, b);
    }
    if (b < a && a < c)
    {
        printf("b %d,a %d,c %d", b, a, c);
    }
    if (b < c && c < a)
    {
        printf("b %d,c %d,a %d", b, c, a);
    }
    if (c < b && b < a)
    {
        printf("c %d,b %d,a %d", c, b, a);
    }
    if (c < a && a < b)
    {
        printf("c %d,a %d,b %d", c, a, b);
    }

#endif

#ifdef Aufgabe4

    int nat = 22;
    int div = 2;
    while (div <= nat)
    {
        if ((nat % div) == 0)
        {
            printf("%d \n", div);
        }
        div++;
    }

#endif

#ifdef Aufgabe4

    int nat = 22;
    int div = 2;
    while (div <= nat)
    {
        if ((nat % div) == 0)
        {
            printf("%d \n", div);
        }
        div++;
    }

#endif

#ifdef Aufgabe5

    int count = 1;
    while (count < 100)
    {
        if ((count % 3) == 0)
        {
            printf("%d\n", count);
        }
        count++;
    }

#endif

#ifdef Aufgabe6

    int_fast16_t Zahl = 21327;
    int_fast16_t foo = 1;
    while (Zahl + foo > 0)
    {
        printf("%d\n", foo);
        foo++;
    }
#endif

#ifdef Aufgabe7

    for (int i = 6; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            printf("*");
        }
        printf("\n");
    }

#endif

    return 0;
}