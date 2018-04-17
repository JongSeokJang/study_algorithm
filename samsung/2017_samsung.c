#include<stdio.h>
#include<string.h>

int N;
int Arr[11];
int Min = 1000000001;
int Max = -1000000001;

void solve( int idx, int sum, int plus, int minus, int mul, int mod){

  
  if(idx == N){
  
    if( sum < Min )
      Min = sum;
    if( sum > Max )
      Max = sum;
    
    return;
  }

  if(plus)
    solve(idx + 1, sum + Arr[idx], plus-1, minus, mul, mod);
  if(minus)
    solve(idx + 1, sum - Arr[idx], plus, minus-1, mul, mod);   
  if(mul)
    solve(idx + 1, sum * Arr[idx], plus, minus, mul-1, mod);  
  if(mod)
    solve(idx + 1, sum / Arr[idx], plus, minus, mul, mod-1); 

}

int main(void){
  
  int ii;
  
  int Plus, Minus, Mul, Mod;


  scanf( "%d", &N );

  for( ii = 0; ii < N; ii++ ){
    scanf("%d", &Arr[ii]);
  }

  scanf("%d %d %d %d", &Plus, &Minus, &Mul, &Mod);
  solve(1, Arr[0], Plus, Minus, Mul, Mod);
  
  printf("%d %d \n", Max, Min);
  return 0;
}

