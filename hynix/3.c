#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct _node{
  int data;
  struct _node *next;
}node;

node *HEAD, *TAIL;

void deQueue(){
  if( HEAD == NULL){
    printf("there are not element\n");
  }
  else if( HEAD == TAIL){
    printf("[%d]\n", HEAD->data);
    HEAD = TAIL = NULL;
  }
  else{
    printf("[%d]\n", HEAD->data);
    HEAD = HEAD->next;
  }
}

void enQueue(int num){
  printf("In enqueue\n");

  node *temp;
  temp = (node*)malloc(sizeof(node));
  temp->data = num;
  temp->next = NULL;

  if (HEAD == NULL){
    HEAD = temp;
    TAIL = HEAD;
  }
  else{
    TAIL->next = temp;
    TAIL = temp;
  }

}

void sortQueue(){

  printf("In sortQueue\n");
  node *temp1, *temp2;
  int temp_data;

  for( temp1 = HEAD; temp1->next != NULL; temp1 = temp1->next){
    for( temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next){
      if( temp1->data >= temp2->data){
        temp_data = temp1->data;
        temp1->data = temp2->data;
        temp2->data = temp_data;
      }
    }
  }

}

void queuePrint(void){
  node *temp;
  for( temp = HEAD; temp != TAIL; temp = temp->next)
    printf("[%d]->", temp->data);

  if( temp != NULL)
    printf("[%d]\n", temp->data);
  

}

int main(void){

  char *param1, *param2; char cmd[100];
  HEAD = TAIL = NULL;

  while(1){
    fgets(cmd, sizeof(cmd), stdin);

    param1 = strtok(cmd, " \n");
    param2 = strtok(NULL, "\n\0");

    if( strcmp(cmd, "exit") == 0)
      break;
    else if( strcmp( cmd, "enqueue") == 0){
      enQueue(atoi(param2));
    }
    else if( strcmp( cmd, "dequeue") == 0){
      deQueue();
    }
    else if( strcmp( cmd, "sort") == 0){
      sortQueue();
    }
    else{
      printf(" insert normal cmd\n");
    }
    queuePrint();
  }

}

