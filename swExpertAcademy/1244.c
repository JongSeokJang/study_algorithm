#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int max;
int size;
char check[1000000][20];

void solve(char *data, int count){

  printf("[%s][%d]\n", data, count);
  int ii, jj;
  char temp;
  char local_data[6+1];


  if( atoi(data) >= max )
    max = atoi(data);

  if( check[atoi(data)][count] == '1')
    return;
  check[atoi(data)][count] = '1';

  if( count == 0)
    return;
  else{

    for( ii = 0; ii < size-1; ii++){
      for( jj = ii+1; jj < size; jj++){

        memset(local_data, 0x00, sizeof(local_data));
        strcpy(local_data, data);
        temp = local_data[ii];
        local_data[ii] = local_data[jj];
        local_data[jj] = temp;
        solve(local_data, count-1);
      }
    }
  }
}

int main(void){
  int TC;
  int ii;
  int number, count;
  char data[6+1];
  scanf("%d", &TC);

  for( ii = 1; ii <= TC; ii++){
    max = 0;
    memset(data, 0x00, sizeof(data));
    memset(check, 0x00, sizeof(check));

    scanf("%d %d", &number, &count);
    sprintf(data, "%d", number);
    size = strlen(data);
   
    solve(data ,count);
    printf("#%d %d\n", ii, max);
    

  }

}
