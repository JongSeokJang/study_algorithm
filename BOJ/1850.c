#include<stdio.h>
#include<string.h>

int GCD(int n1, int n2){

  int r;

  while( n2 != 0 ){
    r = n1 % n2;
    n1 = n2;
    n2 = r;
  }
  return n1;
}

int main(void){
  int ii;
  int n1, n2;

  int num1 = 1, num2 = 1;
  scanf("%d %d", &n1, &n2);

  for( ii = 1; ii < n1; ii++ ){
    num1 = num1*10 +1;
  }
  for( ii = 1; ii < n2; ii++ ){
    num2 = num2*10 +1;
  }

  printf("%d\n", GCD(num1, num2) );

}
