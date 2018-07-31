#include<stdio.h>

int main(void){
  int a, b;
  scanf("%d %d", &a, &b);

  if( a-b == 1 || b-a == 2) 
    printf("A\n");

  if( b-a == 1 || a-b == 2) 
    printf("B\n");


}
