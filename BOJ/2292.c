#include<stdio.h>

int main(void){
  int input;
  int ii;
  int size = 1;
  scanf("%d", &input);

  if( input == 1)
    printf("1\n");
  else{
    for( ii = 1;; ii++){
      size += ii*6;
      
      if( input <= size){
        printf("%d\n", ii+1);
        break;
      }
    }
  }
  return 0;
}
