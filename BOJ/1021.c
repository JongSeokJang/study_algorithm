#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1024
int front = 0;
int end = -1;;

int queue[MAX_SIZE];

void rightRotate(){
  int ii;
  int element = queue[end-1];
  for( ii = end; ii > front; ii--)
    queue[ii] = queue[ii-1];
  queue[ii] = element;

}
void leftRotate(){
  int ii;
  int element = queue[front];
  for( ii = front; ii < end-1; ii++)
    queue[ii] = queue[ii+1];
  queue[ii] = element;

}
void popElement(){
  int ii;
  int element = queue[front];
  for( ii = front; ii < end; ii++)
    queue[ii] = queue[ii+1];
  end--;
}

int main(void){
  int element;
  int option[MAX_SIZE];
  int N, TC;
  int ii, jj;
  int position;
  int rotation_count = 0;

  scanf("%d %d", &N, &TC);
  front = 0;
  end = N;

  for( ii = 0; ii < TC; ii++)
    scanf("%d", &option[ii]);
  
  for( ii = front; ii < end; ii++)
    queue[ii] = ii+1;


  for( ii = 0; ii < TC; ii++){

    element = option[ii];
    position = 0;

    for( jj = front; jj < end; jj++){
      if( element == queue[jj] ) {
        break;
      }
      position++;
    } 

    if( position > end-position ){
      for( jj = 0; jj < end-position; jj++){
        rotation_count++;
        rightRotate();
      }
    }
    else{
      for( jj = 0; jj < position; jj++){
        rotation_count++;
        leftRotate();
      }
    }
    
    popElement();
  }
  printf("%d\n", rotation_count);


}
