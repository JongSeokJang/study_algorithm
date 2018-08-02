#include<stdio.h>
int check(int number){

  int count = 0;
  if( number < 10 ){
    if( number %3 == 0 ){
      printf("- ");
      return 0;
    }
    else{
      return 1;
    }
  }
  else if( number < 100 ){
    //printf("\nhihi");

    if( (number/10) %3 == 0 )
      count++;
    if( (number%10) %3 == 0  && number%10 != 0)
      count++;
    //printf("count : %d\n",count);

    if( count == 0 )
      return 1;
    else{
      if( count == 1)
        printf("- ");
      else
        printf("-- ");
      return 0;
    }
  }
  else{
    if( (number/100) %3 == 0 )
      count++;
    if( ((number%100)/10) %3 == 0 && (number%100)/10 != 0)
      count++;
    if( (number%10) %3 == 0 && number%10 != 0) 
      count++;

    if( count == 0)
      return 1;
    else{
      if( count == 1)
        printf("- ");
      else if (count == 2)
        printf("-- ");
      else
        printf("--- ");
      return 0;
    }
  }

}

int main(void){
  int ii;
  int N;
  scanf("%d", &N);
  for( ii = 1; ii <=N; ii++){
    if( check(ii) )
      printf("%d ", ii);
  }
  printf("\n");

}
