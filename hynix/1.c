#include<stdio.h>
#include<string.h>
int oneCount;

void count(int num){

  int ii;
  char temp_char[10];

  if( num == 0)
    return;

  else{

    memset(temp_char, 0x00, sizeof(temp_char));
    sprintf(temp_char, "%d", num);
    printf("[%s]\n", temp_char);
    
    for( ii = 0; ii < strlen(temp_char); ii++){
      if (temp_char[ii] == '1')
        oneCount++;
    }
    
    count(num-1);
  }
  

}
int main(void){
  int num;
  oneCount = 0;

  scanf("%d", &num);
  count(num);
  printf("[%d]\n", oneCount);

}
