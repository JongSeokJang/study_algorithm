#include<stdio.h>

int main(void){
  int input;
  int cnt = 0;
  scanf("%d", &input);

  while( input != 1){
    cnt++;

    if( input %3 == 0 ){
      input /= 3;
      continue;
    }
    if( input %2 == 0){
      input /= 2;
      continue;
    }

    input -= 1;
  }

  printf("%d\n", cnt);




}
