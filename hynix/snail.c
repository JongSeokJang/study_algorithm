#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int field[100+1][100+1];

void snail(int size){
  int ii, jj, kk;
  int side;
  int count = 1;
  int c = size;

  ii = 0, jj =0, kk=0;

  side = 1;

  while(1){
    switch(side){
      case 1: // right
        for( kk = jj; kk < jj+size; kk++)
          field[ii][kk] = count++;

        side = 2;
        size--;
        ii++;
        jj = kk-1;
        break;
      case 2: // left
        for( kk = ii; kk < ii+size; kk++)
          field[kk][jj] = count++;

        side = 3;
        jj--;
        ii = kk-1;
        break;
      case 3:
        for( kk = jj; kk > jj-size; kk--)
          field[ii][kk] = count++;

        side = 4;
        ii--;
        jj = kk+1;

        size--;
        break;
      case 4:

        for( kk = ii; kk > ii-size; kk--)
          field[kk][jj] = count++;

        side = 1;
        jj++;
        ii = kk+1;
        break;
      default:
        break;
    }
    
    if( count == c*c){
      field[ii][jj] = count;
      break;
    }


  }


}


int main(void){
  int TC;
  int ii, jj, kk;
  int size;
  scanf("%d", &TC);


  for( ii = 1; ii <= TC; ii++){
    scanf("%d", &size);
    snail(size);
    printf("-----------[%d]--------\n", ii);
    for( jj = 0; jj < size; jj++){
      for( kk = 0; kk < size; kk++)
        printf("%3d", field[jj][kk]);
      printf("\n");
    }


  }
}
