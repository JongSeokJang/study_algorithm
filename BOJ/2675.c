#include<stdio.h>
#include<string.h>

#define MAX_SIZE 20

int main(void){

  int TC;
  int ii, jj;
  int input1;
  char input2[MAX_SIZE];
  char result[8 * MAX_SIZE];
  scanf("%d", &TC);

  while(TC--){
    memset( input2, 0x00, MAX_SIZE );
    memset( result, 0x00, MAX_SIZE * 8);

    scanf("%d %s", &input1, input2);
    for( ii = 0 ; ii < strlen(input2); ii++){

      for( jj = 0; jj < input1; jj++){
        result[ (ii*input1)+jj ] = input2[ii];
      }
    }

    printf("%s\n", result);
  }
  return 0;

}
