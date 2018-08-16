#include<stdio.h>
#include<string.h>
#define MAX_SIZE 500
int triangle[MAX_SIZE][MAX_SIZE];
int memo[MAX_SIZE][MAX_SIZE];

void solve(int row, int col, int size){

  if( row == size )
    return;

  if( row == 0 && col == 0){
    memo[row][col] = triangle[row][col];
  }
  else{
    if( col == 0 ){
      memo[row][col] = memo[row-1][col] + triangle[row][col];
    }
    else if( col == row ){
      memo[row][col] = memo[row-1][col-1] + triangle[row][col];
    }
    else{
      if( memo[row-1][col-1] > memo[row-1][col])
        memo[row][col] = memo[row-1][col-1] + triangle[row][col];
      else 
        memo[row][col] = memo[row-1][col] + triangle[row][col];
    }
  }
  solve(row+1, col, size);
  solve(row+1, col+1, size);
}

int main(void){

  int max = 0;
  int ii, jj;
  int rows;

  memset(triangle, 0x00, sizeof(triangle));
  memset(memo, 0x00, sizeof(memo));

  scanf("%d", &rows);
  for( ii = 0; ii < rows; ii++){
    for( jj = 0; jj <= ii; jj++)
      scanf("%d", &triangle[ii][jj]);
  }
  
  solve(0,0, rows);

  for( ii = 0; ii < rows; ii++){
    if( max < memo[rows-1][ii])
      max = memo[rows-1][ii];
  }
  printf("%d\n", max);



}
