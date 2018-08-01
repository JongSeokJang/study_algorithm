#include<stdio.h>
#include<string.h>

typedef struct _ladder{
  int x;
  int visit;
}ladder;

ladder field[100][100];
int ladder_count[100];

int findStart(int end){
  int temp_count = 0;
  int row = 100;

  while( row-- ){
    field[row][end].visit = 1;

    if( end == 0 ){ //current position is left
      if( field[row][end+1].x == 1 && field[row][end+1].visit == 0 ){
        end = end+1;
        row++;
        printf(">");
      }
      else{
        printf("^");
      }
    }
    else if( end == 99 ){ // current position is right
      if( field[row][end-1].x == 1 && field[row][end-1].visit == 0 ){
        end = end-1;
        row++;
        printf("<");
      }
      else{
        printf("^");
      }
    }
    else{ // middle
      // move to right
      if( field[row][end+1].x == 1 && field[row][end+1].visit == 0 ){
        end = end + 1; 
        row++;
        printf(">");
      }
      // move to left
      else if( field[row][end-1].x == 1 && field[row][end-1].visit == 0 ){
        end = end-1;
        row++;
        printf("<");
      }
      else{
        printf("^");
      }
    }
    temp_count++;
  }
  printf("\nstart : [%d]\n",  end);
  ladder_count[end] = temp_count;
  return end;
}

int main(void){
  int ii, jj, kk;
  int now_count;
  int start, end;
  int min_index;
  for( ii = 0; ii < 10; ii++){

    scanf("%d", &now_count);
    memset(field, 0x00, sizeof(field) );
    memset(ladder_count, -1, sizeof(ladder_count) );

    for( jj = 0; jj < 100; jj++){
      for( kk = 0; kk < 100; kk++)
        scanf("%d", &field[jj][kk].x);
    }


    for( jj = 0; jj < 100; jj++){
      for( kk = 0; kk < 100; kk++)
        printf("%d", field[jj][kk].x);
      printf("\n");
    }

    for( jj = 0; jj < 100; jj++){
      if( field[99][jj].x == 1 ){
        end = jj;
        start = findStart(end);
        printf("start : %d // end : %d\n", start, end);
      }
    }

    for( jj = 0; jj < 100; jj++)
      printf("ladder_count[%d] : [%d]\n", jj, ladder_count[jj]);

    /*
    min_index = 0;
    for( jj = 0; jj < 100; jj++){
      if( ladder_count[jj] != -1 && ladder_count[min_index] >= ladder_count[jj] )
        min_index = jj;
    }
    printf("#%d %d\n", ii, ladder_count[min_index]);
    */

  }

}
