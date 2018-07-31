#include<stdio.h>
#include<string.h>

int main(void){
  int ii ;
  char input[80+1];
  scanf("%s", input);
  for ( ii = 0; ii < strlen(input); ii ++) {

    if( 'a' <=  input[ii] && input[ii] <= 'z' )
      printf("%c", input[ii] -'a' + 'A');
    else
      printf("%c", input[ii]);
  }
  printf("\n");
}

