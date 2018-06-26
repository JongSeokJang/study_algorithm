#include<stdio.h>
#include<string.h>

typedef struct _{
  char time[30];
  char flag;
  char task[30];
  int key;
}TASK;

int main(void){

  int ii, jj;
  int T;
  char cTime[30];
  char input[100];
  int output[11];
  char *ptr;
  TASK data[10000];

  scanf("%d|%s", &T, cTime);

  for( ii = 0; ii < T; ii++){
    memset( input, 0x00, sizeof(input) );
    scanf("%s", input);

    ptr = strtok(input, "|");

    jj = 0;
    while( ptr ){
      
      switch(jj){
        case 0:
          strcpy(data[ii].time, ptr);
          break;
        case 1:
          data[ii].flag = ptr[0];
          break;
        case 2:
          strcpy(data[ii].task, ptr);
          break;
        case 3:
          data[ii].key = ptr[0]-'0';
          break;
        default:
          break;
      }
      jj++;
      ptr = strtok(NULL, "|");
    }
  }

  memset(output, 0x00, sizeof(output));
  for( ii = 0; ii < T; ii++){
    
    if( strcmp(data[ii].time, cTime) == -1 ){

      if( data[ii].flag == 'I' )
        output[data[ii].key]++;

      if ( data[ii].flag == 'O'){
        output[data[ii].key]--;

      }
    }
  }

  for( ii = 0; ii < 10; ii++){
    printf("%d %d\n", ii, output[ii]);
  }

}

