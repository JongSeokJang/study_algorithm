#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_SIZE 1000

void stack2stack(int *from, int*to, int top){
  int ii;
  int stack_top = 0;
  for( ii = top; ii >= 0; ii--){
    to[stack_top++] = from[ii];
  }
}

int main(void){

  int ii;
  int TC;
  int stack1[STACK_SIZE] = {0};
  int stack2[STACK_SIZE] = {0};
  int top = 0;

  char  cmd[8];
  int   cmd_param = -1;
  int   top_value = -1;

  scanf("%d", &TC);

  while(TC--){

    memset(cmd, 0x00, sizeof(cmd));

    scanf("%s", cmd);

    if( strcmp(cmd, "ENQUEUE") == 0){
      stack2stack(stack2, stack1, top);
      scanf("%d", &cmd_param);
      stack1[top++] = cmd_param;
      stack2stack(stack1, stack2, top);

    }
    else if( strcmp(cmd, "DEQUEUE") == 0){
      stack2stack(stack1, stack2, top);
      top_value = stack2[top--];
      printf("%d\n", top_value);
      stack2stack(stack2, stack1, top);
    }
    else{

    }
  }

}

