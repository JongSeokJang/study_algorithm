#include<stdio.h>
#define MAX_COL 10
#define MAX_ROW 6

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int field[MAX_ROW+1][MAX_COL+1] = {
  {0,0,1,1,0,0,0,0,0,0},
  {1,1,0,0,0,0,1,1,1,1},
  {1,1,1,1,0,0,1,0,0,0},
  {0,0,0,0,0,1,1,0,0,1},
  {1,1,1,1,1,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0}
};
int visit[MAX_ROW][MAX_COL] = {0};
int max;
int sum;

void calculate(int x, int y){
  int ii;

  if( visit[x][y] == 1)
    return;

  visit[x][y] = 1;
  if( field[x][y] == 0)
    return;
  
  else{
    sum++;
    if( x == 0 ){
      calculate(x + dx[0], y +dy[0]);
      calculate(x + dx[1], y +dy[1]);
      calculate(x + dx[2], y +dy[2]);
    }
    else if( y == 0 ){
      calculate(x + dx[0], y +dy[0]);
      calculate(x + dx[1], y +dy[1]);
      calculate(x + dx[3], y +dy[3]);
    }
    else{
      for( ii = 0; ii < 4; ii++)
        calculate(x + dx[ii], y + dy[ii]);
    }
  }
}


int main(void){
  int ii, jj;
  for( ii = 0; ii < MAX_ROW; ii++){
    for ( jj = 0; jj < MAX_COL; jj++)
      printf("%d", field[ii][jj]);
    printf("\n");
  }

  max = 0;
  for( ii = 0; ii < MAX_ROW; ii++){
    for(jj = 0; jj < MAX_COL; jj++){
      sum = 0;
      calculate(ii, jj);
      if( max < sum)
        max = sum;
    }
  }
  printf("[%d]\n", max);
}
