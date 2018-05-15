#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100

int solve(char *input){

  int ii;
  int total, temp;
  int str_len = strlen(input);

  total = temp = 0;

  for( ii = 0; ii < str_len; ii++){
    
    if( input[ii] == 'X' ){
      temp = 0;
    }
    else{
      temp++;
      total += temp;
    }
  }
  return total;
}


int main(void){

  int TC;
  int result;
  char input[MAX_SIZE];

  scanf("%d", &TC);

  while(TC--){

    result = 0;
    memset(input, 0x00, MAX_SIZE);

    scanf("%s", input);

    result = solve(input);
    printf("%d\n", result);

  }

}

