#include<stdio.h>

int table[15][15];

void makeTable(){
  int ii, jj;
  int temp;
  for( ii = 0 ; ii < 15; ii++){

    if( ii == 0 ){
      for( jj = 0; jj < 15; jj++)
        table[ii][jj] = jj;
    }
    else{

      temp = 0;
      for( jj = 0; jj < 15; jj++){
        if( jj == 0 )
          table[ii][0] = table[ii-1][0];
        else{
          temp += table[ii-1][jj];
          table[ii][jj] = temp;
        }
      }
      
    }
  }
}


int main(void){

  int T;
  int k, n;
  scanf("%d", &T);

  makeTable();
  while(T--){
    scanf("%d", &k);
    scanf("%d", &n);

    printf("%d\n", table[k][n]);

  }


}
