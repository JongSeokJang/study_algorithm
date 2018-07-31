#include<stdio.h>

int facNum[1024];
void makeFac(){
  int ii;
  facNum[0] = 1;
  for( ii = 1; ii <= 1000; ii++){
    if( ii == 1)
      facNum[ii] = 1;
    else
      facNum[ii] = facNum[ii-1] * ii;
  }
}

int main(void){
  int a, b;
  int val ;
  scanf("%d %d", &a, &b);
  makeFac();
  val = (facNum[a] / (facNum[b]* facNum[a-b])) % 10007;

  printf("%d\n", val);


}
