#include<stdio.h>
#include<string.h>

int main(void){

  char cmd[10];
  int param;
  int TC;
  int top = -1;
  int stack[100000];


  scanf("%d", &TC);
  
  while(TC--){
    scanf("%s", cmd);
    
    if( strcmp(cmd, "push") == 0){
      scanf("%d", &param); 

      top++;
      stack[top] = param;

    }
    else if( strcmp(cmd, "pop") == 0){
      if( top == -1)
        printf("-1\n");
      else
        printf("%d\n", stack[top--]);

    }
    else if( strcmp(cmd, "size") == 0){
      printf("%d\n", top+1);
    }
    else if( strcmp(cmd, "empty") == 0){
      
      if( top == -1){
        printf("1\n");
      }
      else{
        printf("0\n");
      }

    }
    else if( strcmp(cmd, "top") == 0){
      if(top == -1)
        printf("-1\n");
      else{
        printf("%d\n", stack[top]);
      }

    }

  }

}

