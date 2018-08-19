#include<stdio.h>
#define MAX_N 500
#define MAX_M 500
int field[MAX_N+1][MAX_M+1];
int count;

void solve(int rows,int cols,int cy,int cx){

  printf("[%d][%d]\n", cx, cy);
  if( cx == cols-1 && cy == rows -1){
    printf("count up : [%d][%d]\n", cx, cy);
    count++;
    return;
  }

  if( cy == 0){
    if( cx == 0 ){ 
      if( cy != rows-1 ){
        if(field[cy][cx] > field[cy+1][cx])
          solve(rows, cols, cy+1, cx);
      }
      if( cx != cols-1 ){
        if(field[cy][cx] > field[cy][cx+1])
          solve(rows, cols, cy, cx+1);
      }
    }
    else{
      if( cy != rows-1 ){
        if(field[cy][cx] > field[cy+1][cy])
          solve(rows, cols, cy+1, cx);
      }
      if( cx != cols-1 ){
        if(field[cy][cx] > field[cy][cx+1])
          solve(rows, cols, cy, cx+1);
      }
      if( cx != 0 ){
        if(field[cy][cx] > field[cy][cx-1])
          solve(rows, cols, cy, cx-1);
      }
    }
  }
  else{
    if( cx == 0 ){
      // 3 case
      if( cy != 0){
        //printf("[%d][%d]:(%d)->[%d][%d]:(%d)\n", cx,cy,field[cx][cy], cx-1,cy,field[cx-1][cy]);
        if( field[cy][cx] > field[cy-1][cx]){
          solve(rows, cols, cy-1, cx);
        }
      }
      if( cx != cols-1 ){
        if( field[cy][cx] > field[cy][cx+1]){
          solve(rows, cols, cy, cx+1);
        }
      }
      if( cy != rows-1 ){
        if( field[cy][cx] > field[cy+1][cx])
          solve(rows, cols, cy+1, cx);
      }
    }
    else{
      // 4 case
      if( cx != 0 ){
        if( field[cy][cx] > field[cy][cx-1])
          solve(rows, cols, cy,cx-1);

      }
      if( cx != cols-1){
        if( field[cy][cx] > field[cy][cx+1])
          solve(rows, cols, cy, cx+1);

      }
      if( cy != 0 ){
        if( field[cy][cx] > field[cy-1][cx])
          solve(rows, cols, cy-1, cx);

      }
      if( cy != rows-1){
        if( field[cy][cx] > field[cy+1][cx])
          solve(rows, cols, cy+1,cx);
      }
    }
  }
}

int main(void){
  int m, n;
  int ii, jj;
  // m : rows, n : cols

  count = 0;
  scanf("%d %d", &m, &n);
  for( ii = 0; ii < m; ii++){
    for( jj = 0; jj < n; jj++)
      scanf("%d", &field[ii][jj]);
  }

  for( ii = 0 ; ii < m; ii++){
    for( jj = 0; jj < n ; jj++)
      printf("(%2d,%2d):[%d]", ii,jj,field[ii][jj]);
    printf("\n");
  }
  solve(m, n, 0, 0);
  printf("%d\n", count);


}
