#include<stdio.h>
#include<string.h>

#define MAX_SIZE 10000

int primeField[10000];

void MakePField(void){
  int ii, jj;

  primeField[0] = primeField[1] = -1;
  for( ii = 2; ii < MAX_SIZE; ii++){
    for( jj = 2;; jj++){
      if( ii * jj <= MAX_SIZE){
        primeField[ii*jj] = -1;
      }
      else{
        break;
      }
    }
  }
}

void solve(int N){

  int ii;
  int min = 9999999;
  int temp;
  int n1, n2;
  for( ii = 2; ii < N; ii++){

    if( primeField[ii] == 0){
      if( primeField[ N - ii ] == 0){

        temp = (N-ii) -ii;
        if( temp < 0)
          temp *= -1;
        
        if( min > temp ){
          min = temp;
          n1 = ii, n2 = N-ii;
        }

      }
    }
  }
  printf("%d %d\n", n1, n2);
}

int main(void){
  int T;
  int N;
  scanf("%d", &T);

  MakePField();

  while(T--){
    scanf("%d", &N);
    solve(N);
  }
}
