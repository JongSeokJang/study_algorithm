#include<stdio.h>

long long int fibo[100000000];

void make_fibo(int n){

  int ii;
  for(ii = 0; ii <=n; ii++){
    if( ii == 0 || ii == 1)
      fibo[ii] = ii;
    else{
      fibo[ii] = (fibo[ii-1] + fibo[ii-2]) %1000000;
    }
  }
}

int main(void){
  int N;
  scanf("%d", &N);
  make_fibo(N);

  printf("%lld\n", fibo[N]);
}
