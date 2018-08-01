#include<stdio.h>

int number;

int calculate(int count){
  if( count == 0)
    return 1;
  else
    return number * calculate(count-1);
}


int main(void){
  
  int ii;
  int count;
  int testcase;
  int result;

  for( ii = 1; ii <= 10; ii++){
    scanf("%d", &testcase);
    scanf("%d %d", &number, &count);
    result = calculate(count);

    printf("#%d %d\n", ii, result);
  }

}
