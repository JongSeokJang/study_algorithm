#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char nodeData[100+1];

typedef struct _node{
  char node;
  struct _node *l;
  struct _node *r;
}node;

void makeNode(node **root, int nodeCount, int index){

  node *newNode;

  if( index  <= nodeCount){

    newNode = (node*)malloc(sizeof(node));
    newNode->node = nodeData[index];
    newNode->l = NULL;
    newNode->r = NULL;

    *root = newNode;

    makeNode( &((*root)->l), nodeCount, index*2); // left
    makeNode( &((*root)->r), nodeCount, index*2+1); // right

  }
}

void printTree(node *root){

  if(root == NULL){
    return;
  }

  printTree(root->l);
  printf("%c", root->node);
  printTree(root->r);

}

int main(void){

  node *root = NULL;
  int nodeCount;
  int TC = 10;
  int ii, jj;
  char input[20];
  char *param1, *param2, *param3, *param4;
  for( ii = 1; ii <= TC; ii++){

    scanf("%d", &nodeCount);
    getchar();
    for( jj = 0; jj < nodeCount; jj++){
      memset(input, 0x00, sizeof(input));
      fgets(input, 20, stdin);

      param1 = strtok(input, " \n");
      param2 = strtok(NULL, " \n");
      param3 = strtok(NULL, " \n");
      param4 = strtok(NULL, " \n");

      nodeData[atoi(param1)] = param2[0];
    }

    makeNode(&root, nodeCount, 1);
    printf("#%d ", ii);
    printTree(root);
    printf("\n");

  }
}
