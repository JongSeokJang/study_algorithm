#include<stdio.h>
#include<string.h>

int field[100];
int max;
int min;

void findMaxMin(void){
  int ii;

  min = max = 0;
  for( ii = 0; ii < 100; ii++){
    if( field[min] >= field[ii] ) 
      min = ii;

    if( field[max] <= field[ii] )
      max = ii;
  }
}

void dump(void){
  findMaxMin();
  field[min]++;
  field[max]--;

}

void print(void){
  int ii,jj;
  for( ii = 0; ii < 100; ii++){
    printf("%3d ", field[ii]);
    for( jj = 0; jj < field[ii]; jj++){
      printf("|");
    }
    printf("\n");
  }
}

int main(void){

  int ii, jj;
  int dump_case;

  for( ii = 0; ii < 10; ii++){
    memset(field, 0x00, sizeof(field) );
    scanf("%d", &dump_case);

    for( jj = 0; jj < 100; jj++)
      scanf("%d", &field[jj]);
  
    while(dump_case--)
      dump();

    printf("\n");
    print();

    
    findMaxMin();
    printf("#%d %d\n", ii+1, field[max] - field[min]);
  }


}
