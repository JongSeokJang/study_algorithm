#include<stdio.h>
#include<string.h>


int main(void){
  int s1, s2;
  int color;
  //int color[20];
  int fn;
  char temp_1[100];

  char input[100];

  int temp;
  int ii;
  int n1, n2, n4;
  char n3[10];


  
  scanf("Canvas size: %d x %d", &s1, &s2);
  getchar();

  scanf("Background color: %x",&color);
  getchar();
  scanf("Number of frames: %d", &fn);
  getchar();

  printf("%d\n", s1);
  printf("%d\n", s2);
  printf("%d\n", color);
  printf("%d\n", fn);

  fgets(temp_1, 100, stdin);
 /* 
  scanf("%s\n", temp_1);
  //printf("%d\n", color);
  */

  for( ii = 1; ii <= fn; ii++){

    scanf("%d: %d %d",&temp, &n1, &n2);
    scanf("%s %d",input, &n4);

    if( strcmp(input,"yes") == 0){
      printf("%dx%d, %d, 1\n", n1,n2,n4);
    }
    else{
      printf("%dx%d, %d, 0\n", n1,n2,n4);
    }

  }

  return 0;
}
