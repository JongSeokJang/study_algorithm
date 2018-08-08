#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int field[10][10];
int result;

void checkField(int row, int col, int size){
  int ii;
  for( ii = row; ii < size; ii++){
    field[ii][col] = 1;
    if( col-ii >= 0 )
      field[ii][col-ii] = 1;
    if( col+ii < size)
      field[ii][col+ii] = 1;
  }
}

void recursive(int row, int size){
  int ii;

  if( row == size )
    return;

  for( ii = 0; ii < size; ii++){
    if( field[row][ii] == 0 )

  }
}

int calcualte(int size){
  int ii, jj, kk;
  for( ii = 0; ii < size; ii++){

  }

}
*/

int main(void){

  int TC;
  int ii, jj, kk;
  int n;
  scanf("%d", &TC);
  for( ii = 1; ii <= TC; ii++){

    scanf("%d", &n);
    memset(field, 0x00, sizeof(field));

    for( jj = 0; jj <n; jj++){
      for( kk = 0; kk < n; kk++)
        printf("[%d]", field[jj][kk]);
      printf("\n"); 
    }
    printf("================\n");

    checkField(0,3,8);

    for( jj = 0; jj <n; jj++){
      for( kk = 0; kk < n; kk++)
        printf("[%d]", field[jj][kk]);
      printf("\n"); 
    }
    /*
    result = 0;

    result = calculate(n);
    */


  }


}


