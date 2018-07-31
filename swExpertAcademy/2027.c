#include<stdio.h>

int main(void){
  int ii, jj;
  for( ii = 0 ; ii < 5 ; ii ++ ){
    for( jj = 0; jj < 5 ; jj++){
      if( jj == ii )
        printf("#");
      else
        printf("+");
    }
    printf("\n");

  }
}
