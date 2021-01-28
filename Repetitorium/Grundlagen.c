/*
1.1 


*/
#include <stdio.h>
#include <stdlib.h>
#define AUFGABE10



int isprime(int n){
for (int i = 2; i < n; i++)
{
    if (n%i == 0)
    {
        return 0;
    }
}

return 1;
}

long squarsum(int i){
    double n = 0;
    for (int j = 1; j <=i; j++)
        n+=(j*j);
    return n;
}


int main()
{

#ifdef AUFGABE1

    int a = 5;
    int b = -3;
    a = b = a;
    printf("\n%d\t%d\n", a, b);

#endif

#ifdef AUFGABE2

    float a = 0;
    int c, i;
    for{i = 0;i < 5;i++}
    a = a + i;
    printf("\n%f\t%d\n", a);

#endif 

#ifdef AUFGABE3

    int i = 5;for (i = 0; i < 3; i--) {i  -= i;printf("i = %3d", i);}

#endif 

#ifdef AUFGABE3

    int i = 5;for (i = 0; i < 3; i--) {i  -= i;printf("i = %3d", i);}

#endif 

#ifdef AUFGABE4

    printf("%d", (int)isprime((unsigned int)35));

#endif 


#ifdef AUFGABE6

int i;
double x, y;
scanf("%d %lf %lf", &i, &x, &y);
printf("\ni = %d x= %lf y= %lf", i, x, y);

#endif 

#ifdef AUFGABE7

int N = 80;
printf("\n");
for (int count = 1; count <= N*N; count++)
{  
    if (isprime(count) == 1)
    {
        printf("p ");
    }else{
        printf("* ");
    }
    
    if (count%N ==0)
    {
        printf("\n");
    }
}

#endif 
    
#ifdef AUFGABE8

int N, D;
N = 30;
D = 3;
int count=0;
for (int i = 1; i <= N; i++)
{
    if (i %D == 0)
    {
        count++;
    }
}
printf("%d", count);

#endif 

#ifdef AUFGABE9

int N = 7;
int count = 0;
for (int a = 1; a <= N; a++)
{
    for (int b = 1; b <= N; b++)
    {
        for (int i = 2; i < (a*a+b*b); i++)
        {
            if (((float)((float)a*a+b*b)/i) == i)
            {
                count++;
            }   
        }
    }
}
printf("%d", count);

#endif 

#ifdef AUFGABE10

int N = 0;
scanf("%d", &N);
int *ptr_N = (int*) malloc(sizeof(int)*N);

for(int i = 0; i < N; i++){
    printf("%d\t", i+1);
    scanf("%d", &ptr_N[i]);
    printf("\n");
}

// for (int i = 0; i < N; i++)
// {
//     for (int j = 0; j < N; j++)
//     {
//         if (ptr_N[i]<ptr_N[j])
//         {
//             int temp = ptr_N[i];
//             ptr_N[i] = ptr_N[j];
//             ptr_N[j]= temp;
//         }
        
//     }
    
// }

for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N-1; j++)
    {
        if (ptr_N[j]>ptr_N[j+1])
        {
            int temp = ptr_N[j];
            ptr_N[j] = ptr_N[j+1];
            ptr_N[j+1]= temp;
        }
        
    }
    
}


for (int i = 0; i < N; i++)
{
    printf("%d\t", ptr_N[i]);
}

#endif 

    return 0;
}
