#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW_MAX 30
#define COL_MAX 30

void setMatrixValue(int (*matrix)[COL_MAX], int n, int m){
  int ii, jj;
  int random;
  srand(time(NULL));

  for( ii = 0; ii < n; ii++){
    for( jj = 0; jj < m; jj++){
      random = (rand() %24) + 2;
      matrix[ii][jj] = random;
    }
  }
}

void printMatrix(int (*matrix)[COL_MAX], int n, int m){
  int ii, jj;
  printf(" Matrix's ROW size : [%d]\n", n);
  printf(" Matrix's COL size : [%d]\n", m);
  for( ii = 0; ii < n; ii++){
    for( jj = 0; jj < m; jj++)
      printf("%2d ", matrix[ii][jj]);
    printf("\n");
  }
}

void getMatrixSize(int *n, int *m){
  // Todo Implement
  printf("Insert row size : 2 ~ 25 \n");

  while(1){
    scanf("%d", n);
    if(2 <= *n  && *n <= 25)
      break;
    else{
      printf("Check your input 2 <= row <= 25 \n");
    }
  }

  printf("Insert col size : 2 ~ 25 \n");
  while(1){
    scanf("%d", m);
    if(2 <= *m  && *m <= 25)
      break;
    else{
      printf("Check your input 2 <= col <= 25 \n");
    }
  }

}

void findMaxElement( int (*matrix)[COL_MAX], int n, int m){
  // Todo Implement
  int elementCount[25+1] = {0};
  int ii, jj;
  int max = 0;

  for( ii = 0; ii < n; ii++){
    for( jj = 0; jj < m ; jj++)
      elementCount[matrix[ii][jj]]++;
  }


  for( ii = 0; ii < 25+1; ii++){
    if( elementCount[ii] >= elementCount[max])
      max = ii;
  }

  if( max < 2)
    printf("None\n");
  else
    printf("[%d] is max value, count is [%d]\n", max, elementCount[max]);

}


int main(void){
  int n, m;
  int matrix[ROW_MAX][COL_MAX];
  getMatrixSize(&n, &m);

  printf("[%d][%d]\n", n,m);
  
  setMatrixValue(matrix, n, m);
  printMatrix(matrix, n, m);

  findMaxElement(matrix, n, m);


}
