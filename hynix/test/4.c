#include<stdio.h>

#define MAX_ARR 5

void sort(int *list, int *ans ){
// Todo Implement

  int min;
  int temp;
  int ii, jj;

  for( ii = 0; ii < MAX_ARR-1; ii++){
    
    min = ii;
    for( jj = ii +1; jj < MAX_ARR; jj++){
      if( list[min] > list[jj] )
        min = jj;
    }

    if( ii != min){
      temp = list[ii];
      list[ii] = list[min];
      list[min] = temp;
    }
  }

  for( ii = 0; ii < MAX_ARR; ii++){
    ans[ii] = list[ii];
  }
}


int sortCount(int *list){
// Todo Implement

  int min;
  int temp;
  int ii, jj;
  int count = 0;

  for( ii = 0; ii < MAX_ARR-1; ii++){
    
    min = ii;
    for( jj = ii +1; jj < MAX_ARR; jj++){
      if( list[min] > list[jj] )
        min = jj;
    }

    if( ii != min){
      count++;
      temp = list[ii];
      list[ii] = list[min];
      list[min] = temp;
    }
  }

  return count;

}
void printList(int *arr){
  int ii;
  for( ii = 0; ii < MAX_ARR; ii++)
    printf("[%3d] ", arr[ii]);
  printf("\n");
}

int main(void){

  int student[MAX_ARR] = {120, 100, 160, 130, 110};

  int list[MAX_ARR];
  int ans[MAX_ARR];
  int ii;
  int minCount;

  for( ii = 0; ii < MAX_ARR; ii++)
    list[ii] = student[ii];

  printList(list);

  sort(list, ans);

  printList(ans);
  

  for( ii = 0; ii < MAX_ARR; ii++)
    list[ii] = student[ii];

  minCount = sortCount(list);
  printf("[%d]\n", minCount);

}
