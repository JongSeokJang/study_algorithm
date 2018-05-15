#include<stdio.h>
#include<string.h>

#define ALPABET_SIZE 26

int main(void){

  int ii;
  int index;
  int alpabet_cnt[ALPABET_SIZE];
  char input[100];

  memset( alpabet_cnt, -1, sizeof(alpabet_cnt) );
  
  scanf("%s", input);
  for( ii = 0; ii < strlen(input); ii++){
    index = (int)(input[ii]-'a');

    if( alpabet_cnt[index] == -1 )
      alpabet_cnt[index] = ii;
  }

  for( ii = 0; ii < ALPABET_SIZE; ii++){
    printf("%d ", alpabet_cnt[ii]);
  }
  printf("\n");

  return 0;
  
}
