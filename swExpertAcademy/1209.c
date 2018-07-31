#include<stdio.h>
#include<string.h>

#define SIZE 100

int field[100][100];
int sum[202];
int count = 0;

void calculate(){

  int ii, jj;
  int total = 0;
  count = 0;
  memset( sum, 0x00, sizeof(sum) );

  // sum of row
  for( ii = 0; ii < SIZE; ii++){
    total = 0;
    for( jj = 0; jj < SIZE; jj++)
      total += field[ii][jj];
    sum[count++] = total;
  }

  // sum of col
  for( jj = 0; jj < SIZE; jj++){
    total = 0;
    for( ii = 0; ii < SIZE; ii++)
      total += field[ii][jj];
    sum[count++] = total;
  }

  // sum of diagonal (To right down)
  total = 0;
  for( ii = 0; ii < SIZE; ii++)
    total += field[ii][ii];
  sum[count++] = total;

  // sum of diagonal (To Left down)
  total = 0;
  for( ii = 0; ii < SIZE; ii++)
    total += field[ii][SIZE-ii];
  sum[count] = total;

}
int findMax(){
  int max;
  int ii;

  max = 0;
  for( ii = 0; ii < count; ii++){
    if( sum[max] <= sum[ii])
      max = ii;
  }
  return sum[max];
}


int main(void){
  int ii,jj,kk;
  int case_num;
  int max_sum;

  for( ii = 0; ii < 10; ii++){
    memset( field, 0x00, sizeof(field) );
    scanf("%d", &case_num);
    
    for( jj = 0; jj < SIZE; jj++){
      for( kk = 0; kk < SIZE; kk++)
        scanf("%d",&field[jj][kk]);
    }
    calculate();
    max_sum = findMax();
    printf("#%d %d\n", ii+1, max_sum);
  }

}
