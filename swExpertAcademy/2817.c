#include<stdio.h>
#include<string.h>
int setMember[20];
int setCount;

void calculate(int start, int end, int checkSum){

  if( checkSum == 0 ){
    setCount++;
    return;
  }
  if( checkSum < 0){
    return;
  }

  int ii;
  for( ii = start; ii <= end; ii++){
    calculate(ii+1, end, checkSum-setMember[ii]);

  }


}

int main(void){
  int ii, jj;
  int N, K;
  int TC;

  scanf("%d", &TC);
  for( ii = 1; ii <=TC; ii++){

    setCount = 0;
    scanf("%d %d", &N, &K);
    memset(setMember, 0x00, sizeof(setMember));

    for( jj = 0; jj < N; jj++)
      scanf("%d", &setMember[jj]);

    calculate(0, N-1, K);
    printf("#%d %d\n", ii, setCount);



  }

}
