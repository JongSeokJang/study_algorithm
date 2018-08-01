#include<stdio.h>
#include<string.h>

typedef struct _ladder{
  int x;
  int visit;
}ladder;

ladder field[100][100];

int findStart(int end){
  int row = 100;
  while( row-- ){
    field[row][end].visit = 1;

    if( end == 0 ){ //current position is left
      if( field[row][end+1].x == 1 && field[row][end+1].visit == 0 ){
        end = end+1;
        row++;
      }
    }
    else if( end == 99 ){ // current position is right
      if( field[row][end-1].x == 1 && field[row][end-1].visit == 0 ){
        end = end-1;
        row++;
      }
    }
    else{ // middle
      // move to right
      if( field[row][end+1].x == 1 && field[row][end+1].visit == 0 ){
        end = end + 1; 
        row++;
      }

      // move to left
      if( field[row][end-1].x == 1 && field[row][end-1].visit == 0 ){
        end = end-1;
        row++;
      }
    }
  }
  return end;
}

int main(void){
  int ii, jj, kk;
  int now_count;
  int start, end;
  for( ii = 0; ii < 10; ii++){

    scanf("%d", &now_count);
    memset(field, 0x00, sizeof(field));

    for( jj = 0; jj < 100; jj++){
      for( kk = 0; kk < 100; kk++)
        scanf("%d", &field[jj][kk].x);
    }
    for( jj = 0; jj < 100; jj++){
      if( field[99][jj].x == 2 ){
        end = jj;
        break;
      }
    }

    start = findStart(end);
    printf("#%d %d\n", ii+1, start);

  }

}
