#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define QSIZE 4

int start = 0, end = 0;
int cQueue[QSIZE];

void enQueue(int num){
  end = (end+1) % QSIZE;
  printf("enQueue %d : %d\n", end, num);
  if( start == end ){
    printf("[This Queue is Full]\n");
  }
  else{
    cQueue[end] = num;
  }
}
int deQueue(){

  start = (start+1) % QSIZE;
  int dequeue_value = cQueue[start];
  return dequeue_value;
}
void showQueue(){
  int ii;
  printf("start : [%d] end : [%d]\n", start, end);
  if( start > end ){
    for( ii = start+1; ii <= end+QSIZE; ii++){
      if( ii >= QSIZE)
        printf("[%d]", cQueue[ii-QSIZE]);
      else
        printf("[%d]", cQueue[ii]);
    }
    printf("\n");
  }
  else{
    for( ii = start+1; ii <= end; ii++)
      printf("[%d]", cQueue[ii]);
    printf("\n");
  }
}


int main(void){

  char cmd[100];
  char *param1, *param2;

  while(1){
    memset(cmd, 0x00, sizeof(cmd));
    fgets(cmd, sizeof(cmd), stdin);

    param1 = strtok(cmd, " \n\0");
    param2 = strtok(NULL, "\n\0");

    printf("[%s][%s]\n", param1, param2);

    if( strcmp(param1, "exit") == 0){
      break;
    }
    else if( strcmp(param1, "enqueue") == 0){
      enQueue(atoi(param2));
    }
    else if( strcmp(param1, "dequeue") == 0){
      printf("[%d]\n", deQueue());
    }
    else if( strcmp(param1, "show") == 0){
      showQueue();
    }
    else{
      printf("insert abnormal cmd\n");
    }
    showQueue();



  }

}
