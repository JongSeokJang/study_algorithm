#include<stdio.h>
#include<string.h>

int number[8+1];

void change(void){
  int ii;

  int temp = number[0];
  for( ii = 1; ii < 8; ii++)
    number[ii-1] = number[ii];
  number[ii-1] = temp;
}

void solve(void){
  int jj;
  int cnt = 1;
  while( number[0]-cnt > 0){
    number[0] -= cnt;
    cnt++;
    if( cnt == 6)
      cnt = 1;
    change();


  }
  number[0] = 0;
  change();

}


int main(void){
  int ii, jj;
  int testNum;

  for( ii = 1; ii <= 10; ii++){
    memset(number, 0x00, sizeof(number));
    scanf("%d", &testNum);
    for( jj = 0; jj < 8; jj++)
      scanf("%d", &number[jj]);
   
    solve();
    printf("#%d ", ii);
    for( jj = 0; jj < 8; jj++)
      printf("%d ",number[jj]);
    printf("\n");

  }

}
