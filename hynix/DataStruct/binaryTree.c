#include<stdio.h>

int data[10] = {1,2,3,4,5,6,7,8,9,0};

typedef struct _node{
  int data;
  struct _node *l;
  struct _node *r;
}node;

void insert(node **parent, int nodeCount, int index){

  node *newNode;
  if( index < = nodeCount){

    newNode = (node*)malloc(sizeof(node));
    newNode->data = data[index];
    newNode->l = NULL;
    newNode->r = NULL;

    *parent = newNode;
    insert(:
        )

  }
  else{

  }

}



int main(void){
  node *root = NULL;
  int ii;

  for( ii = 0; ii < 10; ii++){
    insert(&root, data[ii]);
  }




}
