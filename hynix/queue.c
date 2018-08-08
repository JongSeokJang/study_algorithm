#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
  int data;
  struct _node *next;
}node;

node *head, *tail;

void enQueue(int number){

  node *newNode;
  newNode = (node*)malloc(sizeof(node));
  newNode->data = number;
  newNode->next = NULL;

  if( head == NULL )
    head = newNode;
  else
    tail->next = newNode;
  tail = newNode;

}
int deQueue(){

  int remember;
  if( head == NULL){
    return -1;
  }
  else{
    remember = head->data;
    head = head->next;
    return remember;
  }
}
void showQueue(){

  node *ptrNode;
  for( ptrNode = head; ptrNode->next; ptrNode = ptrNode->next)
    printf("[%d]->", ptrNode->data);

  if( ptrNode != NULL )
    printf("[%d]\n", ptrNode->data);
  
}

int main(void){

  head = tail = NULL;

  int data;
  char cmd[32];
  char *param1, *param2;
  while(1){
    fgets(cmd, 32, stdin);

    param1 = strtok(cmd, " \n");
    param2 = strtok(NULL, " \n");

    if( !strcmp(param1, "exit")){
      break;
    }
    else if( !strcmp(param1, "enqueue")){
      enQueue(atoi(param2));
    }
    else if( !strcmp(param1, "dequeue")){
    
      data = deQueue();

      if( data == -1 )
        printf("This Queue is empty\n");
      else
        printf("dequeue : [%d]\n", data);
    }
    else if( !strcmp(param1, "show")){
      showQueue();
    }
    else{
      printf("[%s] is abnormal command\n", param1);
    }
  }


}
