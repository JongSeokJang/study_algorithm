#include<stdio.h>

long long int data[100+1];

void solve(int N){
  int ii;
  data[0] = 0;
  data[1] = 9;
  for( ii = 2; ii <= N; ii++)
    data[ii] = 2*(data[ii-1]-(ii-1))+(ii-1);
}
int main(void){
  int n;
  scanf("%d", &n);
  solve(n);
  printf("%lld\n", data[n]);
  printf("%lld\n", data[n]%1000000000);
  


}

