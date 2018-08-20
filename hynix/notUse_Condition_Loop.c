#include<stdio.h>

#define CHAR_BIT 1

int cal(int x){
  return ( x+ (x>>31)) ^ (x >> 31);
}

int main(void){
  int v;           // we want to find the absolute value of v

  scanf("%d", &v);

  printf("[%d]\n", cal(v));
}
