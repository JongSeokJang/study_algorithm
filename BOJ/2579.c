#include<stdio.h>
int data[300];
int memo[300][3];

int solve(int size){
  int cVal;
  int ii, jj;
  int max;

  for(ii = 0; ii < size; ii++){
    for(jj =0; jj < 3; jj++){
      cVal = data[ii];
      if( ii == 0 ){
        memo[ii][0] = 0;
        memo[ii][1] = cVal;
        memo[ii][2] = 0;
      }
      else if( ii == size-1 ){
        memo[ii][0] = 0;
        memo[ii][1] = memo[ii-1][0] + cVal;
        memo[ii][2] = memo[ii-1][1] + cVal;
      }
      else{
        if( memo[ii-1][1] > memo[ii-1][2])
          memo[ii][0] = memo[ii-1][1];
        else
          memo[ii][0] = memo[ii-1][2];
        memo[ii][1] = memo[ii-1][0] + cVal;
        memo[ii][2] = memo[ii-1][1] + cVal;
      }
    }
  }
  if( memo[ii-1][1] > memo[ii-1][2])
    max = memo[ii-1][1];
  else 
    max = memo[ii-1][2];
    
  return max;

}

int main(void){
  int T;
  int ii;
  scanf("%d", &T);

  for( ii = 0; ii < T; ii++)
    scanf("%d", &data[ii]);

  printf("%d\n", solve(T));
  

}

