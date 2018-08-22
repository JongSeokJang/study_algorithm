#include<stdio.h>
#define MAX_CASE 10
#define MAX_LENGTH 20
// Check string is palindrome
// If string is palindrome return -1;
// if string without one character return that index;
// else return -2;



int main(void){
  int ii, jj, kk;
  int sLength;
  int testCase;
  char input[MAX_LENGTH];
  char temp[MAX_LENGTH];
  int result[MAX_CASE];
  int flag1, flag2;
  int remove_index;

  scanf("%d", &testCase);

  // Todo Implement
  for( ii = 0; ii < testCase; ii++){

    scanf("%s", input);
   
    sLength = 0;
    while(input[sLength] ) sLength++;

    flag1 = 0;
    for( jj = 0; jj < (sLength)/2; jj++){

      if( input[jj] != input[(sLength-1) -jj]){
        flag1 = 1;
        break;
      }
    }

    if( flag1 == 0){
      result[ii] = -1;  
    }
    else{

      flag2 = 0;
      for(remove_index = 0; remove_index < sLength; remove_index++){

        flag1 = 0;
        for( jj = 0, kk = 0; jj < sLength; jj++){
          if( remove_index != jj )
            temp[kk++] = input[jj];
        }

        for( jj = 0; jj < (sLength-1)/2; jj++){

          if( temp[jj] != temp[(sLength-2) -jj]){
            flag1 = 1;
            break;
          }
        }
        if( flag1 == 0){
          result[ii] = remove_index;
          flag2 = 1;
          break;
        }
      }
      if( flag2 == 0)
        result[ii] = -2;
    }
  }

  for( ii = 0; ii < testCase; ii++)
    printf("[%d]\n", result[ii]);



}
