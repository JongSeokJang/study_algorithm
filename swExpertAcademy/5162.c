#include<stdio.h>
int main(void){
  int ii;
  int TC;
  int a, b, c;
  int min;

  scanf("%d", &TC);
  for( ii = 1; ii <= TC; ii++){
    scanf("%d %d %d", &a, &b, &c);
    if( a < b )
      min = a;
    else
      min = b;
    printf("#%d %d\n", ii, c/min);
  }
}
