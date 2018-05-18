
#include<stdio.h>

int check_prime(int num){

  int ii;

  if(num == 1){
    return 0;
  }
  else{
    for( ii = 2; ii < num-1; ii++){
      if( num%ii == 0)
        return 0;
    }
    return 1;
  }

}

int main(void){
  int N;
  int num;
  int result = 0;
  scanf("%d", &N);

  while(N--){
    scanf("%d", &num);

    result += check_prime(num);
  }

  printf("%d\n", result);

}
