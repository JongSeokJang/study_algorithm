#include<stdio.h>
#include<string.h>


int sortedArr[100];
void merge_sort(int *arr, int start, int end){
  int ii, jj, kk;
  int sortedArr[100];
  int median = (start + end)/2;

  memset(sortedArr, 0x00, sizeof(sortedArr));

  jj = start;     // left
  kk = median+1;  // right
  for( ii = start; ii <=end; ii++){

    if( jj == median+1){
      sortedArr[ii] = arr[kk++];
      continue;
    }
    
    if( kk == end+1){
      sortedArr[ii] = arr[jj++];
      continue;
    }

    if( arr[jj] > arr[kk])
      sortedArr[ii] = arr[kk++];
    else
      sortedArr[ii] = arr[jj++];
  }

  for( ii = start; ii <= end; ii++)
    arr[ii] = sortedArr[ii];
  

}

void merge(int *arr, int start, int end){

  if( start >= end ) return;

  int median = (start + end)/2;

  merge(arr, start, median);
  merge(arr, median+1, end);
  merge_sort(arr, start, end);

}


int data[10] = {5,1,9,2,8,3,7,6,4,0};

int main(void){

  int ii;
  for( ii = 0; ii <10; ii ++)
    printf("[%d]", data[ii]);
  printf("\n");
  
  merge(data, 0, 9);
  for( ii = 0; ii <10; ii ++)
    printf("[%d]", data[ii]);
  printf("\n");

}
