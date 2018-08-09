#include<stdio.h>
#include<string.h>

void quick(int *arr, int start, int end){

  int ii;
  if( start >= end )
    return;
  
  int pivot = arr[end];
  int l = start;
  int r = end-1;
  int temp;

  while(1){

    while( arr[l] < pivot) l++;
    while( arr[r] > pivot) r--;

    if( l > r) break;

    temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;

  }

  temp = arr[l];
  arr[l] = arr[end];
  arr[end] = temp;

  quick(arr, start, l-1);
  quick(arr, r+1, end);

}

int data[10] = {5,1,9,2,8,3,7,6,4,0};

int main(void){

  int ii;
  for( ii = 0; ii <10; ii ++)
    printf("[%d]", data[ii]);
  printf("\n");
  
  quick(data, 0, 9);
  for( ii = 0; ii <10; ii ++)
    printf("[%d]", data[ii]);
  printf("\n");

}
