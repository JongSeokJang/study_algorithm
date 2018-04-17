#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char max[64];
int change_count;

void change_function(char *data, int depth){
  int ii, jj;
  char temp;
  char cpy_data[64];
  memset( cpy_data, 0x00, sizeof(cpy_data) );
  if( depth == change_count){
    if( atoi(max) < atoi(data) ){
      memset(max, 0x00, sizeof(max) );
      strcpy(max, data);
    }
  }
  else{
    for( ii = 0; ii < strlen(data); ii++){
      for (jj = ii+1; jj < strlen(data) ; jj++){
        strcpy(cpy_data, data);
        temp = cpy_data[ii];
        cpy_data[ii] = cpy_data[jj];
        cpy_data[jj] = temp;
        change_function(cpy_data, depth+1);
      }
    }
  }
}

int main(void){

  int result;
  int T;
  char data[64];
  scanf("%d", &T);

  while( T-- ) {

    memset(max, 0x00, sizeof(max) );
    scanf("%s %d", data, &change_count);
    change_function(data, 0);
    printf("%s\n", max);
  }
  
}
