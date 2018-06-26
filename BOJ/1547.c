#include<stdio.h>

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(void){

  int cups[3] = {1,0,0};
  int T;
  int ii;
  int c1, c2;
  
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &c1, &c2);
    swap(&cups[c1-1], &cups[c2-1]);

  }
  for ( ii = 0 ; ii < 3; ii++){
    if( cups[ii] == 1)
      printf("%d\n", ii+1);
  }

}
