#include<stdio.h>
#include<string.h>

#define MATRIX_SIZE 8

char field[8+1][8+1];


int findSameWord(int circular){

  int ii, jj, kk;
  int isSame;
  int sameCount = 0;
  // search to width
 
  for( ii = 0; ii < MATRIX_SIZE; ii++){
    for( jj = 0; jj < MATRIX_SIZE-circular+1; jj++){
     
      isSame = 1;
      for( kk = 0; kk < circular/2; kk++){
        //printf("[%d][%d]:%c // [%d][%d]:%c\n", ii, jj+kk, field[ii][jj+kk], ii, jj+circular-1-kk, field[ii][jj+circular-1-kk]);
        if( field[ii][jj+kk] != field[ii][jj+(circular-1)-kk]){
          isSame = 0;
          break;
        }
      }
      if( isSame == 1){
        //printf("++\n");
        sameCount++;
      }
    }
  } 
  // search to vertical
  //printf("====verticle \n====");
  for( jj = 0; jj < MATRIX_SIZE; jj++){
    for( ii = 0; ii < MATRIX_SIZE-circular+1; ii++){

      isSame = 1;
      for( kk = 0; kk < circular/2; kk++){
        //printf("[%d][%d]:%c // [%d][%d]:%c\n", ii+kk, jj, field[ii+kk][jj], ii+circular-1-kk, jj,field[ii+circular-1-kk][jj]);
        if( field[ii+kk][jj] != field[ii+(circular-1)-kk][jj]){
          isSame = 0;
          break;
        }
      }
      if( isSame == 1){
        //printf("++\n");
        sameCount++;
      }
    }
  }

  return sameCount;
}

int main(void){
  int ii, jj, kk;
  int circular;
  int circular_count;

  for( ii = 1; ii <= 10; ii++){

    memset(field, 0x00, sizeof(field));

    scanf("%d", &circular);
    getchar();
    for( jj = 0; jj < MATRIX_SIZE; jj++){
      for( kk = 0; kk < MATRIX_SIZE; kk++)
        scanf("%c", &field[jj][kk]);
      getchar();
    }

    circular_count = findSameWord(circular);
    printf("#%d %d\n", ii, circular_count);
  }
}
