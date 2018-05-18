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
  int ii;
  int n1, n2;
  int result;
  int min = 9999999, total = 0;
  
  scanf("%d %d", &n1, &n2);

  for ( ii = n1; ii <=n2; ii++){
    result = check_prime(ii);
    if( result ){
      if( min > ii )
        min = ii;
      total += ii;
    }
  }

  if( total == 0){
    printf("-1\n");
    
  }
  else
    printf("%d\n%d\n", total, min);
  

}
