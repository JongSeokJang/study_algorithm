#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
  int data;
  struct _node *next;
}node;

node *head, *tail;

void pushStack(int num){

  node *newNode;
  node *ptrNode;
  
  newNode = (node*)malloc(sizeof(node));
  newNode->data = num;
  newNode->next = NULL;

  if( head == NULL )
    head = newNode;
  else
    tail->next = newNode;
  tail = newNode;


}

int popStack(){

  int popData;
  node *ptrNode;

  if( head == NULL ){
    return -1;
  }
  else if( head == tail){
    popData = head->data;
    head = tail = NULL;
  }
  else if( head->next == tail){
    popData = tail->data;
    head->next = NULL;
    tail = head;
  }
  else{
    for(ptrNode = head; ptrNode->next->next; ptrNode = ptrNode->next);
    popData = ptrNode->next->data;
    ptrNode->next = NULL;
    tail = ptrNode;
  }
  return popData;

}
void showStack(){

  int ii,jj;
  int queue[100];
  node *ptrNode;

  printf("----Top----\n");
  for(ii= 0, ptrNode = head; ptrNode; ptrNode = ptrNode->next, ii++)
    queue[ii] = ptrNode->data;
  for(jj = ii-1, ptrNode = head; ptrNode; ptrNode = ptrNode->next, jj--)
    printf("[%d]\n", queue[jj]);
  printf("---Bottom--\n");

}

int main(void){

  head = tail = NULL;
  char cmd[32];
  char *param1, *param2;
  int popData;

  while(1){
    fgets(cmd, sizeof(cmd), stdin);
    param1 = strtok(cmd, " \n");
    param2 = strtok(NULL, "\n");


    if ( !strcmp(param1, "exit"))
      break;
    else if ( !strcmp(param1, "push") )
      pushStack(atoi(param2));
    else if ( !strcmp(param1, "pop") ){
      popData = popStack();
      if( popData == -1 )
        printf("This Stack is empty\n");
      else
        printf("Pop : [%d]\n", popData);
    }
    else if ( !strcmp(param1, "show") )
      showStack();
    else 
      printf("[%s] is abnormal command\n", param1);

  }

}
