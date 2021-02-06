#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define AUFGABE2

void scalar_mult(int n, float *v, float a){
    for (int i = 0;i < n; i++) v[i]=v[i]*a;
    return;
}

/*Here you see the dangers of C: a ptr just points to memory and has no way of knowing what supposed size is. 
You can just increment and increment and the OS might complain eventually, or you crash your program, 
or corrupt other ones. 

You should always specify the size, and check bounds yourself!*/

void vec_add(int n, float *u, float *v){
    for (int i = 0;i < n; i++) u[i]=u[i]+v[i];
    return;
}

float scalar_prod(int n, float *u, float *v){
    float sum=0;
    for (int i = 0; i < n; i++)
    {
        sum += (u[i]*v[i]);
    }
    return sum;
}

float two_norm(int n, float *v){
    return sqrt(scalar_prod(n, v, v));
}



int main(){

#ifdef AUFGABE1
int dimension = 0;
float *u = NULL;
float *v = NULL;
printf("\nDimension:\t");
scanf("%d", &dimension);
u = (float*) malloc(sizeof(float)*dimension);
v = (float*) malloc(sizeof(float)*dimension);
for(int i = 0; i < dimension; i++){
    printf("\nEintrag %d von %d von Array u:\t", i+1, dimension);
    scanf("%f", &u[i]);
    printf("\nEintrag %d von %d von Array v:\t", i+1, dimension);
    scanf("%f", &v[i]);
}

float a = 3;
scalar_mult(dimension, v, a);
printf("\n");
for (int i = 0; i < dimension; i++) printf("%f\t", v[i]);
vec_add(dimension, u, v);
printf("\n");
for (int i = 0; i < dimension; i++) printf("%f\t", u[i]);

#endif

#ifdef AUFGABE2

int dimension = 0;

printf("\nDimension:\t");
scanf("%d", &dimension);

float *u = NULL;
float *v = NULL;

u = (float*) malloc(sizeof(float)*dimension);
v = (float*) malloc(sizeof(float)*dimension);

for(int i = 0; i < dimension; i++){
    printf("\nEintrag %d von %d von Array u:\t", i+1, dimension);
    scanf("%f", &u[i]);
    printf("\nEintrag %d von %d von Array v:\t", i+1, dimension);
    scanf("%f", &v[i]);
}

printf("\nu_t * v=\t");

printf("\t%f", scalar_prod(dimension, u, v));

printf("\n||v||_2=\t");

printf("\t%f", two_norm(dimension, v));

#endif


    return 0;
}