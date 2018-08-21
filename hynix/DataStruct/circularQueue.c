#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define QUEUE_SIZE 10

int front = 0;
int rear = 0;
int queue[QUEUE_SIZE];

void enQueue(int data){

  if( front == (rear + 1)%QUEUE_SIZE ){
    printf("QUEUE is full\n");
  }
  else{
    rear = (rear+1) %QUEUE_SIZE;
    queue[rear] = data;
  }
}

void deQueue(void){
  if( front == rear ){
    printf("Queue is Empty\n");
  }
  else{
    front = (front + 1) %QUEUE_SIZE;
    printf("deQueue : [%d]\n", queue[front]);
    queue[front] = 0;
  }
}

void printQueue(void){

  int ii;
  for( ii = 0; ii < QUEUE_SIZE; ii++){
    printf("[%2d] [%2d]", ii, queue[ii]);
    if( ii == front )
      printf(" <-- front");
    if( ii == rear )
      printf(" <-- rear");
    
    printf("\n");
  }
}

int main(void){

  char input[20];
  char *param1, *param2;
  while(1){
    fgets(input, sizeof(input), stdin);
    param1 = strtok(input, " \n");
    param2 = strtok(NULL, " \n");

    if( !strcmp(param1, "exit")){
      break;
    }
    else if( !strcmp(param1, "enqueue")){
      enQueue(atoi(param2));
    }
    else if( !strcmp(param1, "dequeue")){
      deQueue();
    }
    else if( !strcmp(param1, "print")){
      printQueue();
    }
    else{
      printf("Input is wrong\n");
    }
    printQueue();
  }
}
