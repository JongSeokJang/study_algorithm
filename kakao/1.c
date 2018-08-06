#include<stdio.h>
int c1(int a){
  if( a == 1 )
    return 5000000;
  else if( a == 2 || a == 3 )
    return 3000000;
  else if( 4 <= a && a <= 6)
    return 2000000;
  else if ( 7 <= a && a <= 10)
    return 500000;
  else if ( 11 <= a && a <= 15)
    return 300000;
  else if( 16 <= a && a <= 21)
    return 100000;
  else {
    return 0;
  }
}
int c2(int b){
  if( b == 1){
    return 5120000;
  }
  else if( b >= 2 && b < 2+2)
    return 2560000;
  else if( b >= 4 && b < 4+4 )
    return 1280000;
  else if( b >= 8 && b < 8+8)
    return 640000;
  else if (b >= 16 && b< 16+16)
    return 320000;
  else {
    return 0;
  }
  
}

int main(void){
  int T;
  int a,b;

  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &a, &b);
    printf("\n%d\n", c1(a)+c2(b));
  }


}
