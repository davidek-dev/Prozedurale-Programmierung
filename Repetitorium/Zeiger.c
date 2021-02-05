#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Aufgabe10

void swap(int *p_a, int *p_b)
{
    int tmp = *p_a;
    *p_a = *p_b;
    *p_b = tmp;
    return;
}

void median(double *p_a, double *p_b, double *p_c)
{
    double a, b, c;
    a = (*p_a + *p_b + *p_c) / 3;
    b = cbrt((*p_a) * (*p_b) * (*p_c));
    c = 3 / ((1 / (*p_a)) + (1 / (*p_b)) + (1 / (*p_c)));
    *p_a = a;
    *p_b = b;
    *p_c = c;
    return;
}

float *maximum(float *p_a, float *p_b, float *p_c)
{
    if (*p_a > *p_b)
    {
        if (*p_a > *p_c)
        {
            return p_a;
        }
        else
        {
            return p_c;
        }
    }
    else
    {
        if (*p_b > *p_c)
        {
            return p_b;
        }
        else
        {
            return p_c;
        }
    }
}

int main()
{

#ifdef Aufgabe1
    char x = 'G'; //char
    char *p, **q; //char* //char**
    p = &x;
    q = &p;
    printf("Der  Wert  von x ist:\t %c \n", *p);
    printf("Die  Adresse  von x ist:\t %p \n\n", (void *)p);
    printf("Der  Wert  von p ist: \t %p \n", *q);
    printf("Die  Adresse  von p ist: \t %p \n", (void *)q);
#endif

#ifdef Aufgabe2
    int a;
    int *zeige1, zeiger2;
    int *zeiger3, *zeiger4;
    int *zeiger5, *zeiger6;
    int *zeiger7;
    int *zeiger8;
    int *zeiger9;
    int *zeiger10;
    zeige1 = &a;
    zeiger2 = &a;
    zeiger3 = &a;
    zeiger4 = &a;
    zeiger5 = &a;
    zeiger6 = &a;
    zeiger7 = &a;
    zeiger8 = &a;
    zeiger9 = &a;
    zeiger10 = &a;

#endif

#ifdef Aufgabe3
    char c, *p_chr;
    int x, *p_int;
    float y, *p_flt;
    double z, *p_dbl;
    p_chr = &c;
    p_int = &x;
    p_flt = &y;
    p_dbl = &z;
    printf("\nGeben  Sie  ein  Zeichen  ein :c = ");
    scanf("%c", p_chr);
    printf("\nGeben  Sie  eine  ganze  Zahl  ein :x = ");
    scanf("%d", p_int);
    printf("\nGeben  Sie  eine  Fließkommazahl  ein :y = ");
    scanf("%f", p_flt);
    printf("\n. . .  und noch  eine :   z = ");
    scanf("%lf", p_dbl);
    printf("\n");
    printf(" Objekt  |  Bytes  |  Wert\n");
    printf("---------+---------+---------\n");
    printf("*p_chr  |    %d   | %c \n", (int)sizeof(*p_chr), *p_chr);
    printf("*p_int  |    %d   | %d \n", (int)sizeof(*p_int), *p_int);
    printf("*p_flt  |    %d   | %f  \n", (int)sizeof(*p_flt), *p_flt);
    printf("*p_dbl  |    %d   | %f  \n", (int)sizeof(*p_dbl), *p_dbl);
    printf("   p_chr  |    %d   | %p \n", (int)sizeof(p_chr), (void *)&p_chr);
    printf("   p_int  |    %d   | %p \n", (int)sizeof(p_int), (void *)&p_int);
    printf("   p_flt  |    %d   | %p \n", (int)sizeof(p_flt), (void *)&p_flt);
    printf("   p_dbl  |    %d   | %p \n", (int)sizeof(p_dbl), (void *)&p_dbl);
    /*
    Warum haben beispielweise *p_chr und *p_int unterschiedliche Byte-Längen

    A: Die dereferenzierung von p_chr und p_int gibt den Inhalt es Speicherplatzes an,
    auf den p_char/p_int zeigt. Die größe der derefernzierung von p_char ist als die
    Größe des für den Inhalt der Speicherstelle reservierten Speicherplatz.
    Dieser unterscheidet sich je nach Datentyp: Bool ist ein Bit, Char ist ein Byte,
    Int sind 4 Bytes, Floats benötigen ebenfalls 4 Bytes und Double benötigt das doppelte von Float also 8 Bytes

    während hingegen p_char und p_int gleiche Byte-Längen haben?

    A: p_char und p_int sind beides nur Zeiger. Diese beinhalten als Wert Adressen anderer Speicherstellen
    Adressen von Speicherplätzen sind einheitlich gleichgroß - 8 Byte.
    */
#endif

#ifdef Aufgabe4
    int x = 0;
    int y = 0;
    printf("x =");
    scanf("%d", &x);
    printf("\ny =");
    scanf("%d", &y);
    swap(&x, &y);
    printf("Der Wert von X ist %d und der Wert von Y ist %d", x, y);

#endif

#ifdef Aufgabe5

    short int x = 333;
    char *p_chr;
    int i;
    p_chr = (char *)&x;    //der Wert von x, also die Zahl, wird als string equivalent dargestellt
    printf("x = %d\n", x); //druckt x in int repräsentation
    printf("x = ");
    for (i = 32768; i > 0; i >>= 1) //i ist gleich die höchste short zahl, also 100000000, solange es nicht null ist shifte es nach rechts
    {
        printf("%d", (x & i) > 0); //druckt die binär darstellung der Zahl
    }
    printf("\n\n");
    printf("x_chr = %c \n", *p_chr); //druckt den wert von x als equivalenten char
    printf("x_chr = %d \n", *p_chr); //druckt den wert von x als int
    printf("x_chr = ");              //druckt x_chr
    for (i = 128; i > 0; i >>= 1)    //i = bitanzahl. solange nicht null, shifte um 1
    {
        printf("%d", ((*p_chr) & i) > 0); //Bitwise AND. If Both are 1, 1, else 0
    }                                     // ^ Bitwise XOR. | Bitwise OR. ~ NOT
//diese schleife iteriert über jeden Bit der Zahl 128.
//der erste Bit ist immer 1, somit wird jedesmal eine 1 ausgegeben,
//wenn x an dieser stelle den Bitwert 1 hat.
#endif

#ifdef Aufgabe6
#endif

#ifdef Aufgabe7

    double x;
    double y;
    double z;
    printf("x =");
    scanf("%lf", &x);
    printf("\ny =");
    scanf("%lf", &y);
    printf("\nz =");
    scanf("%lf", &z);
    median(&x, &y, &z);
    printf("arithmetsiches Mittel: \t %lf\ngeometrisches Mittel: \t %lf\nharmonische Mittel: \t %lf\n", x, y, z);

#endif

#ifdef Aufgabe8

    char ch0, *ch1, **ch2, ***ch3, ****ch4; //typ char
    ch1 = &ch0;                             //pointer auf eine speicherstelle vom datentyp char
    ch2 = &ch1;                             //pointer auf pointer auf char
    ch3 = &ch2;                             //pointer auf poiner auf pointer auf char
    ch4 = &ch3;                             //pointer auf pointer auf pointer auf pointer auf char
    // printf("Geben  Sie ein  Zeichen  ein ch = ");
    // scanf("%c", **ch3);
    // printf("\n Ihre  Eingabe  war ch = %c \n", ****ch4);
    scanf("%c", ch1);
    printf("\n Ihre  Eingabe  war ch = %c \n", ***ch3);
    // scanf("%c", &ch0);
    // printf("\n Ihre  Eingabe  war ch = %c \n", **ch2);
    // scanf("%c", ***ch4);
    // printf("\n Ihre  Eingabe  war ch = %c \n", *ch1);

#endif

#ifdef Aufgabe9

    float a, b, c;
    printf("a =");
    scanf("%f", &a);
    printf("\nb =");
    scanf("%f", &b);
    printf("\nc =");
    scanf("%f", &c);

    printf("%f", *maximum(&a, &b, &c));

#endif

#ifdef Aufgabe10

    char ch = 'W';
    int x = 7;
    float y = 3.141;
    void *p;
    p = &ch;
    printf("ch = %c\n", *(char*)p);
    p = &x;
    printf("x   = %d\n", *(int*)p);
    p = &y;
    printf("y   = %f\n", *(float*)p);
/*
Welchen Datentyp hat p?

A: p hat den Datentyp void*

Warum genügt es in den Zeilen 9,11 und 13 nicht einfach nur p zu schreiben?

A: Weil der Pointer in void representation abgespeichert wird. 
Damit er in der entsprechenden Datentyp repräsentation angezeigt wird, braucht man ein entsprechenden cast
Nutzung ohne des Casts führt zu einem Fehler, da kein NULL Pointer angezeigt werden kann(welches der Pointer in void representation entspricht)

Was bedeutet "typecasting"?

A: Als Typumwandlung (englisch type conversion oder type casting, kurz cast)
wird in der Informatik die Umwandlung eines Datentyps in einen anderen bezeichnet, 
um eine Typverletzung zu vermeiden, 
die durch mangelnde Zuweisungskompatibilität gegeben ist.

Was ist der Unterschied zwischen explizieten und implizieten typecasting?

A: beim implizieten typecast wird der Typ durch den compiler passen umintepretiert. 
Dies geschieht zum Beispel bei Mathematischen Operationen mit verschiedenen Typen.
explizites typecasting geschieht durch den () operator, indem man den zieltyp in die klammer schreibt
und den umzuwandelnden Wert nach der klammer schreibt.
Dies bewirkt eine gezielte Typumwandlung und kann beispielweise genutzt werden,
um gezielt Nachkommastellen auszulassen.

*/

#endif





    return 0;
}
