#include<stdio.h>
#include<string.h>





int main(void){

  int n;
  int ii;
  int temp;
  int max;
  int need_value[10];

  scanf("%d", &n);
  memset( need_value, 0x00, sizeof(need_value) );
  if( n == 0 ){
    printf("1\n");
    return 0;
  }

  while( n ){
    temp = n % 10;
    need_value[temp]++;
    n /= 10;
  }

  max = need_value[6] + need_value[9];
  if( max % 2)
    max = (max + 1) /2;
  else 
    max = max / 2;

  for( ii = 0; ii < 10; ii++){
    if( ii == 6 || ii == 9 )
      continue;
 
    if( need_value[ii] > max )
      max = need_value[ii];
    
  }

  printf("%d\n", max);

  
}
