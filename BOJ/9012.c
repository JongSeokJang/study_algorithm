#include<stdio.h>
#include<string.h>

#define MAX_SIZE 50

int main(void){
  int ii;
  int N;
  int top = 0;
  int flag = 0;
  char input[MAX_SIZE];
  scanf("%d", &N);

  while(N--){


    top = 0;
    flag = 0;
    memset(input, 0x00, MAX_SIZE);
    scanf("%s", input);

    for( ii = 0; input[ii]; ii++ ){

      if ( input[ii] == '('){
        top++; 

      }
      else{
        if( top == 0 ){
          flag = 1;
          break;
        }
        else{
          top--;
        }
      }
    }
    if( flag || top != 0 )
      printf("NO\n");
    else{
      printf("YES\n");
    }

  }
}
