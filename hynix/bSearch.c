#include<stdio.h>
#define ARR_SIZE 10
int data[ARR_SIZE] = {13, 24, 35, 39, 51, 53, 60, 61, 64, 70};

void binarySearch(int start, int end, int element){

  int median = (start + end)/2;
  if( data[median] == element ){
    printf("index : [%d] element :[%d]\n", median, data[median]);
    return;
  }
  if( start == end ){
    printf(" [%d] is not exist\n", element);
    return;
  }

  if( data[median] > element) // Exist Left
    binarySearch(start, median-1, element);
  else
    binarySearch(median+1,end, element);

}


int main(void){
  int ii;
  int element;
  printf("Select One ");
  for (ii = 0; ii < ARR_SIZE; ii++)
    printf("[%d] ", data[ii]);
  printf("\n element : ");
  scanf("%d", &element);

  binarySearch(0, ARR_SIZE, element);





}
