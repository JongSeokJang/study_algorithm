#include<stdio.h>
#include<string.h>

int hansu(int number){

  int   ii;
  int   before = 0, current = 0;
  int   str_len;
  char  str_num[10];
  memset( str_num, 0x00, sizeof(str_num) );

  sprintf(str_num,"%d", number);
  str_len = (int)strlen(str_num);

  
  if( str_len == 1){
    return 1;
  }
  else{
    for( ii = 0; ii < str_len; ii++){

      if( ii == 0 ){
        before = str_num[ii+1] - str_num[ii];
        current = before;
      }
      else{
        current = str_num[ii] - str_num[ii-1];
      }
      
      if( before != current){
        return -1;
      }
      
      before = current;
    }

    return 1;
  }


}
int main(void){

  int ii;
  int max_number;
  int count = 0;

  scanf("%d", &max_number);

  for( ii = 1; ii <= max_number; ii++){
    if(hansu(ii) == 1)
      count++;
  }
  printf("%d\n", count );

}
