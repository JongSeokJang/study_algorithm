#include<stdio.h>
#include<string.h>

int CheckTime(char* input){
  
  int ii;
  int total = 0;
  for( ii = 0; input[ii]; ii++){

    if( input[ii] < 'D' )
      total += 3;
    else if( input[ii] < 'G')
      total += 4;

    else if( input[ii] < 'J')
      total += 5;

    else if( input[ii] < 'M')
      total += 6;

    else if( input[ii] < 'P')
      total += 7;

    else if( input[ii] < 'T')
      total += 8;

    else if( input[ii] < 'W')
      total += 9;

    else if( input[ii] <= 'Z')
      total += 10;

  }
  return total;

}

int main(void){
  char input[16];
  scanf("%s", input);
  printf("%d\n",CheckTime(input));
}



