#include<stdio.h>
#include<string.h>
int count[10000+1];
int coin[100+1];
int n, k;

void solve(int m, int curVal){
  int ii;
  printf("-------m : [%d], curVal : [%d]-----\n", m, curVal);

  if( m-curVal < 0 )
    return;

  if( count[m-curVal] != 0){
    count[m] += count[m-curVal];
    printf("count : [%d], %d || [%d]: %d\n", m, count[m], m-curVal, count[m-curVal]);
    return;
  }
  
  if( m-curVal == 0 ){

    count[m]++;
    printf("count : [%d], %d || [%d]: %d\n", m, count[m], m-curVal, count[m-curVal]);
    return;
  }

  for( ii = 0 ; ii < n; ii++)
    solve(m-curVal, coin[ii]);
  
}

int main(void){
  int ii;
  scanf("%d %d", &n, &k);
  memset(count, 0x00, sizeof(count));
  for( ii = 0; ii < n; ii++)
    scanf("%d", &coin[ii]);

  for( ii = 0; ii < n; ii++){
    if( count[k - coin[ii]] != 0)
      count[k] += count[ii];
    else
      solve(k, coin[ii]);
  }

  for( ii = 0; ii < k; ii++)
    printf("[%d]:[%d]\n", ii, count[ii]);

}
