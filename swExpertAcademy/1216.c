#include<stdio.h>
#include<string.h>

#define MATRIX_SIZE 100

char field[100+1][100+1];


int findSameWord(int circular){

  int ii, jj, kk;
  int isSame;
  int sameCount = 0;
  // search to width
 
  for( ii = 0; ii < MATRIX_SIZE; ii++){
    for( jj = 0; jj < MATRIX_SIZE-circular+1; jj++){
     
      isSame = 1;
      for( kk = 0; kk < circular/2; kk++){
        if( field[ii][jj+kk] != field[ii][jj+(circular-1)-kk]){
          isSame = 0;
          break;
        }
      }
      if( isSame == 1){
        sameCount++;
      }
    }
  } 
  // search to vertical
  for( jj = 0; jj < MATRIX_SIZE; jj++){
    for( ii = 0; ii < MATRIX_SIZE-circular+1; ii++){

      isSame = 1;
      for( kk = 0; kk < circular/2; kk++){
        if( field[ii+kk][jj] != field[ii+(circular-1)-kk][jj]){
          isSame = 0;
          break;
        }
      }
      if( isSame == 1){
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
  int max_count;

  for( ii = 1; ii <= 10; ii++){

    memset(field, 0x00, sizeof(field));
    max_count = 0;

    scanf("%d", &circular);
    getchar();
    for( jj = 0; jj < MATRIX_SIZE; jj++){
      scanf("%s", &field[jj]);
      getchar();
    }

    for( jj = 1; jj < MATRIX_SIZE-1; jj++ ){

      circular_count = findSameWord(jj);
      if( circular_count != 0 ){
        if( max_count <= jj )
          max_count = jj;
      }
    }

    printf("#%d %d\n", ii, max_count);
  }
}
