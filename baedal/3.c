#include<stdio.h>
#include<string.h>
  
char field[10000][10000];

int main(void){
  // 1 : (x1,y1) ~ (x2,y2)
  // 2 : (x3,y3) ~ (x4,y4)
  // 3 : (x5,y5) ~ (x6,y6)

  //char field[10000][10000];

  int x1, x2, x3, x4, x5, x6;
  int y1, y2, y3, y4, y5, y6;

  int ii, jj;
  int total = 0;

  memset( field, 0x00, sizeof(field) );
  scanf("%d %d %d %d %d %d %d %d %d %d %d %d" ,&x1, &y1, &x2, &y2, &x3, &y3
                                              ,&x4, &y4, &x5, &y5, &x6, &y6);

  for( ii = x1; ii < x2; ii++){
    for( jj = y1; jj < y2; jj++){
      field[ii][jj] = 1;
      total++;
    }
  }

  for( ii = x3; ii < x4; ii++){
    for( jj = y3; jj < y4; jj++){
      if( field[ii][jj] == 1){
        field[ii][jj] = 0;
        total--;
      }
    }
  }
  
  for( ii = x5; ii < x6; ii++){
    for( jj = y5; jj < y6; jj++){
      if( field[ii][jj] == 1){
        field[ii][jj] = 0;
        total--;
      }

    }
  }
  printf("%d\n", total);

}
