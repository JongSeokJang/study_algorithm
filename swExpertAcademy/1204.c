#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int score_count[100+1];

int main(void){
  int ii;
  int T;
  int TC;
  int score;
  int max;
  int count = 1;

  scanf("%d", &T);

  while(T--){

    memset( score_count, 0x00, sizeof(score_count) );

    scanf("%d", &TC);
    for( ii = 0; ii < 1000; ii++){
      scanf("%d", &score);
      score_count[score]++;
    }
    max = 0;
    for( ii = 0; ii <= 100; ii++){
      if( score_count[max] <= score_count[ii] )
        max = ii;
    }
    printf("#%d %d\n", count++, max);

  }

}
