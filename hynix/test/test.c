#include<stdio.h>
#include<string.h>

int main(void){

  char input[10];
  int length;
  int ii;
  scanf("%s", input);
  
  length = strlen(input);

  for( ii = 0; ii < (length)/2; ii++)
    printf("[%c][%c]\n", input[ii], input[length-1-ii]);
  





}
