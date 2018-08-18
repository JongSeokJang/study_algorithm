#include<stdio.h>
#include<string.h>
int count[10000+1];
int coin[100+1];
int n, k;

void solve(int m, int curVal){
  int ii;
  printf("m : [%d], curVal : [%d]\n", m, curVal);
  if( m-curVal < 0 )
    return;

  if( m-curVal == 0 ){
    count[curVal]++;
    printf("(m-curVal == 0) curVal:[%d]  count[curVal]:[%d]\n", curVal, count[curVal]);
    return;
  }
    
  if( count[m-curVal] != 0){
    printf("(count[m-curVal] != 0)  m: [%d](%d) m-curVal:[%d](%d)\n", m,count[m], m-curVal, count[m-curVal]);
    return;
  }
  
  for( ii = 0 ; ii < n; ii++){
    solve(m-curVal, coin[ii]);
    if( m-curVal-coin[ii] >= 0)
      count[m-curVal] += count[m-curVal-coin[ii]];
  }

}

int solve_before(int n, int k){
  int ii;
  for( ii = 0; ii < n; ii++){
    if( count[k - coin[ii]] != 0)
      count[k] += count[ii];
    else
      solve(k, coin[ii]);
  }
  return coin[k-1];
  
}

int main(void){
  int ii;
  scanf("%d %d", &n, &k);
  memset(count, 0x00, sizeof(count));
  for( ii = 0; ii < n; ii++)
    scanf("%d", &coin[ii]);

  printf("%d\n",solve_before(n, k));
  for( ii = 0; ii < k; ii++)
    printf("[%d] : [%d]\n", ii, count[ii]);
  


}
