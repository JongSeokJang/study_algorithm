#include<stdio.h>
#include<string.h>

#define FIELD_SIZE 100

int field[FIELD_SIZE+1][FIELD_SIZE+1];
// 1 : N ( go to bottom )
// 2 : S ( go to top )
// N : top
// S : bottom
void move(int field_size){
  int ii, jj,kk;

  for( ii = 0 ; ii < field_size; ii++){ //
    for( jj = 0 ; jj < field_size; jj++){
      for( kk = 0 ; kk < field_size; kk++){

        if( field[kk][ii] == 2 ){
          if( kk == 0 )
            field[kk][ii] = 0;
          else{
            if( field[kk-1][ii] == 0 ){
              field[kk-1][ii] = 2;
              field[kk][ii] = 0;
            }
          }
        }

        if( field[kk][ii] == 1 ){
          if( kk == field_size-1)
            field[kk][ii] = 0;
          else{
            if( field[kk+1][ii] == 0){
              field[kk+1][ii] = 1;
              field[kk][ii] = 0;
            }
          }
        }
      }
    }
  }
}
int calculate(int field_size){
  int ii, jj;
  int count = 0;
  for( ii = 0; ii< field_size; ii++){
    for( jj =0; jj < field_size; jj++){
      if( field[jj][ii] == 1 && field[jj+1][ii] == 2)
        count++;
    }
  }
  return count;
}

int main(void){
  int ii, jj, kk;
  int field_size;
  int result;

  for( ii = 1; ii <= 10; ii++){

    memset(field, 0x00, sizeof(field));
    scanf("%d", &field_size);

    for( jj = 0; jj < field_size; jj++){
      for(kk = 0; kk < field_size; kk++)
        scanf("%d", &field[jj][kk]);
    }
    move(field_size); 
    result =  calculate(field_size);
    printf("#%d %d\n", ii, result);
  }
}
