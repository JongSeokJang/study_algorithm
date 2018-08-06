#include<stdio.h>
#include<string.h>

void sort(int *member, int size){

  int ii, jj;
  int temp;
  for( ii = 0 ; ii <size -1; ii++){
    for( jj = ii; jj < size; jj++){

      if( member[ii] >= member[jj]){
        temp = member[ii];
        member[ii] = member[jj];
        member[jj] = temp;
      }
    }
  }
}

int solve(){

  int food[100+1];
  int member[100+1];
  int ii;
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  memset(member, 0x00, sizeof(member));
  memset(food, 0x00, sizeof(food));


  for( ii = 0; ii < N; ii++)
    scanf("%d", &member[ii]);

  sort(member, N);
  for( ii = 0; ii < N; ii++)
    food[member[ii]]--;

  for( ii = 1; ii <= 100; ii++){

    food[ii] = food[ii-1] + food[ii];
    if( ii % M == 0 )
      food[ii] = food[ii] + K;

    if( food[ii] < 0)
      return 0;
  }
  return 1;

}

int main(void){
  int TC;
  int ii;
  int result;

  
  scanf("%d", &TC);
  for( ii = 1; ii <=TC; ii++){

    result = solve();
    if( result == 1)
      printf("#%d Possible\n", ii);
    else
      printf("#%d Impossible\n", ii);
  }

}
