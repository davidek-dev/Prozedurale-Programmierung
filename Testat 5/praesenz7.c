#include <stdio.h>

void cycle3(int* ptr_a, int* ptr_b, int* ptr_c){
    
    
    int temp = *ptr_c;
    *ptr_c = *ptr_b;    
    *ptr_b = *ptr_a;
    *ptr_a = temp;
    return;
}

int main(){
    int a = 6;
    int b = 4;
    int c = 5;
    printf("\ta = %d\n\tb = %d\n\tc = %d\n\n\n", a, b, c);
    cycle3(&a, &b, &c);
    printf("\ta = %d\n\tb = %d\n\tc = %d\n", a, b, c);
    return 0;
}