#include <stdio.h>
#define min(x,y) ((x)<(y))?(x):(y)
int main(void) {
  int a,b,c,q,N;
  int cnt=0;
  printf("\n N = ");
  scanf("%d",&N);
  for(b=1; b<=N; b++) {
    for(a=1; a<=b; a++) {
      q=a*a+b*b;
      c=min(a,b);
      while(c*c<q) c++;
      if((c*c)==q) {
        printf("\n %d^2 + %d^2 = %d^2",a,b,c);
        cnt++;
      }
    }
  }
  printf("\n\n %d Quadratsummen a^2+b^2, 1<=a<=b<=%d, sind ein Quadrat.\n",cnt,N);
  return 0;
}
