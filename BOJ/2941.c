#include<stdio.h>
#include<string.h>

int solve(char *input){

  int ii;
  int len = strlen(input);
  int cnt = 0;;

  for( ii = 0; input[ii]; ii++){

    cnt++;
    switch( input[ii]){
      case 'c':

        if( input[ii+1] ){
          if( input[ii+1] =='=' || input[ii+1] == '-')
            ii++;
        }
        break;
      case 'd':

        if( input[ii+1] ){
          if( input[ii+1] == '-') 
            ii++;
          else if( input[ii+1] == 'z'){
            if( input[ii+2] && input[ii+2] == '=')
              ii+=2;
          }
        }

        break;
      case 'l':

        if( input[ii+1] ){
          if( input[ii+1] == 'j' )
            ii++;
        }
        break;

      case 'n':

        if( input[ii+1] ){
          if( input[ii+1] == 'j' )
            ii++;
        }
        break;

      case 's':

        if( input[ii+1] ){
          if( input[ii+1] == '=' )
            ii++;
        }
        break;

      case 'z':

        if( input[ii+1] ){
          if( input[ii+1] == '=' )
            ii++;
        }
        break;
      default:
        break;
    }

  }
  return cnt;

}



int main(void){
  
  char input[102];
  scanf("%s", input);
  printf("%d\n", solve(input) );

  return 0;

}
