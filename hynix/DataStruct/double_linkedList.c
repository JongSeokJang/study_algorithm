#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _node{
  int data;
  struct _node *prev;
  struct _node *next;
}node;

void insert(node **head, node **tail, int data){

  node *newNode;
  newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->prev = *tail;
  newNode->next = NULL;


  if( (*head) == NULL){
    *head = newNode;
  }
  else{
    (*tail)->next = newNode;
  }
  *tail = newNode;
}

void delete(node **head, node **tail, int data){

  node *ptrNode;
  if( *head == NULL ){
    printf("There are not exist data\n");
  }
  else{
    for( ptrNode = *head; ptrNode; ptrNode = ptrNode->next){
      if( ptrNode->data == data){
        if( ptrNode == *head ){
          *head = ptrNode->next;
          ptrNode->next->prev = NULL;
        }
        else if ( ptrNode == *tail){
          *tail = ptrNode->prev;
          ptrNode->prev->next = NULL;
        }
        else{
          ptrNode->prev->next = ptrNode->next;
          ptrNode->next->prev = ptrNode->prev;
        }
        free(ptrNode);
        break;
      }
    }
  }
}

void printNode(node **head, node **tail){
  node *ptrNode;
  printf("print [->]\n");
  for( ptrNode = *head; ptrNode->next; ptrNode = ptrNode->next)
    printf("[%d]->", ptrNode->data);
  printf("[%d]\n", ptrNode->data);

  printf("print [<-]\n");
  for( ptrNode = *tail; ptrNode->prev; ptrNode = ptrNode->prev)
    printf("[%d]->", ptrNode->data);
  printf("[%d]\n", ptrNode->data);

}

int main(void){

  node *head = NULL;
  node *tail = NULL;

  char input[30];
  char *param1, *param2;


  while(1){
    fgets(input, sizeof(input), stdin);
    param1 = strtok(input, " \n");
    param2 = strtok(NULL, " \n");


    if( !strcmp(param1,"exit") ){
      break;
    }
    else if( !strcmp(param1, "insert")){
      insert(&head, &tail, atoi(param2));
    }
    else if( !strcmp(param1, "delete")){
      delete(&head, &tail, atoi(param2));
    }
    else if( !strcmp(param1, "print")){
      printNode(&head, &tail);
    }
    printNode(&head, &tail);


  }




}
