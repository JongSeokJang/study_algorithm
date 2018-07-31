#include<stdio.h>
#include<string.h>

int main(void){
  char input[200+1];
  int ii;

  scanf("%s", input);
  for( ii = 0; ii < strlen(input); ii++ ){
    printf("%d ", input[ii]-'A'+1);
  }
  printf("\n");
}
