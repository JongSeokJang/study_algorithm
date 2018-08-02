#include<stdio.h>
int data[100];
int result[100];
int new[100];
int count = 0;

int main(void){

  int cmd_option;
  int cmd_size;
  int cmd_start;
  int cmd_data;

  int ii, jj, kk;
  int length_basic;
  int length_cmd;

  for( ii = 1; ii <=10; ii++){
    scanf("%d", &length_basic);
    count = length_basic;

    for( jj =0; jj < count; jj++)
      scanf("%d", &data[jj]);

    scanf("%d", &length_cmd);
    for( jj = 0; jj < length_cmd; jj++){
      scanf("%c %d %d", &cmd_option, &cmd_start, &cmd_size);
      for( kk = 0; kk < cmd_size; kk++){
        scanf("%d", &new[kk]);
      }

      for( kk = 0; kk< cmd_start; kk++){
        strcpy(result[kk], data[kk]);
      }
      for( kk = 0; kk< cmd_size; kk++){
        strcpy(result[kk+cmd_start], new[kk]);
      }
      for( kk = 0; kk< count-cmd_start; kk++){
        strcpy(result[kk+cmd_start+cmd_size], data[kk+cmd_start]);
      }

      for( kk = 0; kk < 10; kk++){
        strcpy(data[kk], result[kk]);
      }
    }
    
    printf("#%d ", ii);
    for( kk = 0; kk < 10; kk++){
      printf("%d ", data[kk]);
    }
    printf("\n");
    
  }

}
