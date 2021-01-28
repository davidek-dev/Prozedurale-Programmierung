#include <stdio.h>

int kgV1(int a, int b){
    int r = b%a;
    if(r==0){
        return b;
    }
    return b* kgV1(r, a) /r;
}

int kgV2(int a, int b){
    if(b%a == 0) return b;
    return b/(b%a) * kgV2(b%a, a);
}


int main(){
    int a = 5;
    int b = 7;
    printf("%d\t%d\n%d\t%d",a, b, kgV1(a,b), kgV2(a,b));

    return 0;
}