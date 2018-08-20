#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printBit(int num){
  int bitData[12] = {0};
  int ii =0, jj;
  
  if( num != 0){

    while( num / 2 ){
      if( num % 2 == 0)
        bitData[ii++] = 0;
      else
        bitData[ii++] = 1;
      num /= 2;
    }
    bitData[ii] = 1;
  }
  for( ii = 12-1, jj= 0; ii >= 0; ii--, jj++){
    printf("%d", bitData[ii]);
    if( (jj+1) % 4 == 0)
      printf(" ");
  }
  printf("\n");

}

int main(void){
  int num = 0;
  char input[10];
  char *param1, *param2;
  while(1){
    fgets(input, sizeof(input), stdin);
    param1 = strtok(input, " \n");
    param2 = strtok(NULL, " \n");

    if( !strcmp(param1, "exit") ){
      break;
    }
    else if( !strcmp(param1, "set") ){
      num |= (1 << atoi(param2));
      printBit(num);
    }
    else if( !strcmp(param1, "reset") ){
      num &= ~(1 << atoi(param2));
      printBit(num);
    }
    else if( !strcmp(param1, "toggle") ){

      if( num & (1 << atoi(param2)) ) // This bit is already "1"
        num &= ~(1 <<atoi(param2));
      else
        num |= (1 <<atoi(param2));
      
      printBit(num);
    }
    else{
      printf("Input is worng: [%s %s]\n", param1, param2);
    }
  }



}
