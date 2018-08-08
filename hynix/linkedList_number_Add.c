#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _node{
  int num;
  struct _node *link;
}node;

void makeLinked(node **head, node **tail, int num){
  printf("make Linked\n");
  *head = *tail = NULL;
  node *temp;
  char num_str[64];
  int ii;

  sprintf(num_str, "%d", num);
  for( ii = 0; ii < strlen(num_str); ii++){


    temp = (node*)malloc(sizeof(node));
    temp->num = num_str[ii]-'0';
    temp->link = NULL;
    printf("[%d]\n", temp->num);

    if( *head == NULL ){
      *head = temp;
      *tail = temp;
    }
    else{
      (*tail)->link = temp;
      *tail = temp;
    }
  }
}
void showLinked(node *head){
  printf("show Linked\n");
  node *temp;
  for( temp = head; temp->link; temp = temp->link)
    printf("[%d]->",temp->num);
  printf("[%d]\n", temp->num);
}

int addLinked(node *h1, node *h2){
  int digit = 1;
  int carry = 0;
  int n1, n2;
  int sum = 0;
  node *t1 = h1, *t2 = h2;

  while( t1 != NULL || t2 != NULL){
    for(t1 = h1; t1->link; t1 = t1 -> link);
    for(t2 = h2; t2->link; t2 = t2 -> link);

    if( t1 == NULL )
      n1 = 0;
    else{
      n1 = t1 ->num;
      t1->link = NULL;
      if( t1 == h1)
        t1 = NULL;
    }

    if( t2 == NULL )
      n2 = 0;
    else{
      n2 = t2 ->num;
      t2->link = NULL;
      if( t2 == h2)
        t2 = NULL;
    }

    if( n1+n2+ carry > 9){
      sum = sum + digit*(n1+n2+carry-10);
      carry = 1;
    }
    else{
      sum = sum + digit*(n1+n2+carry);
      carry = 0;
    }
    digit *= 10;
    printf("[%d]\n", sum);

  }
  return sum;

}

int main(void){
  int TC;
  int num1, num2;

  node *h1, *h2;
  node *t1, *t2;
  node *temp;

  scanf("%d", &TC);
  while(TC--){
    scanf("%d %d", &num1, &num2);

    makeLinked(&h1, &t1, num1);
    showLinked(h1);

    makeLinked(&h2, &t2, num2);
    showLinked(h2);

    printf("[%d]\n",addLinked(h1, h2) );
  }



}
