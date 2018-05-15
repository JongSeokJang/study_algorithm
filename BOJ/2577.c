#include<stdio.h>
#include<string.h>

int data_cnt[10];

void count_number(int number){

  int ii;
  int index;
  char str_num[1000000];
  sprintf(str_num, "%d", number);

  for( ii = 0; ii < (int)strlen(str_num); ii++){
    index = (int)(str_num[ii] - '0');
    data_cnt[ index ]++;
  }
}

int main(void){
  
  int ii;
  int num1, num2, num3;

  scanf("%d", &num1);
  scanf("%d", &num2);
  scanf("%d", &num3);

  count_number( num1 * num2 * num3);

  for( ii = 0; ii < 10; ii++){
    printf("%d\n", data_cnt[ii]);
  }

  return 0;

}
