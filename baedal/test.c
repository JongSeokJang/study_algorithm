#include <stdio.h>

#define MAX_SIZE 1024

int queue[MAX_SIZE];

void push(int*, int);
int pop(int*);

int main() {
  int d, j, k;
	int n, m =0;
	int front, back;

	front = back = 0;

//	scanf("%d %d", &n, &m);
  scanf("%d %d %d %d", &n, &d, &j, &k);


  if( d == 1 ){
    for (int i = 1; i <= n; ++i) 
      push(&back, i);
  }
  else{
    push(&back, 1);
    for (int i = n; i > 1; --i) 
      push(&back, i);
  }

	for (int i = 1; front != back; ++i) {

    if( i == 1){
      m = k;
      for(int t = 0; t < m; t++)
        push(&back, pop(&front));
    }
    else{
      m = m+j;
      for(int t = 0; t < m-1; t++)
        push(&back, pop(&front));
    }

    if( front == back -1)
		  printf("%d\n", pop(&front) );
    else
      pop(&front);
	}
	return 0;
}

void push(int* back, int data) {
	queue[(*back)++ % MAX_SIZE] = data;
	return;
}

int pop(int* front) {
	return queue[(*front)++ % MAX_SIZE];
}
