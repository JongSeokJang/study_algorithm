#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 200

typedef struct _node{
  struct _node *left;
  struct _node *right;
  char data;
  double num;
}node;

char nodeData[MAX_SIZE];
double   nodeNum[MAX_SIZE];
int eFlag = 0;

void makeTree(node **cNode, int index, int nodeCount){

  if( index  <= nodeCount ){

    *cNode = (node*)malloc(sizeof(node));
    (*cNode)->left = NULL;
    (*cNode)->right = NULL;
    if( nodeData[index] == '0' )
      (*cNode)->num = nodeNum[index];
    else
      (*cNode)->data = nodeData[index];

    makeTree( &((*cNode)->left), index*2, nodeCount);
    makeTree( &((*cNode)->right), index*2+1, nodeCount);

  }

}

void inOrder(node *cNode){

  if( cNode == NULL)
    return;

  inOrder(cNode->left);
  printf("[%c][%lf]\n", cNode->data, cNode->num);
  inOrder(cNode->right);

}

void calculateTree(node *cNode){

  if( eFlag )
    return;

  if( cNode->left == NULL || cNode->right == NULL)
    return;

  calculateTree(cNode->left);
  calculateTree(cNode->right);


  if( !(cNode->data == '+' || cNode->data == '-' || cNode->data == '*' || cNode->data=='/')){
    eFlag = 1;
    return;
  }

  if( cNode->data == '+')
    cNode->num = cNode->left->num + cNode->right->num;
  else if(cNode->data == '-')
    cNode->num = cNode->left->num - cNode->right->num;
  else if(cNode->data == '*')
    cNode->num = cNode->left->num * cNode->right->num;
  else if(cNode->data == '/')
    cNode->num = cNode->left->num / cNode->right->num;

}


int main(void){
  int ii, jj;
  int nodeCount;
  int TC = 10;
  char input[20];
  char *param1, *param2;

  node *root;

  for( ii = 1; ii <= TC; ii++){

    memset(nodeData, '0', sizeof(nodeData));
    memset(nodeNum, 0x00, sizeof(nodeNum));

    scanf("%d", &nodeCount);
    getchar();
    for( jj = 0; jj < nodeCount; jj++){

      eFlag = 0;
      memset(input, 0x00, sizeof(input));
      fgets(input, sizeof(input), stdin);

      param1 = strtok(input, " \n");
      param2 = strtok(NULL, " \n");

      if( param1 != NULL && param2 != NULL){
        if( param2[0] == '+' || param2[0] == '-' || param2[0] == '*' || param2[0] =='/')
          nodeData[atoi(param1)] = param2[0];
        else {
          nodeNum[atoi(param1)] = atoi(param2);
        }
      }

    }

    makeTree(&root, 1, nodeCount);

    printf("----BEFORE-----\n");
    inOrder(root);
    calculateTree(root);

    printf("----AFTER-----\n");
    inOrder(root);
    printf("#%d %.lf\n", ii, root->num);

  }

}
