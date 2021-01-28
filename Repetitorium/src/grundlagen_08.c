#include <stdio.h>
int main(void) {
  int D,N,n;
  int cnt=0;
  printf("\n N = ");
  scanf("%d",&N);
  printf(" D = ");
  scanf("%d",&D);
  for(n=1; n<=N; n++) if((n%D)==0) cnt++;
  printf("\n %d Zahlen in 1,...,%d sind durch %d teilbar.\n",cnt,N,D);
  return 0;
}
