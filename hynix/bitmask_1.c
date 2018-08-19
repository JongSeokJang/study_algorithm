#include<stdio.h>

void printBit(int num){
  int temp[20] = {0};
  int ii = 0, jj;


  if( num != 0){

    while( num / 2 ){
      if( num % 2 == 0)
        temp[ii++] = 0;
      else
        temp[ii++] = 1;
      num /= 2;
    }
    temp[ii] = 1;
  }

  for( jj = 19, ii = 0 ; jj >=0 ;jj--, ii++){
    printf("%d", temp[jj]);
    if( (ii+1) % 4 == 0){
      printf(" ");
    }
  }
  printf("\n");
}

int main(void){

  //int fullPizza = (1 << 20) -1;
  //
  // 1        : 0001 (1)
  // 1<<2     : 0100 (4)
  // (1<<2)-1 : 0011 (3)
  //
  int temp = (1<<20)-1;
  printf("[%d]\n", temp);
  printBit(temp);
  
  int p = 1;
  int toppings = 0; 
  toppings |= ( 1 << p);
  printf("[%d]\n", toppings);
  printBit(toppings);

  toppings &= ~( 1 << p);
  printf("[%d]\n", toppings);
  printBit(toppings);

  toppings ^= (1 << p);
  printf("[%d]\n", toppings);
  printBit(toppings);

  toppings ^= (1 << p);
  printf("[%d]\n", toppings);
  printBit(toppings);


}
