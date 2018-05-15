#include<stdio.h>
#include<string.h>

#define MAX_SIZE 1000000

int main(void){
  int flag = 0;
  int ii;
  int cnt = 0;
  char sentence[MAX_SIZE];


  fgets(sentence,MAX_SIZE, stdin );
  trim(sentence);

  for( ii = 0; ii < strlen(sentence); ii++){
    flag = 1;
    if( sentence[ii] == ' ')
      cnt++;
  }

  if(cnt == 0){
    if( flag == 1){
      printf("1\n");
    }
    else{
      printf("0\n");
    }
  }
  else{
    printf("%d\n", cnt+1);
  }

  return 0;

}
