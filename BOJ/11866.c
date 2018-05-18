#include<stdio.h>
#include<string.h>


int field[1000000];
int queue[1000];
int end = -1;
int size;

void add_field(int N){

  int ii;
  for( ii = 0; ii < N; ii++){

    if( field[ii]!= 0){
      field[size++] = field[ii];
    }
  }

}

void push_queue(int num){
  queue[++end] = num;
}

int main(void){

  int N, M;
  int ii, jj;
  int index;

  scanf("%d %d", &N, &M);
  for( ii =0; ii < N; ii++){
    field[ii] = ii+ 1;
  }

  index = -1;
  size = N;
  while( end != (N-1) ){

    index += M;
    if( index >= size ) {
      add_field(N);
      index -= M;
    }
    else{
      if( field[index] != 0 ){
        push_queue( field[index] );

        for( ii = 0; ii < N; ii++){
          if( field[ii] == field[index])
            field[ii] = 0;
        }
      }
    }
  }

  printf("<");
  for( ii = 0; queue[ii]; ii++){
    if( ii == 0)
      printf("%d", queue[ii]);
    else{
      printf(", %d", queue[ii]);
    }
  }
  printf(">\n");

}
