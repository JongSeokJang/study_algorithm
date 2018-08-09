#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 50
int field[MAX_SIZE][MAX_SIZE];

int calculate(int field_size){
  int ii, jj;
  int range = 0;
  int median = (field_size-1)/2;
  int sum = 0;
  
  for( ii = 0; ii < field_size;ii++){
  
    for( jj = median-range; jj <= median+range; jj++)
      sum += field[ii][jj];

    if( ii < median )
      range++;
    else
      range--;
  }
  return sum;

}

int main(void){
  int ii;
  int jj, kk;
  int TC;
  int profit;
  int field_size;
  char temp_row[MAX_SIZE];
  scanf("%d", &TC);
  for( ii = 1; ii <=TC; ii++){
    scanf("%d", &field_size);
    memset(field, 0x00, sizeof(field));
    memset(temp_row, 0x00, sizeof(temp_row));

    for( jj = 0; jj < field_size; jj++){
      scanf("%s", temp_row);

      for( kk = 0; kk < field_size ;kk++)
        field[jj][kk] = temp_row[kk]-'0';
      
    }
    
    printf("#%d %d\n", ii, calculate(field_size));
 
  }
}
