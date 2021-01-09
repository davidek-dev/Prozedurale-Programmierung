#include "libBMP.h"
#include <stdio.h>
#include <math.h>
//#define W 1000
//#define H 800
#define W 3840//4k test
#define H 3840
#include <stdint.h>
#include <stdlib.h>

const double x_min = -2.1;//4k modification
const double x_max = 2.1;
const double y_min = -2.1;
const double y_max = 2.1;

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


//Berechnung der Mandelbrot Rekursions tiefe
//------------------------------------------------
//complexe zahl c= x+ i*y
//real teil = x
//imaginär teil = y
int max_tiefe(double c_x, double c_y, double z_x, double z_y, int n_max, int n){
    //z_n+1 = z_n^2 +c
    //x_n+1 = x_n^2 - y_n^2 + c_x
    //y_n+1 = 2*x_n*y_n + c_y
    if ((n>n_max)||(sqrt(pow(z_x, 2.0)+pow(z_y, 2.0))>=2))
    {   
        return n;
    } else
    {
        max_tiefe(c_x, c_y, (pow(z_x, 2.0) - pow(z_y, 2.0) + c_x),2.0*z_x*z_y+c_y, n_max, n+1);
    }
}



int main(){
  
  
   //1.1 Weißer Hitnergrund
    //------------------------------------------------
    uint32_t *canvas = malloc(W * H * sizeof(uint32_t)); //erstelle ein dynamische Array der Größe WxH mit sizeof uint_32
    double x, y;

for (int i = 0; i < H; i++)
{
    for (int j = 0; j < W; j++)
    {       
        toMath(j, i, &x, &y);
        // switch (max_tiefe(x, y, 0.0, 0.0, 500, 0))
        // {

        // case 0 ... 4:
        //     canvas[i * W + j] = COLOR_WHITE;
        //     break;
        // case 5 ... 9:
        //     canvas[i * W + j] = COLOR_GREEN;
        //     break;
        // case 10 ... 19:7
        //     canvas[i * W + j] = COLOR_BLUE;
        //     break;
        // case 20 ... 499:
        //     canvas[i * W + j] = COLOR_RED;
        //     break;
        // default:
        //     canvas[i * W + j] = COLOR_BLACK;
        //     break;
        // }
        switch (max_tiefe(x, y, 0.0, 0.0, 500, 0))
        {
        case 0:
            canvas[i * W + j] = COLOR_WHITE;
            break;
        case 1:
            canvas[i * W + j] = pstlblgr_green1;
            break;
        case 2:
            canvas[i * W + j] = pstlblgr_green2;
            break;
        case 3:
            canvas[i * W + j] = pstlblgr_green3;
            break;
        case 4:
            canvas[i * W + j] = pstlblgr_green4;
            break;
        case 5:
            canvas[i * W + j] = pstlblgr_green5;
            break;
        case 6:
            canvas[i * W + j] = pstlblgr_green6;
            break;
        case 7:
            canvas[i * W + j] = pstlblgr_green7;
            break;
        case 8:
            canvas[i * W + j] = pstlblgr_green8;
            break;
        case 9:
            canvas[i * W + j] = pstlblgr_green9;
            break;
        case 10:
            canvas[i * W + j] = pstlblgr_green10;
            break;
        case 11:
            canvas[i * W + j] = pstlblgr_green11;
            break;
        case 12:
            canvas[i * W + j] = pstlblgr_green12;
            break;
        case 13:
            canvas[i * W + j] = pstlblgr_green13;
            break;
        case 14:
            canvas[i * W + j] = pstlblgr_green14;
            break;
        case 15:
            canvas[i * W + j] = pstlblgr_green15;
            break;
        case 16:
            canvas[i * W + j] = pstlblgr_green16;
            break;
        case 17:
            canvas[i * W + j] = pstlblgr_green17;
            break;
        case 18:
            canvas[i * W + j] = pstlblgr_green18;
            break;
        case 19:
            canvas[i * W + j] = pstlblgr_green19;
            break;
        case 20 ... 499:
            canvas[i * W + j] = pstlblgr_green20;
            break;
        default:
            canvas[i * W + j] = COLOR_BLACK;
            break;
        }
    }
    
}

    bmp_create("mandelbrot_pastellgruen_over4k.bmp", canvas, W, H);
    free(canvas);


    return 0;
}