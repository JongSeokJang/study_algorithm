#include<stdio.h>
#include<string.h>

typedef struct _{
  int x;
  int y;
  int who;
  int result;
}info;

void swap(info *t1, info *t2){

  info temp;
  temp = *t1;
  *t1 = *t2;
  *t2 = temp;

}

int main(void){

  int winner;
  int cnt;
  int ii,jj;
  int T, N;
  int x, y;
  int same_data;
  char name[10];
  info data[1000];
  info *temp;

  scanf("%d", &T);
  while(T--){

    scanf("%d", &N);
    for( ii = 0; ii < N; ii++){
      memset( name, 0x00, sizeof(name) );

      scanf("%d %d %s", &x, &y, name);
      data[ii].x = x;
      data[ii].y = y;
      if( strcmp( name, "Brown") == 0 )
        data[ii].who = 0;
      else
        data[ii].who = 1;
      data[ii].result = x*x + y*y;
      
    }

    for( ii = 0; ii < N; ii++){
      for( jj = ii+1; jj < N; jj++){

        if( data[ii].result > data[jj].result )
          swap(&data[ii], &data[jj]);
      }
    }

    cnt = 0;
    winner = data[0].who;

    for( ii = 0; ii < N; ii++){

      if( winner == data[ii].who ){
        cnt++;
      }
      else{
        if( ii > 0 && data[ii].result == data[ii-1].result ){

          same_data = data[ii].result;
          for( jj = ii-1; ; jj--){
            if( data[jj].result == same_data ){
              cnt--;
            }
            else{
              break;
            }
          }
        }
        break;
      }
    }

    if( winner == 0 ){
      printf("Brown %d\n", cnt);
    }
    else{
      printf("Cony %d\n", cnt);
    }
    

  }
  return 0;
}
