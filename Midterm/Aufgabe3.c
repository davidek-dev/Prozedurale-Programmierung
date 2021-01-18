#include <stdio.h>

void  print_reverse(int*a, int n){
    for(int i = n-1; i>=0; i--){
        printf("%d", a[i]);
    }
}

void print_array(int* a,int len, void (*func_ptr)(int *a, int n)){
    func_ptr(a, len);
}


float quadrat(float Kantenlange, float* umfang){
    *umfang = Kantenlange*4; //call by pointer
    return Kantenlange*Kantenlange; //call by value
}

/*
CALL BY VALUE
While calling a function, we pass values of variables to it.
Such functions are known as “Call By Values”.

In this method, the value of each variable in calling function
is copied into corresponding dummy variables of the called function.

With this method, the changes made to the dummy variables in the called 
function have no effect on the values of actual variables in the calling function.


CALL BY REFERENCE
While calling a function, instead of passing the values of variables, we pass address 
of variables(location of variables) to the function known as “Call By References.

In this method, the address of actual variables in the calling 
function are copied into the dummy variables of the called function.

With this method, using addresses we would have an access 
to the actual variables and hence we would be able to manipulate them.
*/



int main(){
    float Kantenlange = 2;
    float Umfang = 0;
    float Flacheninhalt = quadrat(Kantenlange, &Umfang);
    //printf("\nKantenlange:\t%f\nUmfang:\t%f\nFlacheninhalt:\t%f\n\n", Kantenlange, Umfang, Flacheninhalt);

    int a[]={1, 2, 3, 4, 5};
    int len = 5;


    print_array(a, len, print_reverse);

}