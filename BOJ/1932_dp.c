#include<stdio.h>
#include<string.h>
#define MAX_SIZE 500
int triangle[MAX_SIZE][MAX_SIZE];
int memo[MAX_SIZE][MAX_SIZE];

void solve(int row){

  int curValue;
  int ii, jj;
  for( ii = 0; ii < row; ii++){
    for( jj = 0; jj <= ii; jj++){

      curValue = triangle[ii][jj];
      if( ii == 0 && jj == 0){
        memo[ii][jj] = curValue;
      }
      else if( jj == 0){
        memo[ii][jj] = memo[ii-1][jj] + curValue;;
      }
      else if( ii == jj )
        memo[ii][jj] = memo[ii-1][jj-1] + curValue;
      else{
        if( memo[ii-1][jj] > memo[ii-1][jj-1])
          memo[ii][jj] = memo[ii-1][jj] + curValue; 
        else 
          memo[ii][jj] = memo[ii-1][jj-1] + curValue; 
      }
    }
  }
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
  
  solve(rows);

  for( ii = 0; ii < rows; ii++){
    for( jj = 0; jj <= ii; jj++)
      printf("%d ", memo[ii][jj]);
    printf("\n");
  }

  for( ii = 0; ii < rows; ii++){
    if( max < memo[rows-1][ii])
      max = memo[rows-1][ii];
  }
  printf("%d\n", max);



}
