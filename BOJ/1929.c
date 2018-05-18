#include<stdio.h>
#include<string.h>


#define MAX_SIZE 1000000

int prime_field[MAX_SIZE];

void make_field(int num2){

  int ii, jj;
  prime_field[0] = -1;
  prime_field[1] = -1;

  for( ii = 2; ii < num2; ii++){

    for( jj = 2; ; jj++){
      if(ii*jj <= num2){
        prime_field[ii*jj] = -1;
      }
      else{
        break;
      }
    }
  }
}

int main(void){
  int ii;
  int n1, n2;
  
  scanf("%d %d", &n1, &n2);
  memset( prime_field, 0x00, sizeof(prime_field) );

  make_field(n2);
  for( ii = n1; ii <= n2; ii++){
    if( prime_field[ii] == 0)
      printf("%d\n", ii);
  }

}
