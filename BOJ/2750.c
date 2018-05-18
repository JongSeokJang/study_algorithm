#include<stdio.h>

int main(void){

  int number[1000];
  int size;
  int ii, jj;
  int temp;

  scanf("%d", &size);
  for( ii = 0; ii < size; ii++){
    scanf("%d", &number[ii]);
  }

  for( ii =0; ii < size; ii++){
    for( jj = ii; jj < size; jj++){
      if( number[ii] > number[jj]){
        temp = number[ii];
        number[ii] = number[jj];
        number[jj] = temp;
      }
    }
  }

  for( ii = 0; ii < size; ii++)
    printf("%d\n",number[ii]);

  return 0;
}
