#include<stdio.h>

int main(void){


  int T;
  int h, w, n;
  int f, r;
  scanf("%d", &T);

  while( T-- ){
    scanf("%d %d %d", &h, &w, &n);

    //5 5 10

    if( n%h == 0){
      f = h;
      r = n/h;

    }
    else {
      f = n %h;
      r = n/h+1;
    }
      

    printf("%d%02d\n",f, r);

  }

}
