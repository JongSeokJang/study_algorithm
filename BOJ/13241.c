#include<stdio.h>

int GCD (long long a, long long b){
  long long mod = 0;
  while( (mod = a%b) ){
    a = b;
    b = mod;
  }
  return b;
}

int main(void){

  long long n1, n2;
  scanf("%lld %lld", &n1, &n2);

  printf("%lld\n", n1 * n2 /GCD(n1,n2) );
  

}

