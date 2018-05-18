#include<stdio.h>

typedef struct _{
  int c0;
  int c1;
}fibo_cnt;

fibo_cnt cnt[100000];

void make_cnt(int N){
  int ii;

  for( ii = 0; ii <= N; ii++){
    if( ii == 0 ){
      cnt[ii].c0 = 1;
      cnt[ii].c1 = 0;
    }
    else if(ii == 1){
      cnt[ii].c0 = 0;
      cnt[ii].c1 = 1;
    }
    else{
      cnt[ii].c0 = cnt[ii-1].c0 + cnt[ii-2].c0;
      cnt[ii].c1 = cnt[ii-1].c1 + cnt[ii-2].c1;
    }
  }
}



int main(void){

  int T;
  int N;

  scanf("%d", &T);

  while(T--){

    scanf("%d", &N);
    make_cnt(N);
    printf("%d %d\n", cnt[N].c0, cnt[N].c1);
  }

}
