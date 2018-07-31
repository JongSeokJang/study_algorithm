#include<stdio.h>

int main(void){

  int sum = 0;
  int T;
  int ii;
  scanf("%d", &T);
  for( ii = 1; ii <= T; ii++ )
    sum += ii;
  printf("%d\n", sum);

}
