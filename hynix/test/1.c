#include<stdio.h>

// Find minimum sum of factor
// ex) 
// 7 = 1 * 7 => (1+7 = 8) 
// 16 = 1 * 16  => (1 + 16 = 17)
//    = 2 * 8   => (2 + 8 = 10)
//    = 4 * 4   => (4 + 4 = 8)
//
//
//

int solve( int data ){
  // Todo implement
  int min  = 99999;
  int ii, jj;

  for( ii = 1; ii <= data; ii++){
    for( jj = 1; jj <= data; jj++){

      if( ii * jj == data ){
        if( ii + jj < min ){
          min = ii + jj;
        }
      }
      if (ii * jj > data){
        break;
      }
    }
  }
  return min;
}

int main(void){ 
  int ii;
  int testData[8] = {2, 6, 16, 50,  102, 5046, 2032,10042 };
  int answer[8];

  for( ii = 0; ii < 8 ; ii++){
    answer[ii] = solve(testData[ii]);

    printf("(%6d)'s sum of factor  minimum : [%d]\n",testData[ii], answer[ii] );
  }

  





}
