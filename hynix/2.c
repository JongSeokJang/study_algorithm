#include<stdio.h>

int custom_strlen(char *str){
  int ii = 0;
  while( str[ii] != '\n' && str[ii] != '\0'){
    ii++;
  }

  return ii;
}
int custom_strcpy(char *to, char *from){

  int ii;
  for( ii = 0; ii < custom_strlen(from); ii++)
    to[ii] = from[ii];
  
  return 1;
}


int main(void){
  char str1[10] = "jongseok";
  char str2[10];
  custom_strcpy(str2, str1);

  printf("%s\n", str2);

}
