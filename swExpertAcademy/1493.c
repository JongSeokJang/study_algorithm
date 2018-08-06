#include<stdio.h>

void c1(int v, int *x, int *y){
  int ii, jj, kk;
  int temp_value = 0;
  int sum;
  int count = 0;

  for( ii = 1;; ii++){
    sum = ii + 1;
    for (jj = 1; jj < sum; jj++){

      count++;
      kk = sum-jj;

      if( count == v){
        *x = jj;
        *y = kk;
        return;
      }
    }
  }
}
int c2(int x, int y){
  
  int ii, jj, kk;
  int count = 0;
  int sum;

  for( ii = 1;; ii++){
    sum = ii+1;
    for( jj = 1; jj < sum; jj++){
      count++;
      kk = sum-jj;

      if( x == jj && y == kk)
        return count;

    }
  }


}

int solve(int a, int b){
  int x1, y1;
  int x2, y2;
  c1(a, &x1, &y1);
  c1(b, &x2, &y2);

  return c2(x1+x2, y1+y2);
}

int main(void){
  int ii;
  int TC;
  int a, b;

  scanf("%d", &TC);
  for( ii = 1; ii <= TC; ii++){
    scanf("%d %d",&a, &b);
    printf("#%d %d\n", ii, solve(a, b));

  }
}
