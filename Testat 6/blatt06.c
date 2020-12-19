#include "libBMP.h"
#include <stdio.h>
#define W 500
#define H 500
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

const double x_min = -5;
const double x_max = 5;
const double y_min = -5;
const double y_max = 5;

//1.2 Übersetzung BMP zu Koordinaten
//------------------------------------------------
void toMath(unsigned int bmp_x, unsigned int bmp_y, double *x, double *y)
{
    //zunächst problem behandlung: out of bounds damit bei out of bounds trotzdem gedruckt wird.
    if ((bmp_x < 0) || (bmp_x > W) || (bmp_y < 0) || (bmp_y > H)) //bei fehler setze wert auf Koordinatenachse
    {
        *x = x_min;
        *y = y_min;
        return;
    }

    *x = x_min + ((bmp_x * (x_max - x_min)) / W);
    *y = y_min + ((bmp_y * (y_max - y_min)) / H);
    return;
}


void toBMP(double math_x, double math_y, unsigned int *x, unsigned int *y)
{
    //zunächst problem behandlung: out of bounds damit bei out of bounds trotzdem gedruckt wird.
    if ((math_x < x_min) || (math_x > x_max) || (math_y < y_min) || (math_y > y_max)) //bei fehler setze wert auf Koordinatenachse
    {
        *x = 0;
        *y = 0;
        return;
    }

    *x = (int)((math_x - x_min) * W / (x_max - x_min));     //einfach die formel aus dem arbeitsblatt umformen
    *y = H - (int)((math_y - y_min) * H / (y_max - y_min)); //H -, weil maximales H ja ganz oben ist als bei niedrigem BMP
    return;
}



int main()
{

    //1.1 Weißer Hitnergrund
    //------------------------------------------------
    uint32_t *canvas = malloc(W * H * sizeof(uint32_t)); //erstelle ein dynamische Array der Größe WxH mit sizeof uint_32

    for (int i = 0; i < W * H; i++)
    {
        *(canvas + i) = COLOR_WHITE; //färbt jeden eintrag von canvas Weiß
    }

    //1.3 Koordinatenachsen
    //------------------------------------------------
    int bmp_x_kord = 0;
    int bmp_y_kord = 0;
    toBMP(0.0, 0.0, &bmp_x_kord, &bmp_y_kord); //setzt die BMP punkte auf die felder, wo der koordinaten ursprung ist

    for (unsigned int i = 0; i < W; i++)
    {
        canvas[bmp_y_kord * W + i] = COLOR_BLACK; //ykord*W ist eine konstante und represäntiert die höhe des koordinatenursprungs in bmp
    }                                             //+i geht einen x wert weiter

    for (unsigned int i = 0; i < H; i++)
    {
        canvas[i * W + bmp_x_kord] = COLOR_BLACK; //gleiches prinzip wie oben, bloß das x diesmal konstant bleibt
    }

    //1.4 Funktionsplot
    //------------------------------------------------
    double math_x_kord;
    double math_y_kord;
    double f_x;

    for (unsigned int i = 0; i < W; i++)
    {
        toMath(i, 0, &math_x_kord, &math_y_kord);                            //schreibt i(bmp) in math_x und schreibt max_y in math_y_kord
        toBMP(math_x_kord, pow(math_x_kord, 2.0), &bmp_x_kord, &bmp_y_kord); //schreibt x=toMath(i) in bmp_x und f(x)=? in bmp_y
        canvas[bmp_y_kord * W + i] = COLOR_RED;                              //nach prinzip der koordinatenachsen
    }

    bmp_create("graph.bmp", canvas, W, H);
    free(canvas);

    return 0;
}