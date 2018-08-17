#include<stdio.h>
int memo[1000001];

int min2(int a, int b){
  if ( a < b)
    return a;
  else
    return b;
}

int min3(int a, int b, int c){
  int min = 0;
  if( a <= b && a <= c )
    min = a;
  if( b <= a && b <= c )
    min = b;
  if( c <= a && c <= a)
    min = c;
  return min;
}

int solve(int size){

  int ii;
  memo[1] = 0;
  memo[2] = 1;
  memo[3] = 1;

  for( ii = 4; ii <= size; ii++){
    if( ii % 3 == 0 ){
      if( ii % 2 == 0 )
        memo[ii] = min3(memo[ii/3], memo[ii/2], memo[ii-1]) + 1;
      else
        memo[ii] = min2(memo[ii/3], memo[ii-1]) + 1;
    }
    else{
      if( ii % 2 == 0)
        memo[ii] = min2(memo[ii/2], memo[ii-1]) + 1;
      else
        memo[ii] = memo[ii-1] + 1;
    }
  }
  return memo[size];
}

int main(void){
  int size;
  scanf("%d", &size);
  printf("%d\n",solve(size));
}
