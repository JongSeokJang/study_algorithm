#include<stdio.h>

int preSucceed = 0;


int clickSucceed() {
    if (preSucceed == 0) {
        preSucceed = 1;
    } else {
        preSucceed = 0;
    }
    return preSucceed;
}


int main(void){

  int ii;
  int jj;
  int i = 0;
  int N = 100;
  int succeed = 0;

  int click[1000];
  for( ii = 1; ii <= N; ii++){
    click[ii] = 0;
  }

  int n_click = 0;

  while (n_click < 90) {
    i++;
    for ( jj = 1; jj <= N; jj++){
      if (click[jj] == 0) {
        succeed = clickSucceed();
        click[jj] = succeed;

        if (succeed == 1) {
          n_click++;
        }
      }
    }
  }
    printf("%d\n", n_click);
}
