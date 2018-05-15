#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR 1000

int main(void){
  int TC;
  char temp;
  char str1[MAX_STR];
  char str2[MAX_STR];
  int str1_ptr, str2_ptr;
  int flag;
  int ii;
  

  scanf("%d", &TC);
  while(TC--){

    flag = 0;
    temp = 0;
    str1_ptr = str2_ptr = 0;
    memset(str1, 0x00, MAX_STR);
    memset(str2, 0x00, MAX_STR);

    scanf("%s %s", str1, str2);

    while(str1_ptr < strlen(str1) && str2_ptr < strlen(str2) ) {

      if(str1[str1_ptr] == '*'){
        temp = str1[str1_ptr+ 1];

        if( strlen(str2)-1 == str2_ptr){

          str1_ptr += 2;
        }
        else{

          for( ii = str2_ptr; temp == str2[ii]; ii++);
          
          str1_ptr += 2;
          str2_ptr += (ii-str2_ptr);
        }

      }
      else if(str1[str1_ptr] == '?'){
        temp = str1[str1_ptr-1];
        if(temp == '*'){
          if( str1_ptr == strlen(str1) -1){ // Ok

            for( ii = str2_ptr; ii < strlen(str2); ii++);
            str1_ptr ++;
            str2_ptr += (ii-str2_ptr);
          }
          else{ // there is next char

            temp = str1[str1_ptr+1];
            for( ii = str2_ptr; ii < strlen(str2); ii++){
              if( str2[str2_ptr] == temp )
                break;
            }
            str1_ptr += 2;
            str2_ptr += (ii-str2_ptr);

          }
        }
        else{
          if( temp == str2[str2_ptr]){
            str1_ptr++;
            str2_ptr++;
          }
          else{
            flag = 1;
            break;
          }

        }

      }
      else if( str1[str1_ptr] == str2[str2_ptr] ){
        str1_ptr++;
        str2_ptr++;
      }
      else{
        flag = 1;
        break;
      }
        
    }

    if(str1_ptr != (int)strlen(str1) || str2_ptr != (int)strlen(str2) ){

      printf("this is last [%d][%d]/[%d][%d]", str1_ptr, (int)strlen(str1), str2_ptr, (int)strlen(str2));
      flag = 1;
    }

    if( flag ){
      printf("X\n");
    }
    else{
      printf("O\n");
    }

    


  }

}
