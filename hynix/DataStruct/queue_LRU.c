#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define QUEUE_SIZE 10

typedef struct _node{
  int data;
  int priority;
}node;

node queue[QUEUE_SIZE];
int front = 0, rear = -1;

void enQueue(int data, int priority){

  int ii;
  int remember;
  node temp;
  if( rear == QUEUE_SIZE - 1 ){
    printf("Queue is Full\n");
  }
  else{
    rear = rear + 1;
    queue[rear].data = data;
    queue[rear].priority = priority;

    remember = rear;
    for( ii = rear; ii >= front; ii--){
      if( queue[remember].priority > queue[ii].priority){
        temp.data = queue[ii].data;
        temp.priority = queue[ii].priority;

        queue[ii].data = queue[remember].data;
        queue[ii].priority = queue[remember].priority;

        queue[remember].data = temp.data;
        queue[remember].priority = temp.priority;
        remember = ii;
      }
    }
  }
}
void deQueue(void){
  int ii;
  if( rear == -1 ){
    printf("Queue is Empty\n");
  }
  else{
    printf("data : [%d] priority : [%d]\n", queue[front].data, queue[front].priority);
    for( ii = front; ii < rear; ii++){
      queue[ii].data = queue[ii+1].data;
      queue[ii].priority = queue[ii+1].priority;
    }
    rear--;
  }
}
void show(void){
  int ii;
  for( ii = front; ii <= rear; ii++){
    printf("data : [%d] priority : p[%d]\n", queue[ii].data, queue[ii].priority);
  }
}

int main(void){
  char input[20];
  char *param1, *param2, *param3;

  while(1){
    fgets(input, sizeof(input), stdin);
    param1 = strtok(input, " \n");
    param2 = strtok(NULL, " \n");
    param3 = strtok(NULL, " \n");

    if( !strcmp(param1, "exit") ){

    }
    else if( !strcmp(param1, "enqueue") ){
      enQueue(atoi(param2), atoi(param3));
    }
    else if( !strcmp(param1, "dequeue") ){
      deQueue();
    }
    else if( !strcmp(param1, "show")){
      show();
    }
    else{
      printf("Input is wrong :[%s][%s]\n", param1, param2);
    }
  }
}

