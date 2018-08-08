#include<stdio.h>
int data[10] = {5,1,9,2,8,3,7,6,4,0};

void selection(){
  int ii, jj;
  int temp;
  int min;
  for( ii = 0; ii < 10; ii++){
    min = ii;
    for( jj = ii+1; jj < 10; jj++){
      if( data[min] >= data[jj])
        min = jj;
    }
    temp = data[min];
    data[min] = data[ii];
    data[ii] = temp;
  }
}

int main(void){

  int ii;
  for( ii = 0; ii <10; ii ++)
    printf("[%d]", data[ii]);
  printf("\n");
  
  selection();
  for( ii = 0; ii <10; ii ++)
    printf("[%d]", data[ii]);
  printf("\n");

}
