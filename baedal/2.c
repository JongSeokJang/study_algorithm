#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

int main(void)
{

  int *flag;
  int len;
  int N;
  int section[MAX_SIZE][2];
  int lowest, highest;
  int start=0, check=0, cont=0, sec=0;

  scanf("%d",&N);

  for(int i=0; i<N; i++){
    scanf("%d %d",&section[i][0],&section[i][1]);

    if(i==0){
      lowest = section[i][0];
      highest = section[i][1];
    }
    else{
      if(section[i][0] < lowest)
        lowest = section[i][0];
      if(section[i][1] > highest)
        highest = section[i][1];
    }
  }

  len = highest - lowest + 1;
  flag = (int *)calloc(len, sizeof(int));

  for(int i=0; i<N; i++)
  {
      for(int j=section[i][0]; j<section[i][1]; j++)
      {
        int k = j - lowest;
        flag[k]++;
      }
  }

  for(int i=0; i<len-1; i++){

    if(!check){

      if(flag[i]%2 != 0){
        check = 1;
        printf("(-, %d)\n",i+lowest);
        start = i+1;
      }
    }
    else{

      if(flag[i]%2 == 0){
        if(!cont){
          start = i;
          cont = 1;
          if(!flag[i])
            sec = 1;
          else
            sec = 2;
        }
      }
      else{

        if(!cont)
          continue;
        else{
          if(sec == 1){
            if(!flag[i-1])
              printf("(%d, %d)\n", start+lowest, i+lowest);
            else
              printf("(%d, %d]\n", start+lowest, i+lowest);
          }
          else{
            if(!flag[i-1])
              printf("[%d, %d)\n", start+lowest, i+lowest);
            else
              printf("[%d, %d]\n", start+lowest, i+lowest);
          }
        }
        cont = 0;
        sec = 0;
      }
    }
  }
  printf("(%d, +)\n",len+lowest-1);

  return 0;
}

