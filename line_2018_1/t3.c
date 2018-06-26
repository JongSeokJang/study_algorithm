#include<stdio.h>

typedef struct _{
  char temp_time[100];
  char flag;
  char task[100];
  int   id;
}TIMER;

int main(void)
{
  int ii;
  int T;
  char input[100];
  TIMER timer[1000];
  
  
  scanf("%d|%s", &T,input);
  
  printf("%d\n", T);
  printf("%s\n", input);
  
  for( ii = 0; ii < T; ii++){
    scanf("%s", input);
  }

  for( ii = 0; ii < T; ii++){
    printf("%s\n", input);
  }



  
}
