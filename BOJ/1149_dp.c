#include<stdio.h>
#include<string.h>

int RGB[1000][3];
int memo[1000][3]; // RGB

int solve(int N){
  int ii, jj;
  int r,g,b;
  int min;
  for( ii = 0; ii < N; ii++){
    for( jj = 0; jj < 3; jj++){
      if( ii == 0 ){
        memo[ii][jj] = RGB[ii][jj];
      }
      else{
        r = memo[ii-1][0];
        g = memo[ii-1][1];
        b = memo[ii-1][2];
        switch(jj){
          case 0 :  // current color RED
            if( g > b )
              memo[ii][jj] = b + RGB[ii][jj];
            else
              memo[ii][jj] = g + RGB[ii][jj];
            break;
          case 1:   // current color GREEN
            if( r > b )
              memo[ii][jj] = b + RGB[ii][jj];
            else
              memo[ii][jj] = r + RGB[ii][jj];
            break;
          case 2:   // current color BLUE
            if( r > g )
              memo[ii][jj] = g + RGB[ii][jj];
            else
              memo[ii][jj] = r + RGB[ii][jj];
            break;
        }
      }
    }
  }

  min = memo[N-1][0];
  for( jj = 0; jj < 3; jj++){
    if( min > memo[N-1][jj])
      min = memo[N-1][jj];
  }
  return min;
}

int main(void){
  int ii, jj;
  int N;

  scanf("%d", &N);
  for( ii = 0; ii < N; ii++){
    for( jj = 0; jj < 3; jj++)
      scanf("%d", &RGB[ii][jj]);
  }
  printf("%d\n", solve(N) );

}

