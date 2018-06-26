#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 10000

int section[MAX_SIZE][2];

int main(void){

  int T;
  int ii, jj;
  int s, e;
  int lowest, highest;
  int *field;
  int len;
  int check;
  int start, cont, sec;
  
  scanf("%d", &T);
  for( ii = 0; ii < T; ii++){
    scanf("%d %d", &s, &e);
    section[ii][0] = s;
    section[ii][1] = e;

    if( ii == 0 ){
      lowest  = s;
      highest = e;
    }
    else{
      if( lowest > s)
        lowest = s;
      if( highest < e)
        highest = e;
    }
  }

  len = highest - lowest + 1;
  field = (int*)malloc(sizeof(int)*len);
  memset(field, 0x00, sizeof(int) * len);

  for( ii = 0; ii < T; ii++){
    for( jj = section[ii][0]; jj < section[ii][1]; jj++){
      field[jj-lowest]++;
    }
  }

  check = 0;
  for( ii = 0; ii < len -1; ii++){

    if( check == 0){
      
      if( field[ii] %2 != 0 ){
        check = 1;
        printf("(-, %d)\n", ii + lowest);
        start = ii + 1;
      }
    }
    else{

      if( field[ii] %2 == 0 ){ // even
        if( cont == 0 ){
          start = ii;
          cont = 1;
          if( field[ii] == 0)
            sec = 1;
          else {
            sec = 2;
          }
        }
      }
      else{   // odd
        if( cont == 0 )
          continue;
        else{
          if( sec == 1 ){
            if( field[ii-1] == 0 )
              printf("(%d, %d)\n", start+lowest, ii+lowest);
            else
              printf("(%d, %d]\n", start+lowest, ii+lowest);
          }
          else{
            if( field[ii-1] == 0 )
              printf("[%d, %d)\n", start+lowest, ii+lowest);
            else
              printf("[%d, %d]\n", start+lowest, ii+lowest);
          }
        }
        cont = 0;
        sec = 0;
      }
    }
  }
  printf("(%d, +)\n", len+lowest-1);
  free(field);
}
