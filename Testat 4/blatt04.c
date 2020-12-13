/*Aufgabe:
Schreibe eine sin, arctan und ln funktion.
Möglichst wenig Gleitpunktoperationen +, *
Was sind geeignete Schleifenabbruchbedigngungen, 
die eine sehr hohe Genauigkeit des Ergebnisses sicherstellen? => stichwort Maschienengenauigkeit
zu jedem Schritt k die Zwischenergebnisse der Reihenentwicklung in einer Tabelle.
*/
#include <stdio.h>
#include <math.h>

int k = 0;               //Schritt
double temp_sum = 0;     //bissherige Summe
double next_summand = 0; //nächster Summand
double my_power = 1;     //für den Zähler jeweils

double my_sin(double x)
{
    double my_factorial = 1; //für den Nenner bei sin(x)

    next_summand = x; //erster schritt mit k = 0 ergibt x
    printf("\n\n");
    printf("----------------------------------------------------------------------\n");
    printf("                     y = sin(%.16f)\n", x);
    printf("--------+-------------------------------------------------------------\n");
    printf("  k\t|\ttemp_sum\t+\tnext_summand\t=\tsum\t\tfactorial\t\tpower\n");
    printf("--------+-------------------------------------------------------------\n");
    printf(" %d\t|\t%.16f\t+\t%.16f\t=\t%.16f\n", k, temp_sum, next_summand, temp_sum + next_summand);

    k++;

    for (k; (temp_sum + next_summand) != temp_sum; k++)
    {
        temp_sum += next_summand;
        if ((k % 2) == 0)
        {
            for (int i = 2 * k + 1; i > 0; i--)
            {
                my_power *= x;
            }

            for (int j = 1; j <= (2 * k + 1); j++)
            {
                my_factorial *= j;
            }

            next_summand = (my_power / my_factorial);
        }
        else
        {
            for (int i = 2 * k + 1; i > 0; i--)
            {
                my_power *= x;
            }

            for (int j = 1; j <= (2 * k + 1); j++)
            {
                my_factorial *= j;
            }

            next_summand = -1 * (my_power / my_factorial);
        }

        printf(" %d\t|\t%.16f\t+\t%.16f\t=\t%.16f\t\t%.16f\t\t%.16f\n", k, temp_sum, next_summand, temp_sum + next_summand, my_factorial, my_power);
        my_power = 1;
        my_factorial = 1;
    }
    return temp_sum;
}

double my_arctan(double x)
{
    double my_denominator = 1; //für den Nenner bei sin(x)

    next_summand = x; //erster schritt mit k = 0 ergibt x
    printf("\n\n");
    printf("----------------------------------------------------------------------\n");
    printf("                     y = arcsin(%.16f)\n", x);
    printf("--------+-------------------------------------------------------------\n");
    printf("  k\t|\ttemp_sum\t+\tnext_summand\t=\tsum\t\tfactorial\t\tpower\n");
    printf("--------+-------------------------------------------------------------\n");
    printf(" %d\t|\t%.16f\t+\t%.16f\t=\t%.16f\n", k, temp_sum, next_summand, temp_sum + next_summand);

    k++;

    for (k; (temp_sum + next_summand) != temp_sum; k++)
    {
        temp_sum += next_summand;
        my_denominator = 2 * k + 1;
        if ((k % 2) == 0)
        {
            for (int i = 2 * k + 1; i > 0; i--)
            {
                my_power *= x;
            }
            next_summand = (my_power / my_denominator);
        }
        else
        {
            for (int i = 2 * k + 1; i > 0; i--)
            {
                my_power *= x;
            }
            next_summand = -1 * (my_power / my_denominator);
        }

        printf(" %d\t|\t%.16f\t+\t%.16f\t=\t%.16f\t\t%.16f\t\t%.16f\n", k, temp_sum, next_summand, temp_sum + next_summand, my_denominator, my_power);
        my_power = 1;
    }

    return temp_sum;
}

double my_ln(double x)
{

    k++;
    next_summand = x - 1; //erster schritt mit k = 0 ergibt x
    printf("\n\n");
    printf("----------------------------------------------------------------------\n");
    printf("                     y = ln(%.16f)\n", x);
    printf("--------+-------------------------------------------------------------\n");
    printf("  k\t|\ttemp_sum\t+\tnext_summand\t=\tsum\n");
    printf("--------+-------------------------------------------------------------\n");
    printf("k\t|\t%.16f\t+\t%.16f\t=\t%.16f\n", temp_sum, next_summand, temp_sum + next_summand);
    k++;
    for (k; (temp_sum + next_summand) != temp_sum; k++)
    {
        temp_sum += next_summand;

        if ((k % 2) == 0)
        {
            for (int i = k; i > 0; i--)
            {
                my_power *= (x - 1);
            }
            next_summand = -1 * (my_power / k);
        }
        else
        {
            for (int i = k; i > 0; i--)
            {
                my_power *= (x - 1);
            }
            next_summand = (my_power / k);
        }

        printf(" %d\t|\t%.16f\t+\t%.16f\t=\t%.16f\t\n", k, temp_sum, next_summand, temp_sum + next_summand);
        my_power = 1;
    }
    return temp_sum;
}

int main()
{
    double ergebnis;
    double my_x;
    int mode;
    printf("Folgende Funktionen können hier berechnet werden:\n\n\t1. sin(x)\n\t2. arctan(x)\n\t3. ln(x)");
    printf("\n\nWelche Funktion möchtest du berechnen?\n");
    scanf("%d", &mode);

    switch (mode)
    {
    case 1:
        printf("\n\nGebe einen Ganzzahl oder Gleitpunktwert ein, welches als x in die Funktion eingesetzt werden soll\n");
        scanf("%lf", &my_x);
        ergebnis = my_sin(my_x);
        printf("\n\nVergleich\teigenes sin()\tvs\tmath.h sin()\n\n");
        printf("\n\nVergleich\t%.32f\tvs\t%.32f\n\n", ergebnis, sin(my_x));
        break;

    case 2:
        printf("\n\nGebe eine Zahl im Bereich [-1, .., 1] ein, welche als x in die Funktion eingesetzt werden soll\n");
        scanf("%lf", &my_x);
        ergebnis = my_arctan(my_x);
        printf("\n\nVergleich\teigenes arctan()\tvs\tmath.h atan()\n\n");
        printf("\n\nVergleich\t%.32f\tvs\t%.32f\n\n", ergebnis, atan(my_x));
        break;

    case 3:
        printf("\n\nGebe eine Zahl im Bereich (0, .., 2] (also ohne 0) ein, welche als x in die Funktion eingesetzt werden soll\n");
        scanf("%lf", &my_x);
        ergebnis = my_ln(my_x);
        printf("\n\nVergleich\teigenes ln()\tvs\tmath.h log()\n\n");
        printf("\n\nVergleich\t%.32f\tvs\t%.32f\n\n", ergebnis, log(my_x));
        break;

    default:
        printf("\n\n___________________________________________\nDu hast weder 1, noch 2, noch 3 bei Modus eingegeben\n___________________________________________\n");
        break;
    }

    return 0;
}