#include<stdio.h>
#include<string.h>

int score[100];

void sort(int size){
  int ii, jj;
  int temp;
  for( ii =0; ii < size-1; ii++){
    for( jj = ii+1; jj < size; jj++){
      if( score[ii] < score[jj]){
        temp = score[ii];
        score[ii] = score[jj];
        score[jj] = temp;
      }
    }
  }
}

int main(void){
  int TC;
  int N, K;
  int ii, jj;
  int sum = 0;;

  scanf("%d", &TC);
  for( ii = 1; ii <= TC; ii++){
    scanf("%d %d", &N, &K);
    memset(score, 0x00, sizeof(score));
    sum = 0;

    for( jj = 0; jj < N; jj++)
      scanf("%d", &score[jj]);
    
    sort(N);
    for( jj = 0; jj < K; jj++)
      sum += score[jj];
    
    printf("#%d %d\n", ii, sum);

  }
}
