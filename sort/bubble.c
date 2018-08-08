#include<stdio.h>
int data[10] = {5,1,9,2,8,3,7,6,4,0};

void bubble(){
  int ii, jj;
  int temp;
  for( ii = 0; ii < 10; ii++){
    for( jj = 0; jj < (10-1)-ii; jj++){
      
      if( data[jj] >= data[jj+1]){
        temp = data[jj];
        data[jj] = data[jj+1];
        data[jj+1] = temp;
      }
    }
  }
}

int main(void){

  int ii;
  for( ii = 0; ii <10; ii ++)
    printf("[%d]", data[ii]);
  printf("\n");
  
  bubble();
  for( ii = 0; ii <10; ii ++)
    printf("[%d]", data[ii]);
  printf("\n");

}
