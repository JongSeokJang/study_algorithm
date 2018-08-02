#include<stdio.h>
#include<string.h>

int password[100];

int remove_password(int index, int length){

  int ii;

  for( ii = index; ii < length-2; ii++)
    password[ii] = password[ii+2];

  return length-2;
}

int solve(int length){

  int length_temp;
  int ii;
  int continue_flag = 1;

  while( continue_flag ){
    for( ii = 0; ii < length -1; ii++){
      if( password[ii] == password[ii+1]){
        length_temp = remove_password(ii, length);
        break;
      }
    }
    if( ii == length - 1)
      continue_flag = 0;

    length = length_temp;
  }
  return length;

}

int main(void){
  int ii, jj;
  int password_length;
  char password_temp[100+1];


  for( ii = 1; ii <= 10; ii++){
    memset(password_temp, 0x00, sizeof(password_temp));
    scanf("%d %s", &password_length, password_temp);

    for( jj = 0; jj < password_length; jj++)
      password[jj] = password_temp[jj]-'0';

    password_length = solve( password_length );

    printf("#%d ", ii);
    for( jj = 0; jj < password_length; jj++)
      printf("%d", password[jj]);
    printf("\n");
  }

}
