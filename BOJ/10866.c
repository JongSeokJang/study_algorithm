#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char insert_cmd[32];
int dequeue[1024];
int front = 0;
int back = -1;

void process(char *cmd, int option){
  int ii;
  int temp;

  if( strcmp("push_front",cmd) == 0 ){
    back++;
    for( ii = back; ii > front; ii--)
      dequeue[ii] = dequeue[ii-1]; 
    dequeue[ii] = option;
  }
  else if( strcmp("push_back", cmd) == 0){
    dequeue[++back] = option;
  }
  else if( strcmp("pop_front", cmd) == 0){

    if( back == -1)
      printf("-1\n");
    else {
      printf("%d\n", dequeue[front]);
    
      for( ii = front; ii < back; ii++)
        dequeue[ii] = dequeue[ii+1]; 
      back--;
    }

  }
  else if( strcmp("pop_back", cmd) == 0 ){
    if ( back == -1 )
      printf("-1\n");
    else
      printf("%d\n", dequeue[back--]);
  }
  else if( strcmp("size", cmd) == 0){
    printf("%d\n", back+1);

  }
  else if( strcmp("empty", cmd) == 0){
    if ( back == -1 )
      printf("1\n");
    else
      printf("0\n");

  }
  else if( strcmp("front", cmd) == 0){
    if ( back == -1 )
      printf("-1\n");
    else
      printf("%d\n", dequeue[front]);
  }
  else if( strcmp("back", cmd) == 0){
    if ( back == -1 )
      printf("-1\n");
    else
      printf("%d\n", dequeue[back]);
  }
  else{

  }

}

int main(void){

  int TC;
  char *ptr;
  char cmd[32];
  int option_cmd;
  scanf("%d",  &TC);
  getchar();

  while(TC--){

    memset(insert_cmd, 0x00, sizeof(insert_cmd) );
    memset(cmd, 0x00, sizeof(cmd) );
    option_cmd = 0;

    fgets(insert_cmd, sizeof(insert_cmd), stdin);

    ptr = strtok( insert_cmd, " \n");
    strcpy(cmd, ptr);
    ptr = strtok( NULL, " \n");
    if( ptr ) 
      option_cmd = atoi(ptr);

    process(cmd, option_cmd);

  }
}
