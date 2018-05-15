#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 200

int TC, CC;

void travel_circle(int *chager, int *spend, int *result){

  int ii;
  int index;
  int save_energy, spend_energy;
  for( index = 0; index < CC; index++){ 

    save_energy = spend_energy = 0;

    for( ii = 0 ; ii < CC; ii++){
      
      save_energy += chager[(index+ii)%CC];
      spend_energy += spend[(index+ii)%CC];

      if( spend_energy > save_energy ){
        result[index] = -1;
        break;
      }
      if( ii == CC -1)
        result[index] = 1;
    }
  }
}

int main(void){
  
  int ii;
  int charge_energy[MAX_SIZE];
  int spend_energy[MAX_SIZE];
  int result[MAX_SIZE];

  scanf("%d", &TC);

  while(TC--){

    memset(charge_energy, 0x00, sizeof(charge_energy));
    memset(spend_energy,  0x00, sizeof(spend_energy));
    memset(result, 0x00, sizeof(MAX_SIZE));
    
    scanf("%d", &CC);

    for( ii = 0; ii < CC; ii++)
      scanf("%d", &charge_energy[ii]);

    for( ii = 0; ii < CC; ii++)
      scanf("%d", &spend_energy[ii]);

    travel_circle(charge_energy, spend_energy, result);

    for( ii = 0 ; ii < CC; ii++){
      if( result[ii] == 1){
        printf("%d\n", ii);
        break;
      }
      if( ii == CC-1){
        printf("-1\n");
        break;
      }
    }
  }
  return 0;
}
