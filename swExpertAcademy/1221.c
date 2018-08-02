#include<stdio.h>
#include<string.h>
char data[10000][3+1];
char number[10][3+1] = {
  "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN","EGT", "NIN"
};
int number_count[10+1];

int findIndex(char *num){
  int ii;
  for( ii = 0; ii < 10; ii++){
    if( strcmp(number[ii], num) == 0 )
      return ii;
  }
  return -1;
}

void calculate(int case_size){
  int ii;
  memset(number_count, 0x00, sizeof(number_count));
  for( ii = 0; ii < case_size; ii++){
    number_count[findIndex(data[ii])]++;
  }
}

void print(void){
  int ii, jj;
  for( ii = 0; ii < 10; ii++){
    for( jj = 0; jj < number_count[ii]; jj++)
      printf("%s ", number[ii]);
  }
}

int main(void){

  char temp[10];
  int TC;
  int ii, jj;
  int case_size;
  scanf("%d", &TC);
  getchar();

  for( ii = 1; ii <= TC; ii++){
    memset(data, 0x00, sizeof(data));

    scanf("%s %d", temp, &case_size);

    for( jj = 0; jj < case_size; jj++)
      scanf("%s", data[jj]);

    calculate(case_size);

    printf("#%d\n", ii);
    print();
  }
}
