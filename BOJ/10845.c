#include<stdio.h>
#include<string.h>

int main(void){

  int ii;
  int T;

  char input[10];
  int param;

  int queue[10000];
  int front, end;

  front = 0;
  end = -1;

  scanf("%d", &T);

  while( T--){

    memset(input, 0x00, 10);
    scanf("%s", input);


    if( strcmp(input, "push") == 0){

      scanf("%d", &param);
      queue[++end] = param;
    }
    else if( strcmp(input, "pop") == 0){

      if( end < front)
        printf("-1\n");
      else
        printf("%d\n", queue[front++]);
    }
    else if( strcmp(input, "size") == 0){
      printf("%d\n", end - front + 1);
    }
    else if( strcmp(input, "empty") == 0){

      if( end < front)
        printf("1\n");
      else
        printf("0\n");
    }
    else if( strcmp(input, "front") == 0){
      
      if( end < front )
        printf("-1\n");
      else 
        printf("%d\n", queue[front]);
      
    }
    else if( strcmp(input, "back") == 0){

      if( end < front )
        printf("-1\n");
      else 
        printf("%d\n", queue[end]);

    }
  }

}
