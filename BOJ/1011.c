#include<stdio.h>
#include<string.h>

int main(void){

  int s, e;
  int ii;
  int temp;
  long long sum = 0;
  scanf("%d %d", &s, &e);

  for( ii = s; ii <= e; ii++){

    temp = ii;
    while( temp ){
      sum += temp % 10;
      temp /= 10;
    }

  }

  
  printf("%lld\n" , sum);

}
