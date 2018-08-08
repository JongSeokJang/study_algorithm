#include<stdio.h>
int data[10] = {5,1,9,2,8,3,7,6,4,0};

void insertion(){
  int ii, jj;
  int remember;

  for( ii = 1; ii < 10; ii++){
    remember = data[ii];
    for( jj = ii-1; jj >= 0; jj--){

      if( data[jj] > remember ){
        data[jj+1] = data[jj];
        data[jj] = remember;
      }
      else
        break;
    }
  }
}

int main(void){

  int ii;
  for( ii = 0; ii <10; ii ++)
    printf("[%d]", data[ii]);
  printf("\n");
  
  insertion();
  for( ii = 0; ii <10; ii ++)
    printf("[%d]", data[ii]);
  printf("\n");

}
