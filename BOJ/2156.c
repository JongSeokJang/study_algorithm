#include<stdio.h>

int data[10000+1];
int res[10000+1][3];
int solve(int N){
  int ii, jj;
  int max;

  for(ii = 0; ii < N; ii++){

    if( ii == 0 ){
      res[ii][0] = 0;
      res[ii][1] = data[ii];
      res[ii][2] = 0;
    }
    else{
      if( res[ii-1][1] > res[ii-1][2] )
        res[ii][0] = res[ii-1][1];
      else 
        res[ii][0] = res[ii-1][2];

      res[ii][1] = res[ii-1][0] + data[ii];
      res[ii][2] = res[ii-1][1] + data[ii];
    }
  }
/*
  for( ii = 0; ii < N; ii++){
    printf("%d : ", ii);
    for( jj = 0; jj < 3; jj++)
      printf("[%d]", res[ii][jj]);
    printf("\n");
  }
  */

  max = res[ii][0];
  for( ii = 0; ii < 3; ii++){
    if( res[N-1][ii] > max )
      max = res[N-1][ii];
  }
  return max;

}

int main(void){
  int N;
  int ii;
  scanf("%d", &N);
  for( ii = 0; ii < N; ii++)
    scanf("%d", &data[ii]);

  printf("%d\n", solve(N));
  
  

}
