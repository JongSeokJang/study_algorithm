#include<stdio.h>
#include<string.h>

int checkPalindrome(char *word){
  int ii;
  int pFlag = 1;
  for( ii = 0; ii < strlen(word)/2; ii++ ){

    if( word[ii] == '?' || word[strlen(word)-1-ii] == '?'){

      //printf("hihi\n");

      continue;
    }

    if( word[ii] != word[strlen(word)-1-ii]){
      pFlag = 0;
      break;
    }
  }
  return pFlag;
}

int main(void){
  int TC;
  int ii;
  int result;
  char temp[20];

  scanf("%d", &TC);
  for( ii = 1; ii <= TC; ii++){
    memset(temp, 0x00, sizeof(temp));
    scanf("%s", temp);
  
    result = checkPalindrome(temp);
    if( result == 1)
      printf("#%d Exist\n", ii);
    else
      printf("#%d Not exist\n", ii);

  }
  


}
