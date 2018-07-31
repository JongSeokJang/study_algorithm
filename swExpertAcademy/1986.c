#include<stdio.h>

int main(void){

  int sum = 0;
  int T;
  int num;
  int ii;
  int count = 1;
  scanf("%d", &T);

  while(T--){
    scanf("%d", &num);
    sum = 0;
    for( ii = 0; ii < num; ii++){
      if( (ii + 1) %2 == 1 ) // odd
        sum += (ii+1);
      else // even
        sum -= (ii+1);
    }
    printf("#%d %d\n", count, sum);
    count ++;
  }
}
