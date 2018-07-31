#include<stdio.h>
int count2  = 0;
int count3  = 0;
int count5  = 0;
int count7  = 0;
int count11 = 0;

void calcul(int num){

  count2  = 0;
  count3  = 0;
  count5  = 0;
  count7  = 0;
  count11 = 0;

  while (num % 2 == 0){
    count2++;
    num /= 2;
  }
  while (num % 3 == 0){
    count3++;
    num /= 3;
  }
  while (num % 5 == 0){
    count5++;
    num /= 5;
  }
  while (num % 7 == 0){
    count7++;
    num /= 7;
  }
  while (num % 11 == 0){
    count11++;
    num /= 11;
  }
}

int main(){
  int T;
  int ii;
  int num;

  scanf("%d", &T);
  for( ii = 0; ii < T; ii++){
    scanf("%d", &num);
    calcul(num);
    printf("#%d %d %d %d %d %d\n", ii+1, count2, count3, count5, count7, count11);
  }
  
}
