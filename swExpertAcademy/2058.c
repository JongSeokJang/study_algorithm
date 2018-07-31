#include<stdio.h>
#include<string.h>

int main(void){

  int ii;
  int total = 0;
  char input[10];

  scanf("%s", input);

  for( ii = 0; ii < strlen(input); ii ++)
    total += input[ii] -'0';
  
  printf("%d\n", total);
}
