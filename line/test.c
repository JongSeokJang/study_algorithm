#include<stdio.h>


int main(void){
  int data = 1;
  int ii;

  for( ii = 0; ii < 10; ii++){

    printf("%d\n", data);


    if( ii == 9 ){
      printf("end\n");
    }

  }

  return 0;
}
