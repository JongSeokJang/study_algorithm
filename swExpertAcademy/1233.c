#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 200

typedef struct _node{
  struct _node *left;
  struct _node *right;
  char data;
  int num;
}node;

char nodeData[MAX_SIZE];
int eFlag = 0;

void makeTree(node **cNode, int index, int nodeCount){

  if( index  <= nodeCount ){

    *cNode = (node*)malloc(sizeof(node));
    (*cNode)->left = NULL;
    (*cNode)->right = NULL;
    (*cNode)->data = nodeData[index];

    makeTree( &((*cNode)->left), index*2, nodeCount);
    makeTree( &((*cNode)->right), index*2+1, nodeCount);

  }

}

void inOrder(node *cNode){

  if( cNode == NULL)
    return;

  inOrder(cNode->left);
  printf("[%c]\n", cNode->data);
  inOrder(cNode->right);

}

void calculateTree(node *cNode){

  if( eFlag )
    return;

  if( cNode->left == NULL || cNode->right == NULL)
    return;

  calculateTree(cNode->left);
  calculateTree(cNode->right);


  if( !( cNode->left->data >= '0' && cNode->left->data <='9') ){
    eFlag = 1;
    return;
  }
 
  if( !(cNode->data == '+' || cNode->data == '-' || cNode->data == '*' || cNode->data=='/')){
    eFlag = 1;
    return;
  }
  if( !(cNode->right->data >= '0' && cNode->right->data <='9') ){
    eFlag = 1;
    return;
  }

  cNode->data = '1';
  

}


int main(void){
  int ii, jj;
  int nodeCount;
  int TC = 10;
  char input[20];
  char *param1, *param2;

  node *root;

  for( ii = 1; ii <= TC; ii++){
    scanf("%d", &nodeCount);
    getchar();
    for( jj = 0; jj < nodeCount; jj++){

      eFlag = 0;
      memset(input, 0x00, sizeof(input));
      fgets(input, sizeof(input), stdin);

      param1 = strtok(input, " \n");
      param2 = strtok(NULL, " \n");

      if( param1 != NULL && param2 != NULL)
        nodeData[atoi(param1)] = param2[0];

    }

    makeTree(&root, 1, nodeCount);
    calculateTree(root);
    if( eFlag == 1 )
      printf("#%d %d", ii, 0);
    else
      printf("#%d %d", ii, 1);

  }

}
