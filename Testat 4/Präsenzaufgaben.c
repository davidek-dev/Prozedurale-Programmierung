#define Aufgabe2
#include <stdio.h>
int main()
{

#ifdef Aufgabe1

    //Tests auf Gleichheit oder Reihenfolge sind rechtsassoziativ L => R
    //Zuweisungsoperator ist Linksassoziativ R=>L
    double d1, d2;
    float f1, f2;
    f2 = d1 = 0.25;
    d2 = f1 = 0.25;
    //a:
    if (f1 == f2)
    {
        printf("f1 == f2\n");
    }
    else
    {
        printf("f1!=f2\n");
    }
    //c d
    if (d1 == d2)
    {
        printf("d1 == d2\n");
    }
    else
    {
        printf("d1!=d2\n");
    }

//Bei der Zuweisung wird der rechte Operand immer in den Typ des linken Operanden umgewandelt.
//Dabei werden überzählige (Nachkomma-)Stellen oder höherwertige Bits, die nicht mehr Platz haben, einfach abgeschnitten:
//Es wird nicht gerundet.
//Wenn der Originalwert im neuen Typ nicht mehr darstellbar ist, findet ein Überlauf statt,
//und das Ergebnis hat mit dem Originalwert meist nicht mehr viel gemein.
#endif

#ifdef Aufgabe2

    double summand = 1;
    double sum = 0;
    int k = 0;

    double power = 1;
    double x = 2.7;
    double faculty = 1;
    do

    {
        sum += summand;
        k++;
        for (int i = 0; i < k; i++)
        {
            power *= x;
        }
        for (int j = 1; j <= k; j++)
        {
            faculty *= j;
        }

        summand = power / faculty;

        faculty = 1;
        power = 1;
    } while (summand + sum > sum);

    printf("%f", sum);

#endif

#ifdef Aufgabe3

    int k = 3;
    int n = 7;
    int ergebnis;
    int faculty = 1;

    if (n == 0)
    {
        ergebnis = 1;
    }
    else if (0 < n && n <= k)
    {
        ergebnis = n;
    }
    else
    {
        for (int j = 1; j <= (n - k); j++)
        {
            faculty *= j;
        }

        for (int i = 1; i < k; i++)
        {
            faculty *= faculty;
        }
        ergebnis = n * faculty;
    }

    printf("%d", ergebnis);

#endif

    return 0;
}