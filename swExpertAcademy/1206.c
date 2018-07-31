#include<stdio.h>
#include<string.h>

int field[256][1024];
int main(void){

  int ii, jj, kk;
  int TC;
  int floor;
  int total = 0;

  for( ii = 1; ii <= 10; ii++){

    memset( field, 0x00, sizeof(field) );
    total = 0;
    scanf("%d", &TC);

    for( jj = 0; jj < TC; jj++){
      scanf("%d", &floor);

      for ( kk = 0; kk < floor; kk++){
        field[jj][kk] = 1;
      }

    }
/*
    for( jj = 2; jj < TC-2; jj++){
      for( kk = 0; kk < 1024; kk++){
        if( field[jj][kk] == 1 ){
          if( field[jj-1][kk] == 0 && field[jj-2][kk] == 0
              && field[jj+1][kk] == 0 && field[jj+2][kk] == 0 )
            total++;
        }
        else{
          break;
        }
      }
    }
*/

    printf("#%d %d\n", ii, total);

  }
}
