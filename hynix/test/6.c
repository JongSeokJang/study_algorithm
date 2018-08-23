#include<stdio.h>

#define STACK_SIZE  100
#define MAX_SIZE    25

typedef struct _{
  int stackTop;
  int data[STACK_SIZE];
}stackStruct;

int isempty(stackStruct *stack){
  // Todo Implement
  
  if( stack->stackTop < 0)
    return 1;
  else
    return 0;
}

int stackTop(stackStruct *stack){
  // Todo Implement

  if( stack->stackTop < 0)
    return -1;
  else
    return stack->data[stack->stackTop];

}

void stackPush(stackStruct *stack, int value){
  // Todo Implement
  
  stack->data[++(stack->stackTop)]  = value;

}
int stackPop(stackStruct *stack){
  // Todo Implement

  if( stack->stackTop < 0)
    return -1;
  else
    return stack->data[(stack->stackTop)--];
}
  
void printField(int (*field)[MAX_SIZE],int max_height,int n){
  int ii, jj;

  for( ii = 0; ii < max_height; ii++){
    for( jj = 0; jj < n; jj++)
      printf("[%d]", field[ii][jj]);
    printf("\n");
  }
  printf("\n");
}

// Using Stack, Find Max quadrangle's area
int maxArea(int *hist, int n){
  // Todo Implement
  
  int max;
  int sum;
  int ii, jj, kk;
  int height, max_height = 0;
  int field[MAX_SIZE][MAX_SIZE] = {0};
  int field_area[MAX_SIZE][MAX_SIZE] = {0};


  // make field
  for( jj = 0; jj < n; jj++){
    height = hist[jj];
    for( ii = 0; ii < height; ii++)
      field[ii][jj] = 1;

    if( height > max_height)
      max_height = height;
  }

  // calculate field_area
  max = 0;
  for(ii = 0 ; ii < max_height; ii++){
    for( jj = 0; jj < n; jj++){
      sum = 0;
      for( kk = jj; kk < n ; kk++){

        if( field[ii][kk] == 0 ){ 
          field_area[ii][jj] = (ii + 1) * sum;
          break;
        }
        sum++;
      }

      if( kk == n )
        field_area[ii][jj] = (ii + 1) * sum;
      

      if( max < field_area[ii][jj])
        max = field_area[ii][jj];
    }
  } 

  printField(field, max_height, n);
  printField(field_area, max_height, n);

  return max;
}


int main(void){

  int hist1[6] = {2,1,6,5,3,2};
  printf("max : [%d]\n", maxArea(hist1, 6));


}

