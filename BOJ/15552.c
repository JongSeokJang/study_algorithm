#include<stdio.h>


int main(void){

  int TC;
  int num1, num2;

  scanf("%d", &TC);

  while(TC--){
   scanf("%d %d", &num1, &num2); 
    printf("%d\n",num1+num2);
  }

  return 0;

}
