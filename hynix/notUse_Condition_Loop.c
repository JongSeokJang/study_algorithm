#include<stdio.h>

#define CHAR_BIT 1

int cal(int x){
  int mask = x >> 31; // 0(0000000000000) or -1(1111111111111)
  return  (x+ (mask)) ^ mask;
}

int main(void){
  int v;           // we want to find the absolute value of v

  scanf("%d", &v);

  printf("[%d]\n", cal(v));
}
