#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HEAP_SIZE 200

int heap[HEAP_SIZE];
int cCount = 0;

void addHeap(int data){

  int temp;
  int index = ++cCount;
  int parent = index / 2;
  heap[index] = data;
  while(parent){
    if( heap[parent] < heap[index]){
      temp = heap[parent];
      heap[parent] = heap[index];
      heap[index] = temp;

      index = parent;
      parent = index / 2;
    }
    else{
      break;
    }
  }
}

void extract(){

  int ii;
  int temp;
  int parent = 1;
  int bigger_child;
  int l_child, r_child;

  if( cCount == 0 ){
    printf("Heap is Empty\n");
  }
  else{
    printf("max : [%d]\n", heap[parent]);
    heap[1] = heap[cCount--];

    while(parent <= cCount / 2){
      l_child = 2 * parent;
      r_child = 2 * parent+1;

      if( heap[l_child] > heap[r_child]){ // l > r
        if( heap[parent] < heap[l_child]){
          temp = heap[parent];
          heap[parent] = heap[l_child];
          heap[l_child] = temp;
          parent = l_child;
        }
        else{
          break;
        }
      }
      else{ // l < r
        if( heap[parent] < heap[r_child]){
          temp = heap[parent];
          heap[parent] = heap[r_child];
          heap[r_child] = temp;
          parent = r_child;
        }
        else{
          break;
        }
      }
    }
  }

}

void printHeap(){
  int ii, jj, kk;

  for( ii = 1, jj = 1, kk = 1; ii <= cCount; ii++, jj++){
    printf("\t[%d]",heap[ii]);
    if( jj == kk ){
      printf("\n");
      jj = 0;
      kk *= 2;
    }
  }
  printf("\n");
}


int main(void){
  char input[10];
  char *param1, *param2;
  
  while(1){
    fgets(input, sizeof(input), stdin);
    param1 = strtok(input, " \n");
    param2 = strtok(NULL, " \n");

    if( !strcmp(param1, "exit")){
      break;
    }
    else if( !strcmp(param1, "add")){
      addHeap(atoi(param2));
    }
    else if( !strcmp(param1, "extract")){
      extract();
    }
    else if( !strcmp(param1, "show")){
      printHeap();
    }
    else{
      printf("Input is wrong\n");
    }
    printHeap();

  }

}
