#include<stdio.h>
#include<string.h>


#define MAX_SIZE 300000

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
  int jj;
  int num;
  int cnt;
  
  memset( prime_field, 0x00, sizeof(prime_field) );

  make_field(MAX_SIZE);

  while(1){
    scanf("%d", &num);
    cnt = 0;

    if( num == 0 )
      break;

    for( ii = num+1; ii <= 2*num; ii++){
      if( prime_field[ii] == 0){
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }

}
