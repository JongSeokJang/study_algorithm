#include<stdio.h>
#include<string.h>

int oneCount[100000+1];
int count;

void makeField(int num){

  printf("%d\n", num);
  if(num == 100001)
    return ;
  else{

    if( num < 10){
      if( num == 1){
        oneCount[num] = 1;
      }
      else {
        oneCount[num] = 0;
      }
    }
    else if( num < 100){

      oneCount[num] = oneCount[num%10];
      if( num / 10 == 1)
        oneCount[num]++;

    }
    else if( num < 1000){

      oneCount[num] = oneCount[num%100];
      if( num / 100 == 1)
        oneCount[num]++;

    }
    else if( num < 10000){
      oneCount[num] = oneCount[num%1000];
      if( num / 1000 == 1)
        oneCount[num]++;

    }
    else if( num < 100000){

      oneCount[num] = oneCount[num%10000];
      if( num / 10000 == 1)
        oneCount[num]++;

    }
    else{

      oneCount[num] = oneCount[num%100000];
      if( num / 100000 == 1)
        oneCount[num]++;
    }
  }
  count += oneCount[num];
  makeField(num+1);
}


int main(void){
  int num;
  count = 0;
  //scanf("%d", &num);
  memset(oneCount, 0x00, sizeof(oneCount));
  makeField(1);
  printf("[%d]\n", count);


}

