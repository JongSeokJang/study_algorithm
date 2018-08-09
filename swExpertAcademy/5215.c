#include<stdio.h>
#include<string.h>

typedef struct _data{
  int point;
  int calorie;
}data;

data food[20];
int maxPoint = 0;

void calculate(int N, int L, int p, int k){

  if( k > L )
    return;

  if ( maxPoint < p)
    maxPoint = p;

  if( N == -1)
    return ;
  

  calculate(N-1, L, p+food[N].point, k+food[N].calorie );
  calculate(N-1, L, p, k );

}


int main(void){
  int ii, jj;
  int TC;
  int N, L;

  scanf("%d", &TC);
  for( ii = 1; ii <=TC; ii++){

    
    scanf("%d %d", &N, &L);
    memset(food, 0x00, sizeof(food));
    maxPoint = 0;

    for( jj = 0; jj < N; jj++)
      scanf("%d %d", &food[jj].point, &food[jj].calorie);
    
    calculate(N, L, 0, 0);
    printf("#%d %d\n", ii, maxPoint);

  }

}
