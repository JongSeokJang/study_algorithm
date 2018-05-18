#include<stdio.h>

int main(void){
  int ii;
  int input;
  int temp = 0;
  int a1, a2;
  scanf("%d", &input);


  for( ii = 1; ; ii++){

    temp += ii;
    if( input <= temp ){
      if( ii % 2 == 0){
        a1 = input-(temp-ii);
        a2 = (ii+1) - a1;
      }
      else{
        a2 = input-(temp-ii);
        a1 = (ii+1) - a2;

      }
      break;
    }
  }
  printf("%d/%d\n", a1, a2);

  return 0;
}
