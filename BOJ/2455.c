#include<stdio.h>

int main(void){
  int T = 4;
  int in, out, now = 0;
  int max = 0;
  while(T--){
    scanf("%d %d", &out, &in);
    now = now + in - out;
    if(now > max)
      max = now;
  }

  printf("%d\n", max);

  
}
